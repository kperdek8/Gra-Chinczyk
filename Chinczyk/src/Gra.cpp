#include "Gra.h"
#include <time.h>
#include <cstdlib>
#include <string>

void poczekaj(int liczbaMs)
{
    // Aktualny czas
    clock_t czas = clock();

    // Petla dopoki nie minie podany czas
    while (clock() < czas + liczbaMs);
}

Gra::Gra()
{
    czyGraSkonczona = false;
    planszaWsk = nullptr;

    Gracz* gracz = new Gracz(false,niebieski);
    gracze.push_back(gracz);
    gracz = new Gracz(false,czerwony);
    gracze.push_back(gracz);
    gracz = new Gracz(false,zolty);
    gracze.push_back(gracz);
    gracz = new Gracz(false,niebieski);
    gracze.push_back(gracz);

}

Gra::~Gra()
{
    if(planszaWsk!=nullptr)
        delete planszaWsk;
}

void Gra::zacznijGre() //Petla gry
{
    while(czyGraSkonczona != true)
    {
        poczekaj(240);
        planszaWsk->wyswietlPlansze();

    }
}

int Gra::rzucKoscia()
{
    planszaWsk->wyswietlKomunikat("Wcisnij enter by rzucic koscia");

    srand(time(0));
    int rzut;
    for(int i = 0; i<10; i++)
    {
        rzut = rand()%5+1;
        planszaWsk->wyswietlKomunikat(("Rzucanie koscia: "+std::to_string(rzut)),false);
        poczekaj(400);
    }
    return rzut;
}

void Gra::zaktualizujTure()
{

}

void Gra::zresetujPlansze()
{
    if(planszaWsk!=nullptr)
    {
        delete planszaWsk;
    }
    Plansza* plansza = new Plansza;
    planszaWsk = plansza;
}

void Gra::przesunPionek(Pionek* pionek, int liczbaPol, int szybkoscAnimacji) //do przeniesienia do klasy Gra pozniej, dodac test czy pionek wykonal okrazenie
{
    Pole* aktualnePolne = pionek->gdzieStoje();

    while(liczbaPol > 0)
    {
        aktualnePolne->nastepnePole()->postawPionek(pionek);
        aktualnePolne->zdejmijPionek();

        aktualnePolne = aktualnePolne->nastepnePole();

        pionek->postawPionek(aktualnePolne);

        planszaWsk->wyswietlPlansze();
        poczekaj(szybkoscAnimacji);
        liczbaPol--;
    }
}
