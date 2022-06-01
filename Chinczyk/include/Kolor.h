#ifndef KOLOR_H
#define KOLOR_H

#include <iostream>

enum Kolor{niebieski=0, czerwony=1, zolty=2, zielony=3, brak=4};

inline Kolor& operator++(Kolor& kolor)
{
    if(kolor != zielony)
        kolor = static_cast<Kolor>(kolor+1);
    else
        kolor = niebieski;

    return kolor;
}

#endif // KOLOR_H
