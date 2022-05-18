#include "Plansza.h"
#include <string>
#include <iostream>
/*

Uklad planszy 11x11 wzorowany na obrazku Plansza.png, ktory znajduje sie w folderze projektu

rr  ##b  bb
rr  #b#  bb
    #b#
    #b#
r####b#####
#rrrr gggg#
#####y####g
    #y#
    #y#
yy  #y#  gg
yy  y##  gg
*/


Plansza::Plansza()
{
    polaStartowe.resize(4);
    schowki.resize(4);

    Pole* pierwszyInit = nullptr; //Wskaznik sluzacy do polaczenia na koncu inicjalizacji pierwszego i ostatniego pola
    Pole* pole = nullptr; //Wskaznik ktoremu beda przypisywane inicjalizowane pola, ktore nastepnie trafia do wektora.

    for(int i=0; i<=1; i++) //Schowek czerwonego
    {
        for(int k=0; k<=1; k++)
        {
            pole = new Pole(i,k,czerwony);
            pola.push_back(pole);
            schowki.at(czerwony).push_back(pole);
        }
    }

    for(int i=9; i<=10; i++) //Schowek niebieskiego
    {
        for(int k=0; k<=1; k++)
        {
            pole = new Pole(i,k,niebieski);
            pola.push_back(pole);
            schowki.at(niebieski).push_back(pole);
        }
    }

    for(int i=0; i<=1; i++) //Schowek zoltego
    {
        for(int k=9; k<=10; k++)
        {
            pole = new Pole(i,k,zolty);
            pola.push_back(pole);
            schowki.at(zolty).push_back(pole);
        }
    }

    for(int i=9; i<=10; i++) //Schowek zielonego
    {
        for(int k=9; k<=10; k++)
        {
            pole = new Pole(i,k,zielony);
            pola.push_back(pole);
            schowki.at(zielony).push_back(pole);
        }
    }

    for(int i=1; i<=4; i++) //Domek niebieskiego
    {
        pole = new Pole(5,i,niebieski);
        pola.push_back(pole);
    }

    for(int i=6; i<=9; i++) //Domek zoltego
    {
        pole = new Pole(5,i,zolty);
        pola.push_back(pole);
    }

    for(int i=1; i<=4; i++) //Domek czerwonego
    {
        pole = new Pole(i,5,czerwony);
        pola.push_back(pole);
    }

    for(int i=6; i<=9; i++) //Domek zielonego
    {
        pole = new Pole(i,5,zielony);
        pola.push_back(pole);
    }

    //Dalej nastepuje inicjalizacja reszty pól (których nie da sie pogrupowac w schludny sposob)

    Pole* poprzedInit = nullptr;

    for(int i = 0; i<=4; i++) // kreska (6,0) -> (6,4)
    {
        if(i == 0)
        {
            pole = new Pole(6,i,niebieski,poprzedInit); //Pole startowe niebieskiego
            polaStartowe.at(niebieski) = pole;
            pierwszyInit = pole;
        }
        else
            pole = new Pole(6,i,brak,poprzedInit);

        pola.push_back(pole);

        if(poprzedInit != nullptr)
            poprzedInit->wskKolejny = pole;

        poprzedInit = pole;
    }

    for(int i = 7; i<=10; i++) // kreska (7,4) -> (10,4)
    {
        pole = new Pole(i,4,brak,poprzedInit);
        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    pole = new Pole(10,5,brak,poprzedInit); // pole (10,5)
    pola.push_back(pole);
    poprzedInit->wskKolejny = pole;
    poprzedInit = pole;

    for(int i = 10; i>=6; i--) // kreska (10,6) -> (6,6)
    {

        if(i == 10)
        {
            pole = new Pole(i,6,zielony,poprzedInit); //Pole startowe zielonego
            polaStartowe.at(zielony) = pole;
        }
        else
            pole = new Pole(i,6,brak,poprzedInit);

        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    for(int i = 7; i<=10; i++) // kreska (6,7) -> (6,10)
    {
        pole = new Pole(6,i,brak,poprzedInit);
        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    pole = new Pole(5,10,brak,poprzedInit); // pole (5,10)
    pola.push_back(pole);
    poprzedInit->wskKolejny = pole;
    poprzedInit = pole;

    for(int i = 10; i>=6; i--) // kreska (4,10) -> (4,6)
    {
        if(i == 10)
        {
            pole = new Pole(4,i,zolty,poprzedInit); //Pole startowe zoltego
            polaStartowe.at(zolty) = pole;
        }
        else
            pole = new Pole(4,i,brak,poprzedInit);

        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    for(int i = 3; i>=0; i--) // kreska (3,6) -> (0,6)
    {
        pole = new Pole(i,6,brak,poprzedInit);

        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    pole = new Pole(0,5,brak,poprzedInit); // pole (0,5)
    pola.push_back(pole);
    poprzedInit->wskKolejny = pole;
    poprzedInit = pole;

    for(int i = 0; i<=4; i++) // kreska (0,4) -> (4,4)
    {
        if(i == 0)
        {
            pole = new Pole(i,4,czerwony,poprzedInit); //Pole startowe czerwonego
            polaStartowe.at(czerwony) = pole;
        }
        else
            pole = new Pole(i,4,brak,poprzedInit);

        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    for(int i = 3; i>=0; i--) // kreska (4,3) -> (4,0)
    {
        pole = new Pole(4,i,brak,poprzedInit);

        pola.push_back(pole);

        poprzedInit->wskKolejny = pole;
        poprzedInit = pole;
    }

    pole = new Pole(5,0,brak,poprzedInit,pierwszyInit); // pole (5,0)
    pola.push_back(pole);
    poprzedInit->wskKolejny = pole;
    pierwszyInit->wskPoprzedni = pole;
}

Plansza::~Plansza()
{
    //dtor
}

void Plansza::wyswietlPlansze()
{
    std::vector<std::string> planszaStr;

    for(int i = 0; i<11; i++)
    {
        std::string pustaLinia = "           ";
        planszaStr.push_back(pustaLinia);
    }

    unsigned int i = 0;
    while(pola.begin()+i != pola.end())
    {
        switch(pola[i]->kolorPola)
        {
            case brak:
            planszaStr[pola[i]->y][pola[i]->x] = '#';
            break;

            case niebieski:
            planszaStr[pola[i]->y][pola[i]->x] = 'b';
            break;

            case czerwony:
            planszaStr[pola[i]->y][pola[i]->x] = 'r';
            break;

            case zolty:
            planszaStr[pola[i]->y][pola[i]->x] = 'y';
            break;

            case zielony:
            planszaStr[pola[i]->y][pola[i]->x] = 'g';
            break;
        }
        i++;
    }

    for(int i = 0; i < planszaStr.size(); i++)
    {
        std::cout<<planszaStr[i]<<std::endl;
    }

}
