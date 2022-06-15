#include "Pionek.h"

Pionek::Pionek(Kolor aKolorPionka, Pole* aWskPole)
{
    aktywny = false;
    kolor = aKolorPionka;
    wskPole = aWskPole;
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
