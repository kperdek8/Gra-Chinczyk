#ifndef GRA_H
#define GRA_H

#include "Plansza.h"
#include "Kolor.h"
#include "Gracz.h"

#include <vector>

class Plansza;

class Gra
{
    public:
        Gra();
        virtual ~Gra();
        void przesunPionek(Pionek* pionek);
        void zresetujPlansze();
        void petlaGry();
        void zaktualizujTure();
        void rzucKoscia();
        bool czyDozwolonyRuch(Pionek* Pionek);

    protected:

    private:
        Kolor czyjaTura;

        const int DICE_ANIMATION_SPEED = 100; //ms
        const int MOVE_ANIMATION_SPEED = 500;
        int ostatniRzut;

        bool czyPionekJestPrzesuwany;
        bool czyGraSkonczona;
        bool czyRzuconoKoscia;
        bool czyPodjetoDecyzje;
        bool czyZrobilOkrazenie(Pionek* pionek);

        Plansza* planszaWsk;
        std::vector<Gracz*> gracze;


};

#endif // GRA_H
