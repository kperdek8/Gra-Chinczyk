#include "Gra.h"
#include "ZbiorPol.h"
#include "SFMLSupport.h"

void poczekaj(int liczbaMs)
{
    // Start zegara
    sf::Clock zegar;

    // Petla dopoki nie minie podany czas
    while (zegar.getElapsedTime().asMilliseconds() < liczbaMs);
}

Gra::Gra()
{
    czyWyjscZGry = false;
    planszaWsk = nullptr;
    zresetujPlansze();
}

Gra::~Gra()
{
    if(planszaWsk!=nullptr)
        delete planszaWsk;
}

void Gra::rzucKoscia()
{
    if(czyRzuconoKoscia)
        return;

    czyRzuconoKoscia = true;

    int rzut;

    for(int i = 0; i<8; i++)
    {
        rzut = distribution(random_engine);
        planszaWsk->zaktualizujKosc(rzut);
        planszaWsk->wyswietlPlansze();
        poczekaj(DICE_ANIMATION_SPEED);
    }

    ostatniRzut = rzut;

    //Obsluga sytuacji gdzie gracz nie ma zadnych aktywnych pionkow

    if(licznikRzutow >= 3 && rzut < 6) //Rzucono trzy razy mniej niz 6, skonczyly sie proby
    {
        czyPodjetoDecyzje = true;
        zresetujLicznik();
    }
    else if(!czyMaAktywnegoPionka(czyjaTura) && rzut < 6) //Rzucono mniej niz szesc, daj kolejna probe
    {
        czyRzuconoKoscia = false;
        licznikRzutow++;
    }
    else //Gracz wyrzucil szesc i wprowadzi kolejny pionek lub ma juz aktywny pionek
    {
        zresetujLicznik();
    }
}

void Gra::petlaGry() //Petla gry
{
    planszaWsk->zmienNazweOkna(czyjaTura);

    while(czyGraSkonczona != true && !czyWyjscZGry)
    {
        planszaWsk->wyswietlPlansze();
        if (czyPodjetoDecyzje)  //Oczekiwanie na przekazanie prawidlowego ruchu przez plansze do innych funkcji
        {
            zaktualizujTure();
            czyRzuconoKoscia = false;
            czyRzuconoDrugiRaz = false;
            czyPodjetoDecyzje = false;
        }
    }


    while(czyGraSkonczona == true && !czyWyjscZGry)
    {
        planszaWsk->wyswietlResetGry(zwyciezca);
    }
}

void Gra::zaktualizujTure()
{
    ++czyjaTura;
    SFMLSupport::przesunKosc(czyjaTura);
    planszaWsk->zmienNazweOkna(czyjaTura);
}

void Gra::zresetujPlansze()
{
    czyjaTura = Kolor::niebieski;
    licznikRzutow = 1;
    czyPodjetoDecyzje = false;
    czyRzuconoKoscia = false;
    czyGraSkonczona = false;
    czyPionekJestPrzesuwany = false;

    if(planszaWsk!= nullptr)
    {
        delete planszaWsk;
    }
    Plansza* plansza = new Plansza(this);
    planszaWsk = plansza;
    petlaGry();
}

void Gra::przesunPionek(Pionek* pionek)
{
    if(!czyRzuconoKoscia || czyPodjetoDecyzje || !czyDozwolonyRuch(pionek))
        return;

    czyPionekJestPrzesuwany = true; //Ignoruj kolejne klikniecia na pionki dopoki nie zakonczy sie ruch
    czyPodjetoDecyzje = true;

    //ustawRzut(); //Do testowania

    int liczbaPol = ostatniRzut;

    if(!pionek->czyAktywny())
    {
        //Zdejmij pionek z schowka i ustaw jako aktywny
        pionek->aktywuj();
        pionek->gdzieStoje()->zdejmijPionek();

        //Zbij pionek jezeli znajduje sie jakis na polu startowym
        if(planszaWsk->zwrocPoleStartowe(czyjaTura)->zwrocPionek() != nullptr)
            zbijPionek(planszaWsk->zwrocPoleStartowe(czyjaTura)->zwrocPionek());

        //Postaw pionek na polu startowym
        pionek->postawPionek(planszaWsk->zwrocPoleStartowe(czyjaTura));
        planszaWsk->zwrocPoleStartowe(czyjaTura)->postawPionek(pionek);
    }
    else
    {
        Pole* aktualnePolne = pionek->gdzieStoje();
        Pionek* przechowanyPionek = nullptr;

        if(ostatniRzut == 6 && !czyRzuconoDrugiRaz) //Daj graczowi drugi rzut
        {
            czyRzuconoKoscia = false;
            czyPodjetoDecyzje = false;
            czyRzuconoDrugiRaz = true;
        }

        while(liczbaPol > 0)
        {
            aktualnePolne->zdejmijPionek();

            if(przechowanyPionek != nullptr)
            {
                aktualnePolne->postawPionek(przechowanyPionek); //Postaw przechowany pionek z powrotem
                przechowanyPionek = nullptr;
            }

            if(czyZrobilOkrazenie(pionek))
            {
                wprowadzDoDomku(pionek);
                if(przechowanyPionek != nullptr)
                {
                    aktualnePolne->postawPionek(przechowanyPionek); //Postaw przechowany pionek z powrotem
                    przechowanyPionek = nullptr;
                }
                break;
            }
            else
            {
                if(aktualnePolne->nastepnePole()->zwrocPionek() != nullptr && liczbaPol > 1)
                    przechowanyPionek = aktualnePolne->nastepnePole()->zwrocPionek(); //Przechowaj pionek zeby go postawic ponownie, kiedy ruszajacy sie pionek opusci pole

                if(liczbaPol == 1 && aktualnePolne->nastepnePole()->zwrocPionek() != nullptr )
                    zbijPionek(aktualnePolne->nastepnePole()->zwrocPionek());

                aktualnePolne->nastepnePole()->postawPionek(pionek);
                aktualnePolne = aktualnePolne->nastepnePole();

                pionek->postawPionek(aktualnePolne);
                liczbaPol--;
                poczekaj(MOVE_ANIMATION_SPEED);
                planszaWsk->wyswietlPlansze();
            }
        }
    }
    czyPionekJestPrzesuwany = false;
}

bool Gra::czyDozwolonyRuch(Pionek* pionek)
{
    if(czyPionekJestPrzesuwany) //Nie sprawdzaj jezeli inny pionek jest aktualnie przesuwany
    {
        return false;
    }
    else if(!czyRzuconoKoscia) //Nie sprawdzaj dopoki nie rzucono koscia
    {
        return false;
    }
    else if(pionek->zwrocKolor() != czyjaTura)
    {
        return false;
    }
    else if(!pionek->czyAktywny()) //Pionek w schowku lub domku
    {
        //Nie sprawdzaj pionkow ktore znajduja sie w domku
        if(planszaWsk->zwrocDomek(pionek->zwrocKolor()).czyZnajdujeSie(pionek))
            return false;

        if(planszaWsk->zwrocPoleStartowe(czyjaTura)->zwrocPionek() != nullptr) //Pole startowe nie jest puste
            if(ostatniRzut == 6 && (planszaWsk->zwrocPoleStartowe(czyjaTura)->zwrocPionek()->zwrocKolor() != czyjaTura)) //Rzucono szesc i na polu startowym nie znajduje sie pionek tego samego koloru
                return true;
            else    //Na polu startowym stoi pionek tego samego koloru
                return false;
        else if(ostatniRzut == 6) //Pole startowe jest puste i wyrzucono 6
            return true;
        else    //Pole startowe jest puste ale nie wyrzucono 6
            return false;
    }
    else //Pionek na planszy
    {
        Pole* docelowePole = pionek->gdzieStoje();
        for(int i = 0; i<ostatniRzut; i++)
            docelowePole = docelowePole->nastepnePole();

        if(!(docelowePole->zwrocPionek() == nullptr))   //Docelowe pole jest zajete
        {
            if(docelowePole->zwrocPionek()->zwrocKolor() == czyjaTura)  //Na docelowym polu jest inny pionek tego samego koloru
                return false;
            else    //Na docelowym polu jest pionek innego koloru
                return true;
        }
        else    //Docelowe pole jest puste
            return true;
    }
}

bool Gra::czyZrobilOkrazenie(Pionek* pionek)
{
    if(pionek->gdzieStoje() == planszaWsk->zwrocPoleStartowe(pionek->zwrocKolor())->poprzedniePole())
        return true;
    return false;
}

bool Gra::czyMaAktywnegoPionka(Kolor kolorGracza)
{
    for(size_t i = 0; i<4; i++)
    {
        if(planszaWsk->zwrocPionek(kolorGracza,i)->czyAktywny())
            return true;
    }
    return false;
}

void Gra::wprowadzDoDomku(Pionek* pionek)
{
    planszaWsk->zwrocDomek(pionek->zwrocKolor()).wstaw(pionek);
    czyGraSieSkonczyla();
}

void Gra::zbijPionek(Pionek* pionek)
{
    planszaWsk->zwrocSchowek(pionek->zwrocKolor()).wstaw(pionek);
}

void Gra::czyGraSieSkonczyla()
{
    if(planszaWsk->zwrocDomek(czyjaTura).czyPelne())
    {
        czyGraSkonczona = true;
        zwyciezca = czyjaTura;
    }
}

void Gra::zresetujLicznik()
{
    licznikRzutow = 1;
}

void Gra::ustawRzut()
{
    int input;

    std::cout<<"Wprowadz nowy rzut"<<std::endl;

    while(input<1 || input > 99)
        std::cin>>input;

    ostatniRzut = input;
}
