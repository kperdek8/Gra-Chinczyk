#ifndef POLE_H
#define POLE_H

#include "Kolor.h"

class Pionek;

class Pole
{
    public:
        Pole();
        Pole(int aX, int aY,kolor aKolorPola=brak, Pole * aWskPoprzedni = nullptr, Pole * aWskKolejny = nullptr);
        ~Pole();
        void postawPionek(Pionek* wsk);
        void zdejmijPionek();

    private:
        friend class Plansza;
        int x;
        int y;
        kolor kolorPola;
        Pionek* wskPionek;
        Pole *wskPoprzedni;
        Pole *wskKolejny;

        //Funkcja informujaca Plansze o nacisnieciu pola
};

#endif // POLE_H
