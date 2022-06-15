#ifndef PLANSZA_H
#define PLANSZA_H

#include "Pole.h"
#include "Pionek.h"
#include "SFMLSupport.h"
#include "Gra.h"
#include "ZbiorPol.h"

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
        void wyswietlResetGry(Kolor ktoWygral);
        void zmienNazweOkna(Kolor kolorGracza); //Zmienia nazwe okna w zaleznosci od tego czyja jest tura

        Pionek* zwrocPionek(Kolor kolorGracza, int indeksPionka);
        Pole* zwrocPoleStartowe(Kolor kolorGracza);
        ZbiorPol zwrocSchowek(Kolor kolorGracza);
        ZbiorPol zwrocDomek(Kolor kolorGracza);

    protected:

    private:
        Gra* gra;

        sf::RenderWindow* okno;
        sf::Sprite kosc;
        sf::Texture teksturaKosci;

        std::vector<ZbiorPol> schowki;
        std::vector<ZbiorPol> domki;

        std::vector<std::vector<Pionek*>> pionki; //Pierwsza wspolrzedna odpowiada za kolor gracza, a druga indeksy pionkow nalezacych do danego gracza
        std::vector<Pole*> pola;
        std::vector<Pole*> polaStartowe;

};

#endif // PLANSZA_H
