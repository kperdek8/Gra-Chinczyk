#ifndef PIONEK_H
#define PIONEK_H

#include "Kolor.h"

class Pole;

class Pionek
{
    public:
        Pionek(Kolor aKolorPionka, Pole* aWskPole);
        ~Pionek();

        void wystawPionek();
        void zbijPionek();
        void postawPionek(Pole* pole);

        bool czyWystawiony() {return wystawiony;}
        Kolor zwrocKolor() {return kolorPionka;}
        Pole* gdzieStoje() {return wskPole;}

    private:
        friend class Plansza;

        bool wystawiony;
        Kolor kolorPionka;
        Pole* wskPole;

};

#endif // PIONEK_H
