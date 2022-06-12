#include "SFMLSupport.h"
#include <iostream>

sf::Color SFMLSupport::zamienKolorNaSFML(Kolor kolor)
{
    switch(kolor)
    {
        case niebieski:
            return sf::Color::Blue;
        case czerwony:
            return sf::Color::Red;
        case zolty:
            return sf::Color::Yellow;
        case zielony:
            return sf::Color::Green;
        case brak:
            return sf::Color::White;
    }
}

bool SFMLSupport::czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, sf::Sprite sprite)
{
    if(mouseX >= sprite.getGlobalBounds().left && mouseX <= sprite.getGlobalBounds().left + sprite.getGlobalBounds().width)
    {
        if(mouseY >= sprite.getGlobalBounds().top && mouseY <= sprite.getGlobalBounds().top + sprite.getGlobalBounds().height)
        {
            return true;
        }
    }
    return false;
}

bool SFMLSupport::czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, int x, int y)
{
    float xOffset = 0;
    float yOffset = 0;

    if(okno->getSize().x > okno->getSize().y)
        xOffset = (okno->getSize().x - okno->getSize().y);
    else if(okno->getSize().y > okno->getSize().x)
        yOffset = (okno->getSize().y - okno->getSize().x);

    float relativeMouseX = mouseX - xOffset/2;
    float relativeMouseY = mouseY - yOffset/2;
    //Przeliczenie wartosci x,y z siatki 11x11 na piksele okna i sprawdzenie czy myszka znajduje sie w wyliczonym przedziale

    if(relativeMouseX >= ((okno->getSize().x - xOffset)*x/11.0) && relativeMouseX <= ((okno->getSize().x - xOffset)*(x+1)/11.0))
    {
        if(relativeMouseY >= ((okno->getSize().y - yOffset)*y/11.0) && relativeMouseY <= ((okno->getSize().y - yOffset)*(y+1)/11.0))
        {
            return true;
        }
    }
    return false;
}

void SFMLSupport::przygotujRysunekPola(sf::RenderWindow* okno, sf::CircleShape* rysunek, Pole* pole)
{
    //Roznice miedzy szerokoscia i wysokoscia okna sluzace do wysrodkowania planszy
    float xOffset = 0;
    float yOffset = 0;

    if(okno->getSize().x > okno->getSize().y)
        xOffset = (okno->getSize().x - okno->getSize().y);
    else if(okno->getSize().y > okno->getSize().x)
        yOffset = (okno->getSize().y - okno->getSize().x);

    //Wspolrzedne sa wyliczone przy traktowaniu planszy jako kwadratu 11x11
    float x = ((okno->getSize().x - xOffset) * pole->zwrocX())/11.0;
    float y = ((okno->getSize().y - yOffset) * pole->zwrocY())/11.0;
    float r = (0.9*(okno->getSize().x - xOffset))/(11.0*2.0);

    rysunek->setRadius(r);
    rysunek->setPosition(x+(xOffset/2.0),y+(yOffset/2.0)); //Wczesniej wyliczone wspolrzedne sa nastepnie przesuwane w celu wysrodkowania planszy
    rysunek->setOutlineThickness(2);
    rysunek->setOutlineColor(sf::Color::Black);
    rysunek->setFillColor(zamienKolorNaSFML(pole->zwrocKolor()));
}

void SFMLSupport::przygotujRysunekPionka(sf::RenderWindow* okno, sf::CircleShape* rysunek, Pionek* pionek, bool czyMoznaRuszyc)
{
    //Roznice miedzy szerokoscia i wysokoscia okna sluzace do wysrodkowania planszy
    float xOffset = 0;
    float yOffset = 0;

    if(okno->getSize().x > okno->getSize().y)
        xOffset = (okno->getSize().x - okno->getSize().y);
    else if(okno->getSize().y > okno->getSize().x)
        yOffset = (okno->getSize().y - okno->getSize().x);

    //Wspolrzedne sa wyliczone przy traktowaniu planszy jako kwadratu 11x11, wspolrzedne pionka sa dodatkowo przesuniete o 0.15 pola w celu wysrodkowania go do pola na ktorym stoi
    float x = ((okno->getSize().x - xOffset) * (pionek->gdzieStoje()->zwrocX() + 0.135))/11.0;
    float y = ((okno->getSize().y - yOffset) * (pionek->gdzieStoje()->zwrocY() + 0.135))/11.0;
    float r = (0.9*(okno->getSize().x - xOffset))/(11.0*2.0);

    rysunek->setRadius(0.7*r);
    rysunek->setPosition(x+(xOffset/2.0),y+(yOffset/2.0));
    rysunek->setOutlineThickness(2);
    if(czyMoznaRuszyc)
        rysunek->setOutlineColor(sf::Color(169,169,169)); //Srebrny
    else
        rysunek->setOutlineColor(sf::Color::Black);
    rysunek->setFillColor(zamienKolorNaSFML(pionek->zwrocKolor()));
}

void SFMLSupport::przygotujRysunekKosci(sf::RenderWindow* okno, sf::Sprite* rysunek, sf::Texture &tekstura, int rzut)
{
    float xOffset = 0;
    float yOffset = 0;

    if(okno->getSize().x > okno->getSize().y)
        xOffset = (okno->getSize().x - okno->getSize().y);
    else if(okno->getSize().y > okno->getSize().x)
        yOffset = (okno->getSize().y - okno->getSize().x);

    //Wspolrzedne sa wyliczone przy traktowaniu planszy jako kwadratu 11x11
    float x = ((okno->getSize().x - xOffset) * DICE_X_POS)/11.0;
    float y = ((okno->getSize().y - yOffset) * DICE_Y_POS)/11.0;

    if(rzut >= 1 && rzut <= 6)
    {
        switch(rzut)
        {
        case 1:
            tekstura.loadFromFile("sprites/kosc-jeden.png");
            break;
        case 2:
            tekstura.loadFromFile("sprites/kosc-dwa.png");
            break;
        case 3:
            tekstura.loadFromFile("sprites/kosc-trzy.png");
            break;
        case 4:
            tekstura.loadFromFile("sprites/kosc-cztery.png");
            break;
        case 5:
            tekstura.loadFromFile("sprites/kosc-piec.png");
            break;
        case 6:
            tekstura.loadFromFile("sprites/kosc-szesc.png");
            break;
        }
    }

    float scale = 0.9*(((okno->getSize().x - xOffset) * 2 / 11.0) / tekstura.getSize().x);

    rysunek->setTexture(tekstura);
    rysunek->setScale(scale,scale);
    rysunek->setPosition(x+(xOffset/2.0),y+yOffset/2.0);
}
