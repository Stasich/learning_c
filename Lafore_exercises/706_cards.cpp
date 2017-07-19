// 706_cards.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum Suit{clubs, diamonds, hearts, spades};
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class cards
{
private:
    int number;
    Suit suit;
public:
    cards()
    {}
    void set(const int&, const Suit& );
    void show_card() const;
};
void mix_a_deck(cards arr[] );
void fill_the_deck(cards arr[] );
void display_deck(cards arr[], int size );
void split_deck(cards deck[], cards p1[], cards p2[], cards p3[], cards p4[]);
void part_cpy(cards p[], cards t[]);

int main()
{
    const int SIZE = 52;                // менять эти константы не имеет смысла
    const int SIZE_P = 13;              // т.к. в половине функций используются фиксированные цифры
    cards deck[SIZE], p1[SIZE_P], p2[SIZE_P], p3[SIZE_P], p4[SIZE_P];
    fill_the_deck( deck );              // заполняем колоду
    cout << "\nИсходная колода:\n";
    display_deck( deck, SIZE);          // выводим на экран
    srand( time( NULL ) );
    mix_a_deck( deck );                 //перемешиваем колоду
    cout << "\nПеремешанная колода:\n";
    display_deck( deck, SIZE);          // выводим на экран
    split_deck(deck, p1, p2, p3, p4);   // раздаем колоду четырём игрокам
    cout << "\nКолода первого игрока:\n";
    display_deck(p1, SIZE_P);
    cout << "\nКолода второго игрока:\n";
    display_deck(p2, SIZE_P);
    cout << "\nКолода третьего игрока:\n";
    display_deck(p3, SIZE_P);
    cout << "\nКолода четвёртого игрока:\n";
    display_deck(p4, SIZE_P);
    return 0;
}
void mix_a_deck(cards arr[] ){
    for (int j = 0; j < 52; j++)    // перемешиваем колоду
    {
        cards temp;
        int k = rand() % 52;
        temp = arr[ j ];
        arr[ j ] = arr [ k ];
        arr [ k ] = temp;
    }
}

void fill_the_deck(cards arr[] ){
    for (int j = 0; j < 52; j++) // заполняем колоду карт значениями
    {
        int n = j % 13 + 2;
        Suit s = Suit (j / 13);
        arr[ j ].set(n, s);
    }
}

void display_deck( cards arr[], int size ){
    for (int j = 0; j < size; j++) // выводим на экран
    {
        arr[ j ].show_card();
        if ( ((j+1) % 13) == 0)
            cout << endl;
    }
}
void split_deck(cards deck[], cards p1[], cards p2[], cards p3[], cards p4[]){
    cards temp[13];
    int i = 0;
    for (int j = 0; j < 52; j++)
    {
        temp[ i ] = deck [ j ];
        i++;
        if ( i == 13)
        {
            switch ( (j+1) / 13 )
            {
                case 1: part_cpy(p1, temp); break;
                case 2: part_cpy(p2, temp); break;
                case 3: part_cpy(p3, temp); break;
                case 4: part_cpy(p4, temp); break;
            }
            i = 0;
        }
    }
}

void part_cpy(cards p[], cards t[]){
    for (int j = 0; j < 13; j++)
        p[ j ] = t [ j ];
}

void cards::show_card() const {
    if (number < 11)
        cout << number;
    else
        switch ( number )
        {
            case jack: cout << "J"; break;
            case queen: cout << "Q"; break;
            case king: cout << "K"; break;
            case ace: cout << "A"; break;
        }
    switch ( suit )
    {
        case diamonds: cout << "d"; break;
        case clubs: cout << "c"; break;
        case hearts: cout << "h"; break;
        case spades: cout << "s"; break;
    }
    cout << " ";
}

void cards::set(const int& n, const Suit& s) {
    number = n;
    suit = s;
}