#ifndef POLE_H
#define POLE_H

enum kolor{niebieski=0, czerwony=1, zolty=2, zielony=3, brak=4};

class Pole
{
    public:
        Pole();
        Pole(int aX, int aY,kolor aKolorPola=brak, Pole * aWskPoprzedni = nullptr, Pole * aWskKolejny = nullptr);
        ~Pole();
        //void postawPionek(); //Obiekt otrzymuje wskaznik pionka, który stanal na tym polu

    protected:
        //Pionek wskPionek; //wskaznik na pionek znajdujacy sie na polu
    private:
        friend class Plansza;
        int x;
        int y;
        kolor kolorPola;
        Pole *wskPoprzedni;
        Pole *wskKolejny;

        //Funkcja informujaca Plansze o nacisnieciu pola
};

#endif // POLE_H
