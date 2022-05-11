#include "Plansza.h"
#include <string>
#include <iostream>
/* Uk³ad planszy 11x11


rr  ###  bb
rr  #b#  bb
    #b#
    #b#
#####b#####
#rrrr gggg#
#####y#####
    #y#
    #y#
yy  #y#  gg
yy  ###  gg
*/


Plansza::Plansza()
{
    for(int i=0; i<=1; i++) //Schowek czerwonego
    {
        for(int k=0; k<=1; k++)
        {
            Pole* pole = new Pole(i,k,czerwony);
            pola.push_back(pole);
        }
    }

    for(int i=9; i<=10; i++) //Schowek niebieskiego
    {
        for(int k=0; k<=1; k++)
        {
            Pole* pole = new Pole(i,k,niebieski);
            pola.push_back(pole);
        }
    }

    for(int i=0; i<=1; i++) //Schowek zoltego
    {
        for(int k=9; k<=10; k++)
        {
            Pole* pole = new Pole(i,k,zolty);
            pola.push_back(pole);
        }
    }

    for(int i=9; i<=10; i++) //Schowek zielonego
    {
        for(int k=9; k<=10; k++)
        {
            Pole* pole = new Pole(i,k,zielony);
            pola.push_back(pole);
        }
    }

    for(int i=1; i<=4; i++) //Domek niebieskiego
    {
        Pole* pole = new Pole(5,i,niebieski);
        pola.push_back(pole);
    }

    for(int i=6; i<=9; i++) //Domek zoltego
    {
        Pole* pole = new Pole(5,i,zolty);
        pola.push_back(pole);
    }

    for(int i=1; i<=4; i++) //Domek czerwonego
    {
        Pole* pole = new Pole(i,5,czerwony);
        pola.push_back(pole);
    }

    for(int i=6; i<=9; i++) //Domek zielonego
    {
        Pole* pole = new Pole(i,5,zielony);
        pola.push_back(pole);
    }

    //Dalej nastepuje inicjalizacja reszty pól (których nie da siê pogrupowaæ w schludny sposób)

    Pole* poprzedInit = nullptr;

    for(int i = 0; i<=4; i++) // kreska (6,0) -> (6,4)
    {
        Pole* pole = nullptr;
        if(i == 0)
            pole = new Pole(6,i,niebieski);
        else
            pole = new Pole(6,i,brak,poprzedInit);

        pola.push_back(pole);

        if(poprzedInit != nullptr)
            poprzedInit->wskKolejny = pole;

        poprzedInit = pole;
    }

    for(int i = 7; i<=10; i++) // kreska (7,4) -> (10,4)
    {
        Pole* pole = new Pole(i,4,brak,poprzedInit);
        pola.push_back(pole);

        if(poprzedInit != nullptr)
            poprzedInit->wskKolejny = pole;

        poprzedInit = pole;
    }

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
