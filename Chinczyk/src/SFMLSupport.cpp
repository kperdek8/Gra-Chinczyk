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

bool SFMLSupport::czyKliknieto(sf::RenderWindow* okno, float mouseX, float mouseY, sf::Text text)
{
    if(mouseX >= text.getGlobalBounds().left && mouseX <= text.getGlobalBounds().left + text.getGlobalBounds().width)
    {
        if(mouseY >= text.getGlobalBounds().top && mouseY <= text.getGlobalBounds().top + text.getGlobalBounds().height)
        {
            return true;
        }
    }
    return false;
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

int SFMLSupport::oknoResetuGry(sf::RenderWindow* okno, Kolor ktoWygral)
{
    const float BIG_SCALE = 0.1;
    const float SMALL_SCALE = 0.8*BIG_SCALE;
    const float INTERVAL = 0.11;
    const float POSITION = 0.0;

    sf::Event event;

    sf::Font font;
    font.loadFromFile("res/arial.ttf");
    sf::Text ogloszenieZwyciezcy("",font);

    switch(ktoWygral)
    {
        case niebieski:
            ogloszenieZwyciezcy.setString("Wygral niebieski!");
            break;
        case czerwony:
            ogloszenieZwyciezcy.setString("Wygral czerwony!");
            break;
        case zielony:
            ogloszenieZwyciezcy.setString("Wygral zielony!");
            break;
        case zolty:
            ogloszenieZwyciezcy.setString("Wygral zolty!");
            break;
    }

    sf::Text zapytanie("Czy zaczac nastepna gre?",font);
    sf::Text tak("TAK",font);
    sf::Text nie("NIE",font);

    ogloszenieZwyciezcy.setCharacterSize(okno->getSize().y*BIG_SCALE);
    zapytanie.setCharacterSize(okno->getSize().y*BIG_SCALE);
    tak.setCharacterSize(okno->getSize().y*SMALL_SCALE);
    nie.setCharacterSize(okno->getSize().y*SMALL_SCALE);

    ogloszenieZwyciezcy.setPosition((okno->getSize().x - ogloszenieZwyciezcy.getGlobalBounds().width)/2,POSITION);
    zapytanie.setPosition((okno->getSize().x - zapytanie.getGlobalBounds().width)/2,POSITION+okno->getSize().y*INTERVAL);
    tak.setPosition((okno->getSize().x/2) - 2*tak.getGlobalBounds().width,POSITION+okno->getSize().y*INTERVAL*3);
    nie.setPosition((okno->getSize().x/2) + nie.getGlobalBounds().width,okno->getSize().y*INTERVAL*3);

    ogloszenieZwyciezcy.setColor(sf::Color::Black);
    zapytanie.setColor(sf::Color::Black);
    tak.setColor(sf::Color::Black);
    nie.setColor(sf::Color::Black);

    okno->draw(ogloszenieZwyciezcy);
    okno->draw(zapytanie);
    okno->draw(tak);
    okno->draw(nie);

    while(okno->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            okno->close();
        else if (event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            okno->setView(sf::View(visibleArea));
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if(czyKliknieto(okno,event.mouseButton.x,event.mouseButton.y,tak))
            {
                return 1;
            }

            else if(czyKliknieto(okno,event.mouseButton.x,event.mouseButton.y,nie))
            {
                return -1;
            }
        }
    }

    return 0;

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
            tekstura.loadFromFile("res/kosc-jeden.png");
            break;
        case 2:
            tekstura.loadFromFile("res/kosc-dwa.png");
            break;
        case 3:
            tekstura.loadFromFile("res/kosc-trzy.png");
            break;
        case 4:
            tekstura.loadFromFile("res/kosc-cztery.png");
            break;
        case 5:
            tekstura.loadFromFile("res/kosc-piec.png");
            break;
        case 6:
            tekstura.loadFromFile("res/kosc-szesc.png");
            break;
        }
    }

    float scale = 0.9*(((okno->getSize().x - xOffset) * 2 / 11.0) / tekstura.getSize().x);

    rysunek->setTexture(tekstura);
    rysunek->setScale(scale,scale);
    rysunek->setPosition(x+(xOffset/2.0),y+yOffset/2.0);
}
