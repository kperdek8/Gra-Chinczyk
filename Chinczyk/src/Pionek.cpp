#include "Pionek.h"

Pionek::Pionek()
{
    kolorPionka = niebieski;
    wskPole = nullptr;
}

Pionek::Pionek(kolor aKolorPionka, Pole* aWskPole)
{
    kolorPionka = aKolorPionka;
    wskPole = aWskPole;
}

Pionek::~Pionek()
{
    //dtor
}

void Pionek::postawPionek(Pole* pole)
{
    wskPole = pole;
}
