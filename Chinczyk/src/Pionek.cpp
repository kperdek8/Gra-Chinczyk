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

void Pionek::info() //Wersja bez przeciazenia
{
    std::cout<<"======================"<<std::endl;
    std::cout<<"PIONEK "<<uid<<std::endl;
    std::cout<<"kolor: "<<kolor<<std::endl;
    std::cout<<"czyAktywny: "<<aktywny<<std::endl;
    std::cout<<"uid: "<<uid<<std::endl;
    std::cout<<"wskPole: "<<wskPole<<std::endl;
}

void Pionek::info(std::ostream& str) //Wersja z przeciazeniem << i ostream
{
    str<<kolor<<" "<<aktywny<<" "<<uid<<" "<<wskPole<<" ";
}
