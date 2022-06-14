# Projekt gry Chińczyk

## Zasady gry
* Gra przeznaczona dla 2-4 graczy
* Każdy gracz ma swój schowek, znajdujący się poza planszą i zawierający cztery pionki oraz "domek", do którego trafiają pionki, którym udało się okrążyć planszę.
* Na początku gracze rzucają po kolei trzy razy kością do momentu wyrzucenia liczby 6 - wtedy przesuwają jeden z swoich pionków z schowka na pole startowe.
* Następnie gracze rzucają w ustalonej kolejności kością jeden raz, a następnie przesuwają pionek o liczbę pól równej wylosowanej liczbie oczek. W przypadku, gdy na planszy znajduje się kilka pionków jednego gracza, to wybiera którym pionkiem chce się ruszyć
* W przypadku wyrzucenia liczby 6, gracz ma możliwość prowadzenia kolejnego pionka do gry lub rzucenia kością jeszcze raz i przesunięcia jednego pionka o sumę wszystkich rzutów. W przypadku wystapienia szostki drugi raz, gracz nie otrzymuje kolejnego rzutu.
* Pionki mogą nad sobą przeskakiwać
* Jeśli podczas gry pionek jednego gracza stanie na polu zajmowanym przez drugiego, pomijając pole startowe, pionek stojący tutaj poprzednio zostaje zbity i wraca do swojego schowka.
* Jeżeli po ruchu pionek stanąłby na polu zajmowanym przez innego pionka tego samego koloru, to ruch jest niedozwolony i gracz musi wykonać ruch innym pionkiem.
* Pionek, który zrobił pełne okrążęnie wokół planszy i dotarł ponownie na pole startowe trafia do "domku".
* Jeżeli gracz, który nie ma pionków na planszy z powodu zbicia lub doprowadzenia pionków do "domku" rzuca kostką trzy razy do momentu wyrzucenia szóstki i wprowadza nowego pionka do gry. Jeżeli mu się nie udało, to powtarza procedurę podczas kolejnej tury.
* Wygrywa gracz, który jako pierwszy doprowadzi cztery pionki do "domku"

## Klasy

### Plansza

* Zawiera tablice wszystkich pól i pionków
* Zawiera informacje o polu startowym każdego gracza
* Zawiera informacje o polach tworzących "domek" każdego gracza
* Wyświetla pola oraz pionki
* Wyświetla komunikaty (czyja jest tura lub możliwe decyzje)
* Wyświetla rezultat rzutu kością

### Pole

* Zawiera informacje o swojej pozycji na ekranie
* Zawiera informacje o swoim kolorze
* Zawiera wskaźnik na kolejne pole
* Zawiera wskaznik na pionek, ktory stoi na tym polu (lub informacje że pole jest puste)
* Informuje planszę, kiedy użytkownik kliknie dane pole

### Pionek

* Zawiera informacje do którego gracza należy
* Zawiera informacje na którym polu stoi

### Gracz

* Rzuca kością
* Decyduje, którego pionka ruszyć
* Decyduje czy wprowadzić nowego pionka do gry, czy rzucać dalej (wyrzucenie szóstki)

### AI

* Zastępuje klasę gracz i podejmuje decyzje na podstawie algorytmu

### Gra

* Pilnuje czyja jest tura i informuje o tym plansze
* Pyta gracza o decyzje
* Przesuwa pionki
* Losuje wynik rzutu kością
* Sprawdza czy pionek wykonał pełne okrążenie, jeśli tak przenosi pionek do "domku"
* Sprawdza czy ruch użytkownika jest dozwolony
* Sprawdza czy gra się skończyła (czy wszystkie pionki, któregoś gracza dotarły do "domku")

# TO-DO
- [x] Klasa Plansza (najpierw w wersji konsolowej), klasa Pole
- [x] Klasa Pionek i algorytm przesuwania pionka (z pionkiem zaczynającym od razu na planszy)
- [x] Klasa Gra i przeniesienie algorytmu przesuwania pionka do niej
- [x] Dodanie obslugi tur w klasie Gra
- [x] Przerobienie klasy Plansza do SFML
- [x] Interakcja Plansza<->Użytkownik
- [x] Obsługa wyboru, którego pionka ruszyć
- [x] Obsługa wylosowania szóstki - możliwość wystawiania kolejnych pionków na planszę oraz sumowanie rzutów
- [x] Obsługa "domków" 
- [x] Obsługa zbijania pionków i blokada ruchu pionkiem, jeśli będzie skutkował staniem dwóch pionków tego samego koloru na tym samym polu
- [x] Obsługa trzykrotnego rzutu kością w przypadku, kiedy gracz nie ma wystawionych pionków na planszy
- [ ] Napisanie algorytmu AI, który może podejmować decyzje w ramach klasy Gracz
