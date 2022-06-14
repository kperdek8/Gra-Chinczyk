#ifndef GRA_H
#define GRA_H

#include "Plansza.h"
#include "Kolor.h"

#include <vector>

class Plansza;

class Gra
{
    public:
        Gra();
        virtual ~Gra();
        void przesunPionek(Pionek* pionek);
        void rzucKoscia();
        bool czyDozwolonyRuch(Pionek* Pionek);
        void zresetujPlansze();

    protected:

    private:
        Plansza* planszaWsk;

        Kolor czyjaTura;
        Kolor zwyciezca;

        const int DICE_ANIMATION_SPEED = 60; //ms
        const int MOVE_ANIMATION_SPEED = 400;
        int ostatniRzut;
        int licznikRzutow;

        bool czyPionekJestPrzesuwany;
        bool czyGraSkonczona;
        bool czyRzuconoKoscia;
        bool czyRzuconoDrugiRaz;
        bool czyPodjetoDecyzje;

        bool czyZrobilOkrazenie(Pionek* pionek);
        bool czyMaAktywnegoPionka(Kolor kolorGracza);
        void czyGraSieSkonczyla();
        void ustawRzut(); //Do testowania
        void petlaGry();
        void zresetujLicznik();
        void zaktualizujTure();
        void zbijPionek(Pionek* pionek);
        void wprowadzDoDomku(Pionek* pionek);

};

#endif // GRA_H
