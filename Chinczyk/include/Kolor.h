#ifndef KOLOR_H
#define KOLOR_H

#include <iostream>
#include <SFML/Graphics.hpp>

enum Kolor{niebieski=0, zielony=1, zolty=2, czerwony=3, brak=4};

inline Kolor& operator++(Kolor& kolor)
{
    if(kolor != 3)
        kolor = static_cast<Kolor>(kolor+1);
    else
        kolor = niebieski;

    return kolor;
}

#endif // KOLOR_H
