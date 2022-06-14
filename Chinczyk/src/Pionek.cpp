#include "Pionek.h"

Pionek::Pionek(Kolor aKolorPionka, Pole* aWskPole)
{
    aktywny = false;
    kolorPionka = aKolorPionka;
    wskPole = aWskPole;
}

Pionek::~Pionek()
{
    //dtor
}

void Pionek::dezaktywuj()
{
    aktywny = false;
}

void Pionek::aktywuj()
{
    aktywny= true;
}

void Pionek::postawPionek(Pole* pole)
{
    wskPole = pole;
}
