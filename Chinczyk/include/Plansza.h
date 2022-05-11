#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include <vector>

class Plansza
{
    public:
        Plansza();
        virtual ~Plansza();
        void wyswietlPlansze();
        void wyswietlKomunikat() const;

    protected:

    private:
        std::vector<Pole*> pola;
};

#endif // PLANSZA_H
