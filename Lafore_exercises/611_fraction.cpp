// 611_fraction.cpp

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
    fraction ff1, ff2, rez;
    char znak, ch;
    cout << "Введите выражение в виде 1/3+2/4: ";
    ff1.set_data(); cin >> znak; ff2.set_data();
    switch(znak){
        case '+': rez.add(ff1,ff2); rez.lowterms(); break;
        case '-': rez.sub(ff1,ff2); rez.lowterms(); break;
        case '*': rez.mul(ff1,ff2); rez.lowterms(); break;
        case '/': rez.div(ff1,ff2); rez.lowterms() ;break;
    }
    ff1.show_data(); cout << znak; ff2.show_data();
    cout << " = "; rez.show_data();
    cout << endl;
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