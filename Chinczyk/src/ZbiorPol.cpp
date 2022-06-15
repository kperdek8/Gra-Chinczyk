#include "ZbiorPol.h"

Pole* &ZbiorPol::operator[](int i)
{
    return pola.at(i);
}

void ZbiorPol::operator>>(Pole* pole)
{
    pola.push_back(pole);
}

bool ZbiorPol::czyPuste()
{
    for(size_t i = 0; i<pola.size(); i++)
    {
        if(pola.at(i)->zwrocPionek() != nullptr)
            return false;
    }
    return true;
}

bool ZbiorPol::czyPelne()
{
    for(size_t i = 0; i<pola.size(); i++)
    {
        if(pola.at(i)->zwrocPionek() == nullptr)
            return false;
    }
    return true;
}

bool ZbiorPol::czyZnajdujeSie(Pionek* pionek)
{
    for(size_t i = 0; i<pola.size(); i++)
    {
        if(pola.at(i)->zwrocPionek() == pionek)
            return true;
    }
    return false;
}

void ZbiorPol::wstaw(Pionek* pionek)
{
    for(size_t i = 0; i<pola.size(); i++)
    {
        if(pola.at(i)->zwrocPionek() == nullptr)
        {
            if(pionek->gdzieStoje() != nullptr)
                pionek->gdzieStoje()->zdejmijPionek();
            pionek->postawPionek(pola.at(i));
            pionek->dezaktywuj();
            pola.at(i)->postawPionek(pionek);
            return;
        }
    }
}

void ZbiorPol::wyjmij(Pole* poleDocelowe)
{
    for(size_t i = 0; i<pola.size(); i++)
    {
        if(pola.at(i)->zwrocPionek() != nullptr)
        {
            Pionek* pionek = pola.at(i)->zwrocPionek();
            pionek->aktywuj();
            pionek->gdzieStoje()->zdejmijPionek();
            pionek->postawPionek(poleDocelowe);
            poleDocelowe->postawPionek(pionek);
        }
    }
}
