#ifndef PIONEK_H
#define PIONEK_H

#include "Kolor.h"

class Pole;

class Pionek
{
    public:
        Pionek();
        Pionek(kolor aKolorPionka, Pole* aWskPole);
        ~Pionek();
        void postawPionek(Pole* pole);

    private:
        friend class Plansza;
        kolor kolorPionka;
        Pole* wskPole;

};

#endif // PIONEK_H
