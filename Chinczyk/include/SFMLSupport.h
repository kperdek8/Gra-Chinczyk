#ifndef SFMLSUPPORT_H
#define SFMLSUPPORT_H

#include <SFML/Graphics.hpp>
#include <Kolor.h>
#include <Pole.h>
#include <Pionek.h>
#include <string>

class SFMLSupport
{
    public:
        static const int DICE_X_POS = 7;
        static const int DICE_Y_POS = 2;
        static bool czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, sf::Sprite sprite);
        static bool czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, int x, int y);
        static void przygotujRysunekPola(sf::RenderWindow* okno, sf::CircleShape* rysunek,Pole* pole);
        static void przygotujRysunekPionka(sf::RenderWindow* okno, sf::CircleShape* rysunek,Pionek* pionek);
        static void przygotujRysunekKosci(sf::RenderWindow* okno, sf::Sprite* rysunek, sf::Texture &tekstura, int rzut = 0);
        static sf::Color zamienKolorNaSFML(Kolor kolor);
};

#endif // SFMLSUPPORT_H
