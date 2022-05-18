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
        void wyswietlKomunikat();

    protected:

    private:
        std::vector<Pole*> pola;
        std::vector<Pole*> polaStartowe;
        std::vector<std::vector<Pole*>> schowki;

};

#endif // PLANSZA_H
