#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "Pionek.h"

#include <SFML/Window.hpp>
#include <vector>
#include <string>

class Plansza
{
    public:
        Plansza();
        ~Plansza();
        void wyswietlRzut(int rzut);
        void wyswietlPlansze();
        void narysujPlansze();
        void wyczyscPlansze();
        void wyswietlKomunikat(std::string komunikat, bool czyCzekac = true);
        Pionek* zwrocPionek(Kolor kolorGracza, int indeksPionka);

    protected:

    private:
        sf::Window* okno;
        std::vector<std::string> obrazPlanszy;
        std::vector<std::vector<Pionek*>> pionki; //Pierwsza wspolrzedna odpowiada za kolor gracza, a druga indeksy pionkow nalezacych do danego gracza
        std::vector<Pole*> pola;
        std::vector<Pole*> polaStartowe;
        std::vector<std::vector<Pole*>> schowki; //Pierwsza wspolrzedna odpowiada za kolor gracza, a druga indeksy poszczegolnych pol schowka nalezacych do danego gracza

};

#endif // PLANSZA_H
