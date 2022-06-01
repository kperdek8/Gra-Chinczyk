#include "Gra.h"
#include <time.h>
#include <cstdlib>
#include <string>
#include <iostream>

void poczekaj(int liczbaMs)
{
    // Aktualny czas
    clock_t czas = clock();

    // Petla dopoki nie minie podany czas
    while (clock() < czas + liczbaMs * CLOCKS_PER_SEC/1000);
}

Gra::Gra()
{
    czyGraSkonczona = false;
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
}

Gra::~Gra()
{
    if(planszaWsk!=nullptr)
        delete planszaWsk;
}

std::string odmienKolor(Kolor kolor) //
{
    switch(kolor)
    {
        case Kolor::czerwony:
            return "czerwonego";
        case Kolor::niebieski:
            return "niebieskiego";
        case Kolor::zolty:
            return "zoltego";
        case Kolor::zielony:
            return "zielonego";
    }

    return "cos poszlo zle";
}

void Gra::petlaGry() //Petla gry
{
    while(czyGraSkonczona != true)
    {
        poczekaj(240);
        planszaWsk->wyswietlPlansze();
        planszaWsk->wyswietlKomunikat("Tura gracza "+odmienKolor(czyjaTura),false);

        int rzut = 0;

        switch(gracze[czyjaTura]->zdecyduj())
        {
            case (Decyzja::rzuc):
                rzut = rzucKoscia();
                planszaWsk->wyswietlKomunikat("Kliknij ENTER by przesunac pionek",true);
                przesunPionek(planszaWsk->zwrocPionek(czyjaTura,0),rzut,400);
                break;
            case (Decyzja::wystaw):
                //do implementacji pozniej
                break;
        }

        zaktualizujTure();
    }
}

int Gra::rzucKoscia()
{
    planszaWsk->wyswietlKomunikat("Wcisnij enter by rzucic koscia",true);

    srand(time(0));
    int rzut;
    for(int i = 0; i<10; i++)
    {
        rzut = rand()%5+1;
        planszaWsk->wyswietlKomunikat(("Rzucanie koscia: "+std::to_string(rzut)),false);
        poczekaj(400);
    }

    poczekaj(1000);

    return rzut;
}

void Gra::zaktualizujTure()
{
    ++czyjaTura;
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
