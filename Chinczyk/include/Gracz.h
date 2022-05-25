#ifndef GRACZ_H
#define GRACZ_H

#include "Kolor.h"
#include "Dezycja.h"

class Gracz
{
    public:
        Gracz(bool aJestAI, Kolor aKolorGracza);
        virtual ~Gracz();
        void rzuc();
        Decyzja zdecyduj();

    protected:

    private:
        bool jestAI;
        Kolor kolorGracza;
};

#endif // GRACZ_H
