#ifndef POLE_H
#define POLE_H

#include "ElementGry.h"
#include "Kolor.h"
#include <SFML/Graphics.hpp>

class Pionek;

class Pole : public ElementGry
{
    public:
        Pole();
        Pole(int aX, int aY,Kolor aKolorPola=brak, Pole* aWskPoprzedni = nullptr, Pole* aWskKolejny = nullptr);

        void postawPionek(Pionek* wsk);
        void zdejmijPionek();

        int zwrocX() {return x;}
        int zwrocY() {return y;}

        Pionek* zwrocPionek() {return wskPionek;}
        Pole* nastepnePole() { return wskKolejny;}
        Pole* poprzedniePole() { return wskPoprzedni;}

    private:
        friend class Plansza;
        int x;
        int y;
        Pionek* wskPionek;
        Pole *wskPoprzedni;
        Pole *wskKolejny;
};

#endif // POLE_H
