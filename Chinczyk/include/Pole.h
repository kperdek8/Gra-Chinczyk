#ifndef POLE_H
#define POLE_H

enum kolor{brak=0, niebieski=1, czerwony=2, zolty=3, zielony=4};


class Pole
{
    public:
        Pole();
        Pole(int aX, int aY,kolor aKolorPola=brak, Pole * aWskPoprzedni = nullptr, Pole * aWskKolejny = nullptr);
        ~Pole();
        //void postawPionek(); //Obiekt otrzymuje wskaŸnik pionka, który stan¹³ na tym polu

    protected:
        //Pionek wskPionek; //wskaŸnik na pionek znajduj¹cy siê na polu
    private:
        friend class Plansza;
        int x;
        int y;
        kolor kolorPola;
        Pole *wskPoprzedni;
        Pole *wskKolejny;
        //Funkcja informujaca Planszê o naciœniêciu pola
};

#endif // POLE_H
