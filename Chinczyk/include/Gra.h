#ifndef GRA_H
#define GRA_H

#include "Plansza.h"
#include "Kolor.h"
#include "Gracz.h"

#include <vector>

class Gra
{
    public:
        Gra();
        virtual ~Gra();
        void przesunPionek(Pionek* pionek, int liczbaPol, int szybkoscAnimacji = 600);
        void zresetujPlansze();
        void zacznijGre();
        void zaktualizujTure();
        int rzucKoscia();

    protected:

    private:
        Kolor czyjaTura;
        bool czyGraSkonczona;

        Plansza* planszaWsk;
        std::vector<Gracz*> gracze;

        bool czyDozwolony();
        bool czyGraSkonczylaSie();
        bool czyZrobilOkrazenie();
};

#endif // GRA_H
