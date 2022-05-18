#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "Pionek.h"

#include <vector>
#include <string>

class Plansza
{
    public:
        Plansza();
        ~Plansza();
        void wyswietlPlansze();
        void narysujPlansze();
        void wyczyscPlansze();
        void wyswietlKomunikat();
        void przesunPionek(Pionek* pionek, int liczbaPol, int szybkoscAnimacji = 600);
        Pionek* testowyPionek;

    protected:

    private:
        std::vector<std::string> obrazPlanszy;
        std::vector<Pionek*> pionki;
        std::vector<Pole*> pola;
        std::vector<Pole*> polaStartowe;
        std::vector<std::vector<Pole*>> schowki;

};

#endif // PLANSZA_H
