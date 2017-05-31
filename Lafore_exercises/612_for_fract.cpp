// 612_for_fract.cpp

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class fraction {
private:
    int up, down;
public:
    fraction(): up(0), down(1) {}
    fraction(int x, int y) : up(x), down(y) {}
    void set_data();
    void show_data()const;
    void add(fraction, fraction);
    void sub(fraction, fraction);
    void mul(fraction, fraction);
    void div(fraction, fraction);
    void lowterms();
};

int main()
{
    int down;
    cout << "Введите целое число: ";
    cin >> down;
    for (int i=1; i<down; i++)
    {
        fraction f1(i, down);
        f1.lowterms();
        f1.show_data();
    }
    cout << endl;
    for (int i = 0; i < 45; i++)
        cout << "=";
    cout << endl;
    for (int i=1; i<down; i++)
    {
        fraction f1(i, down);
        f1.lowterms();
        f1.show_data();
        for (int j = 1; j < down; j++)
        {
            fraction f2(j,down);
            f2.mul(f1,f2);
            f2.lowterms();
            f2.show_data();
        }
        cout << endl;
    }
    return 0;
}

void fraction::set_data() {
    char slesh = '/';
    cin >> up >> slesh >> down;
    if (down == 0)
    {cout << "Недопустимый знаменатель!" << endl; exit(1);}
}

void fraction::show_data() const {
    if (labs(up) == labs(down))
    {
        if (up > 0)
            cout << 1;
        else
            cout << -1;
    }
    else
        cout << up << "/" << down;
}

void fraction::add(fraction f1, fraction f2) {
    up = (f1.up * f2.down + f1.down * f2.up);
    down = (f1.down * f2.down);
}
void fraction::sub(fraction f1, fraction f2) {
    up = (f1.up * f2.down - f1.down * f2.up);
    down = (f1.down * f2.down);
}
void fraction::mul(fraction f1, fraction f2) {
    up = f1.up * f2.up;
    down = f1.down * f2.down;
}
void fraction::div(fraction f1, fraction f2) {
    up = f1.up * f2.down;
    down = f1.down * f2.up;
}
void fraction::lowterms() {
    long tup, tdown, temp, gcd;
    tup = labs(up);
    tdown = labs(down);
    if (tup == 0)
    {up = 0; down = 1; return;}
    while(tup != 0)
    {
        if (tup < tdown)
        { temp = tup; tup = tdown; tdown = temp;}
        tup = tup - tdown;
    }
    gcd = tdown;
    up = up/gcd;
    down = down/gcd;
}