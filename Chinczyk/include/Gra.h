#ifndef GRA_H
#define GRA_H

#include "Plansza.h"
#include "Kolor.h"

#include <random>
#include <vector>

class Plansza;

class Gra
{
    public:
        Gra();
        virtual ~Gra();
        void zakonczGre(){czyWyjscZGry = true;}
        void przesunPionek(Pionek* pionek);
        void rzucKoscia();
        bool czyDozwolonyRuch(Pionek* Pionek);
        void zresetujPlansze();

    private:
        Plansza* planszaWsk;

        std::random_device random_device;
        std::mt19937 random_engine{random_device()};
        std::uniform_int_distribution<int> distribution{1, 6};

        Kolor czyjaTura;
        Kolor zwyciezca;

        const int DICE_ANIMATION_SPEED = 60; //ms
        const int MOVE_ANIMATION_SPEED = 400;
        int ostatniRzut;
        int licznikRzutow;

        bool czyWyjscZGry;
        bool czyPionekJestPrzesuwany;
        bool czyGraSkonczona;
        bool czyRzuconoKoscia;
        bool czyRzuconoDrugiRaz;
        bool czyPodjetoDecyzje;

        bool czyZrobilOkrazenie(Pionek* pionek);
        bool czyMaAktywnegoPionka(Kolor kolorGracza);
        void czyGraSieSkonczyla();
        void petlaGry();
        void zresetujLicznik();
        void zaktualizujTure();
        void zbijPionek(Pionek* pionek);
        void wprowadzDoDomku(Pionek* pionek);

};

#endif // GRA_H
