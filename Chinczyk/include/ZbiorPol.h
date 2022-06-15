#ifndef ZBIORPOL_H
#define ZBIORPOL_H

#include "Pole.h"
#include "Pionek.h"
#include "Kolor.h"

#include <vector>

class ZbiorPol
{
    public:
        bool czyPuste();
        bool czyPelne();
        bool czyZnajdujeSie(Pionek* pionek);
        void wstaw(Pionek* pionek);
        void wyjmij(Pole* poleDocelowe);
        Pole* &operator[](int i);
        void operator>>(Pole* pole);

    private:
        std::vector<Pole*> pola;
};
#endif // ZBIORPOL_H
