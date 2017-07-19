// 705_fraction.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

class fraction
{
private:
    int up, down;
public:
    fraction() : up(0), down(1) {}
    fraction( int u, int d ) : up(u), down(d) {}
    void get_data();
    void add( fraction );
    void lowterms();
    void show_data() const;
    void div_numb(const int&);
};

int main()
{
    int SIZE = 100;
    fraction fr[ SIZE ], aver;
    int count = 0; //количество введённых дробей.
    char ch;
    do{
        fr[count++].get_data();
        cout << "Продолжить?(y/n):";
        cin >> ch;
    } while(ch != 'n' && count < SIZE);
    for (int j = 0; j < count; j++)    //вычисляем сумму всех введённых дробей
    {
        aver.add( fr[ j ]);
        aver.lowterms();               // на каждом этапе сокращаем дробь
    }
    aver.div_numb( count );            // вычисляем среднее значение
    aver.lowterms();
    cout << "Cреднее начение введённых дробей:";
    aver.show_data();
    cout << endl;
    return 0;
}

void fraction::get_data() {
    char ch = '/';
    cout << "Введите дробь в виде a/b : ";
    cin >> up >> ch >> down;
}
void fraction::add( fraction f) {
    up = up * f.down + f.up * down;
    down *= f.down;
}
void fraction::lowterms() {
    long tup, tdown, temp, gcd;
    tup = labs(up);
    tdown = labs(down);
    if (tup == 0)
    {up = 0; down = 1; return;}
    while(tup != 0)
    {
        if ( tup < tdown )
        { temp = tup; tup = tdown; tdown = temp;}
        tup = tup - tdown;
    }
    gcd = tdown;
    up = up/gcd;
    down = down/gcd;
}
void fraction::show_data() const {
    cout << up << "/" << down;
}

void fraction::div_numb(const int& count) {
    down *= count;
}