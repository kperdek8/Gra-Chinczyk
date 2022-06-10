#include "Plansza.h"

#include <string>
#include <stdlib.h>
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
    okno = new sf::RenderWindow(sf::VideoMode(800,600),"Chinczyk");
    okno->setFramerateLimit(60);

    zaktualizujKosc(1);

    polaStartowe.resize(4);
    schowki.resize(4);
    obrazPlanszy.resize(11);
    pionki.resize(4);

    Pole* pierwszyInit = nullptr; //Wskaznik sluzacy do polaczenia na koncu inicjalizacji pierwszego i ostatniego pola
    Pole* pole = nullptr; //Wskaznik ktoremu beda przypisywane inicjalizowane pola, ktore nastepnie trafia do wektora.

    for(int i=0; i<=1; i++) //Schowek czerwonego
    {
        for(int k=0; k<=1; k++)
        {
            pole = new Pole(i,k,czerwony);
            pola.push_back(pole);
            schowki.at(czerwony).push_back(pole);


            Pionek* pionek = new Pionek(czerwony,pole);
            pionki.at(czerwony).push_back(pionek);

            pole->postawPionek(pionek);
        }
    }

    for(int i=9; i<=10; i++) //Schowek niebieskiego
    {
        for(int k=0; k<=1; k++)
        {
            pole = new Pole(i,k,niebieski);
            pola.push_back(pole);
            schowki.at(niebieski).push_back(pole);

            Pionek* pionek = new Pionek(niebieski,pole);
            pionki.at(niebieski).push_back(pionek);

            pole->postawPionek(pionek);
        }
    }

    for(int i=0; i<=1; i++) //Schowek zoltego
    {
        for(int k=9; k<=10; k++)
        {
            pole = new Pole(i,k,zolty);
            pola.push_back(pole);
            schowki.at(zolty).push_back(pole);

            Pionek* pionek = new Pionek(zolty,pole);
            pionki.at(zolty).push_back(pionek);

            pole->postawPionek(pionek);
        }
    }

    for(int i=9; i<=10; i++) //Schowek zielonego
    {
        for(int k=9; k<=10; k++)
        {
            pole = new Pole(i,k,zielony);
            pola.push_back(pole);
            schowki.at(zielony).push_back(pole);

            Pionek* pionek = new Pionek(zielony,pole);
            pionki.at(zielony).push_back(pionek);

            pole->postawPionek(pionek);
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
    pierwszyInit->wskPoprzedni = pole; //Laczenie ostatniego i pierwsze pola

    //Do testowania, postawienie jednego pionka kazdego gracza na polu startowym

    for(size_t i = 0; i<pionki.size(); i++)
    {
        Pionek* pionek = pionki.at(i).at(0);
        pionek->postawPionek(polaStartowe.at(i));
        polaStartowe.at(i)->postawPionek(pionek);
    }
}

Plansza::~Plansza()
{
    delete okno;

    for(size_t i = 0; i<pola.size(); i++)
    {
        delete pola.at(i);
    }

    for(size_t i = 0; i<pionki.size(); i++)
    {
        for(size_t k = 0; k<pionki.at(i).size(); k++)
        delete pionki.at(i).at(k);
    }
}

void Plansza::zaktualizujKosc(int rzut)
{
    SFMLSupport::przygotujRysunekKosci(okno,&kosc,teksturaKosci,rzut);
}

void Plansza::wyswietlPlansze()
{

    okno->clear(sf::Color(212,179,127)); //Jasno-brazowy
    sf::Event event;

    while(okno->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            okno->close();
        else if (event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            okno->setView(sf::View(visibleArea));
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            float x = event.mouseButton.x;
            float y = event.mouseButton.y;

            for(size_t i = 0; i<pola.size(); i++) //Sprawdzanie pol
                if(SFMLSupport::czyKliknieto(okno,x,y,pola[i]->x,pola[i]->y))
                    {
                        //
                    }
            if(SFMLSupport::czyKliknieto(okno,x,y,kosc))
            {
                std::cout<<"Rzut"<<std::endl;
            }
        }
    }

    for(size_t i = 0; i<pola.size(); i++)
    {
        sf::CircleShape rysunek;
        SFMLSupport::przygotujRysunekPola(okno,&rysunek,pola[i]);
        okno->draw(rysunek);

        if(pola[i]->wskPionek != nullptr)
        {
            sf::CircleShape rysunek2;
            SFMLSupport::przygotujRysunekPionka(okno,&rysunek2,pola[i]->wskPionek);
            okno->draw(rysunek2);
        }
    }

    SFMLSupport::przygotujRysunekKosci(okno,&kosc,teksturaKosci);
    okno->draw(kosc);
    okno->display();
}

Pionek* Plansza::zwrocPionek(Kolor kolorGracza, int indeksPionka)
{
    return pionki[kolorGracza][indeksPionka];
}
