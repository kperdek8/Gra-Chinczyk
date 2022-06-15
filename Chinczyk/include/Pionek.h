#ifndef PIONEK_H
#define PIONEK_H

#include "ElementGry.h"
#include "Kolor.h"

class Pole;

class Pionek : public ElementGry
{
    public:
        Pionek(Kolor aKolorPionka, Pole* aWskPole);

        void aktywuj();
        void dezaktywuj();
        void postawPionek(Pole* pole);
        bool czyAktywny() {return aktywny;}
        Pole* gdzieStoje() {return wskPole;}

    private:
        friend class Plansza;

        bool aktywny;
        Pole* wskPole;

};

#endif // PIONEK_H
