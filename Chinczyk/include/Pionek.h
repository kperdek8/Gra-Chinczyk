#ifndef PIONEK_H
#define PIONEK_H

#include "Kolor.h"

class Pole;

class Pionek
{
    public:
        Pionek();
        Pionek(Kolor aKolorPionka, Pole* aWskPole);
        ~Pionek();
        void postawPionek(Pole* pole);
        Pole* gdzieStoje() { return wskPole; }

    private:
        friend class Plansza;
        Kolor kolorPionka;
        Pole* wskPole;

};

#endif // PIONEK_H
