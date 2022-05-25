#include "Gracz.h"

#include "iostream"

Gracz::Gracz(bool aJestAI, Kolor aKolorGracza)
{
    jestAI = aJestAI;
    kolorGracza = aKolorGracza;
}

Gracz::~Gracz()
{
    //dtor
}

void wyswietlZapytanie()
{
    std::cout<<"Wpisz 'rzuc' zeby rzucic koscia lub 'wystaw' zeby wystawic nowy pionek do gry (jezeli zasady na to pozwalaja"<<std::endl;
}

Decyzja Gracz::zdecyduj()
{
    std::string input;
    wyswietlZapytanie();

    while(input != "rzuc" && input != "wystaw")
    {
        cin>>input;
    }

    if(input == "rzuc")
        return rzuc;
    else
        return wystaw;
}
