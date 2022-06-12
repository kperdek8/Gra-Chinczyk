#include "Gra.h"
#include <time.h>
#include <cstdlib>

void poczekaj(int liczbaMs)
{
    // Start zegara
    sf::Clock zegar;

    // Petla dopoki nie minie podany czas
    while (zegar.getElapsedTime().asMilliseconds() < liczbaMs);
}

Gra::Gra()
{
    czyPodjetoDecyzje = false;
    czyRzuconoKoscia = false;
    czyGraSkonczona = false;
    czyPionekJestPrzesuwany = false;
    planszaWsk = nullptr;

    Gracz* gracz = new Gracz(false,Kolor::niebieski);
    gracze.push_back(gracz);
    gracz = new Gracz(false,Kolor::czerwony);
    gracze.push_back(gracz);
    gracz = new Gracz(false,Kolor::zolty);
    gracze.push_back(gracz);
    gracz = new Gracz(false,Kolor::niebieski);
    gracze.push_back(gracz);

    czyjaTura = Kolor::niebieski;

    zresetujPlansze();
    petlaGry();
}

Gra::~Gra()
{
    if(planszaWsk!=nullptr)
        delete planszaWsk;
}

void Gra::petlaGry() //Petla gry
{

    while(czyGraSkonczona != true)
    {
        planszaWsk->wyswietlPlansze();

        if (czyPodjetoDecyzje)
        {
            zaktualizujTure();
            czyRzuconoKoscia = false;
            czyPodjetoDecyzje = false;
        }
    }
}

void Gra::rzucKoscia()
{
    if(czyRzuconoKoscia)
        return;

    czyRzuconoKoscia = true;

    srand(time(0));
    int rzut;

    for(int i = 0; i<12; i++)
    {
        rzut = rand()%6+1;
        planszaWsk->zaktualizujKosc(rzut);
        planszaWsk->wyswietlPlansze();
        poczekaj(DICE_ANIMATION_SPEED);
    }

    ostatniRzut = rzut;
}

void Gra::zaktualizujTure()
{
    ++czyjaTura;
}

void Gra::zresetujPlansze()
{
    if(planszaWsk!= nullptr)
    {
        delete planszaWsk;
    }
    Plansza* plansza = new Plansza(this);
    planszaWsk = plansza;
}

void Gra::przesunPionek(Pionek* pionek)
{
    if(!czyRzuconoKoscia || czyPodjetoDecyzje || !czyDozwolonyRuch(pionek))
        return;

    czyPionekJestPrzesuwany = true;
    czyPodjetoDecyzje = true;

    int liczbaPol = ostatniRzut;

    if(!pionek->czyWystawiony())
    {
        pionek->wystawPionek();
        pionek->gdzieStoje()->zdejmijPionek();
        pionek->postawPionek(planszaWsk->zwrocPoleStartowe(czyjaTura));
        planszaWsk->zwrocPoleStartowe(czyjaTura)->postawPionek(pionek);
        planszaWsk->wyswietlPlansze();
    }
    else
    {
        Pole* aktualnePolne = pionek->gdzieStoje();
        while(liczbaPol > 0)
        {
            aktualnePolne->nastepnePole()->postawPionek(pionek);
            aktualnePolne->zdejmijPionek();

            aktualnePolne = aktualnePolne->nastepnePole();

            pionek->postawPionek(aktualnePolne);
            liczbaPol--;
            poczekaj(MOVE_ANIMATION_SPEED);
            planszaWsk->wyswietlPlansze();
        }
    }
    czyPionekJestPrzesuwany = false;
}

bool Gra::czyDozwolonyRuch(Pionek* pionek)
{
    if(czyPionekJestPrzesuwany)
    {
        return false;
    }
    else if(!czyRzuconoKoscia)
    {
        return false;
    }
    else if(pionek->zwrocKolor() != czyjaTura)
    {
        return false;
    }
    else if(!pionek->czyWystawiony()) //Pionek w schowku
    {
        if(planszaWsk->zwrocPoleStartowe(czyjaTura)->zwrocPionek() != nullptr) //Pole startowe nie jest puste
            if(ostatniRzut == 6 && (planszaWsk->zwrocPoleStartowe(czyjaTura)->zwrocPionek()->zwrocKolor() != czyjaTura)) //Rzucono szesc i na polu startowym nie znajduje sie pionek tego samego koloru
                return true;
            else    //Na polu startowym stoi pionek innego koloru
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
