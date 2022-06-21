#ifndef SFMLSUPPORT_H
#define SFMLSUPPORT_H

#include <SFML/Graphics.hpp>
#include <Kolor.h>
#include <Pole.h>
#include <Pionek.h>

class SFMLSupport
{
    public:
        static int dice_x_pos;
        static int dice_y_pos;
        static bool czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, sf::Text text);
        static bool czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, sf::Sprite sprite);
        static bool czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, int x, int y);
        static void przygotujRysunekPola(sf::RenderWindow* okno, sf::CircleShape* rysunek,Pole* pole);
        static void przygotujRysunekPionka(sf::RenderWindow* okno, sf::CircleShape* rysunek,Pionek* pionek, bool czyMoznaRuszyc = false);
        static void przygotujRysunekKosci(sf::RenderWindow* okno, sf::Sprite* rysunek, sf::Texture &tekstura, int rzut = 0);
        static void przesunKosc(Kolor kolor);
        static int oknoResetuGry(sf::RenderWindow* okno, Kolor ktoWygral); //Zwraca wartosc 1 jezeli kliknieto przycisk "TAK", "0" - jezeli nic albo "-1" jezeli kliknieto "NIE"
        static sf::Color zamienKolorNaSFML(Kolor kolor);
};

#endif // SFMLSUPPORT_H
