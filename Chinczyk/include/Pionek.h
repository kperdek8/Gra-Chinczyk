#ifndef PIONEK_H
#define PIONEK_H

#include "Kolor.h"

class Pole;

class Pionek
{
    public:
        Pionek(Kolor aKolorPionka, Pole* aWskPole);
        ~Pionek();

        void aktywuj();
        void dezaktywuj();
        void postawPionek(Pole* pole);

        bool czyAktywny() {return aktywny;}
        Kolor zwrocKolor() {return kolorPionka;}
        Pole* gdzieStoje() {return wskPole;}

    private:
        friend class Plansza;

        bool aktywny;
        Kolor kolorPionka;
        Pole* wskPole;

};

#endif // PIONEK_H
