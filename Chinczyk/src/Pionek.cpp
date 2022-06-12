#include "Pionek.h"

Pionek::Pionek(Kolor aKolorPionka, Pole* aWskPole)
{
    wystawiony = false;
    kolorPionka = aKolorPionka;
    wskPole = aWskPole;
}

Pionek::~Pionek()
{
    //dtor
}

void Pionek::zbijPionek()
{
    wystawiony = false;
}

void Pionek::wystawPionek()
{
    wystawiony = true;
}

void Pionek::postawPionek(Pole* pole)
{
    wskPole = pole;
}
