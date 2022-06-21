#include "Pole.h"

Pole::Pole()
{
    x=0;
    y=0;
    kolor=brak;
    wskKolejny=nullptr;
    wskPionek=nullptr;
}

Pole::Pole(int aX, int aY, Kolor aKolorPola, Pole * aWskPoprzedni, Pole * aWskKolejny)
{
    x=aX;
    y=aY;
    kolor = aKolorPola;
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

void Pole::info() //Wersja bez przeciazenia
{
    std::cout<<"======================"<<std::endl;
    std::cout<<"POLE "<<uid<<std::endl;
    std::cout<<"x: "<<x<<std::endl;
    std::cout<<"y: "<<y<<std::endl;
    std::cout<<"uid: "<<uid<<std::endl;
    std::cout<<"kolor: "<<kolor<<std::endl;
    std::cout<<"wskPionek: "<<wskPionek<<std::endl;
    std::cout<<"wskKolejny: "<<wskKolejny<<std::endl;
    if(wskKolejny != nullptr)
    std::cout<<"id kolejny: "<<wskKolejny->zwrocId()<<std::endl;
    std::cout<<"wskPoprzedni: "<<wskPoprzedni<<std::endl;
    if(wskKolejny != nullptr)
    std::cout<<"id poprzedni: "<<wskPoprzedni->zwrocId()<<std::endl;
}

void Pole::info(std::ostream& str) //Wersja z przeciazeniem << i ostream
{
    str<<x<<" "<<y<<" "<<x<<" "<<uid<<" "<<kolor<<" "<<wskPionek<<" "<<wskKolejny<<" "<<wskPoprzedni<<" ";
}
