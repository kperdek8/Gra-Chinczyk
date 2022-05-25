#ifndef POLE_H
#define POLE_H

#include "Kolor.h"

class Pionek;

class Pole
{
    public:
        Pole();
        Pole(int aX, int aY,Kolor aKolorPola=brak, Pole * aWskPoprzedni = nullptr, Pole * aWskKolejny = nullptr);
        ~Pole();
        void postawPionek(Pionek* wsk);
        void zdejmijPionek();
        Pole* nastepnePole() { return wskKolejny;}
        Pole* poprzedniePole() { return wskPoprzedni;}

    private:
        friend class Plansza;
        int x;
        int y;
        Kolor kolorPola;
        Pionek* wskPionek;
        Pole *wskPoprzedni;
        Pole *wskKolejny;

        //Funkcja informujaca Plansze o nacisnieciu pola
};

#endif // POLE_H
