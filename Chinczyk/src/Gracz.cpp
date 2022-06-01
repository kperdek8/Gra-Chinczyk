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

void wyswietlZapytanie(bool czyMozeWystawic)
{
    std::cout<<"Wpisz 'rzuc' zeby rzucic koscia";
    if(czyMozeWystawic)
    std::cout<<" lub 'wystaw' zeby wystawic nowy pionek do gry";
    std::cout<<std::endl;;
}

Decyzja Gracz::zdecyduj(bool czyMozeWystawic)
{
    std::string input;
    wyswietlZapytanie(czyMozeWystawic);

    while(input != "rzuc" && input != "wystaw")
    {
        std::cin>>input;

        if(input != "rzuc" && input != "wystaw")
        {
            std::cout<<"Wprowadz prawidlowa decyzje"<<std::endl;
        }
    }

    if(input == "rzuc")
        return Decyzja::rzuc;
    else
        return Decyzja::wystaw;
}
