#include "Pole.h"

Pole::Pole()
{
    x=0;
    y=0;
    kolorPola=brak;
    wskKolejny=nullptr;
    wskPionek=nullptr;
}

Pole::Pole(int aX, int aY, Kolor aKolorPola, Pole * aWskPoprzedni, Pole * aWskKolejny)
{
    x=aX;
    y=aY;
    kolorPola = aKolorPola;
    wskPoprzedni=aWskPoprzedni;
    wskKolejny=aWskKolejny;
    wskPionek=nullptr;
}

void Pole::postawPionek(Pionek* wsk)
{
    wskPionek = wsk;
}

void Pole::zdejmijPionek()
{
    wskPionek = nullptr;
}
