#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "Pionek.h"
#include "SFMLSupport.h"
#include "Gra.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>

class Gra;

class Plansza
{
    public:
        Plansza(Gra* aGra);
        ~Plansza();

        void zaktualizujKosc(int rzut);
        void wyswietlPlansze();
        Pionek* zwrocPionek(Kolor kolorGracza, int indeksPionka);
        Pole* zwrocPoleStartowe(Kolor kolorGracza);
        std::vector<Pole*> zwrocSchowek(Kolor kolorGracza);

    protected:

    private:
        Gra* gra;

        sf::RenderWindow* okno;
        sf::Sprite kosc;
        sf::Texture teksturaKosci;

        std::vector<std::vector<Pionek*>> pionki; //Pierwsza wspolrzedna odpowiada za kolor gracza, a druga indeksy pionkow nalezacych do danego gracza
        std::vector<Pole*> pola;
        std::vector<Pole*> polaStartowe;
        std::vector<std::vector<Pole*>> schowki; //Pierwsza wspolrzedna odpowiada za kolor gracza, a druga indeksy poszczegolnych pol schowka nalezacych do danego gracza

};

#endif // PLANSZA_H
