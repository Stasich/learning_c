// 807_fraction.cpp

// 611_fraction.cpp modificated

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class fraction {
private:
    int up, down;
public:
    fraction(): up(0), down(1) {}
    fraction(int u, int d) : up( u ), down( d ) {}
    void set_data();
    void show_data()const;
    fraction operator+ ( const fraction& f2 ) const;
    fraction operator- ( const fraction& f2 ) const;
    fraction operator* ( const fraction& f2 ) const;
    fraction operator/ ( const fraction& f2 ) const;
    void lowterms();
};

int main()
{
    fraction f1, f2, rez;
    char znak, ch;
    cout << "Введите выражение в виде 1/3+2/4: ";
    f1.set_data(); cin >> znak; f2.set_data();
    switch(znak){
        case '+': rez = f1 + f2; rez.lowterms(); break;
        case '-': rez = f1 - f2; rez.lowterms(); break;
        case '*': rez = f1 * f2; rez.lowterms(); break;
        case '/': rez = f1 / f2; rez.lowterms() ;break;
    }
    f1.show_data(); cout << " " << znak << " "; f2.show_data();
    cout << " = "; rez.show_data();
    cout << endl;
    return 0;
}

void fraction::set_data() {
    char slesh = '/';
    cin >> up >> slesh >> down;
    if ( up == 0 || down == 0)
    {cout << "Ошибка, один из аргументов равен 0!" << endl; exit(1);}
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

fraction fraction::operator+ ( const fraction& f2 ) const {
    fraction temp;
    temp.up = ( up * f2.down + down * f2.up );
    temp.down = ( down * f2.down );
    return temp;
}
fraction fraction::operator- ( const fraction& f2 ) const {
    fraction temp;
    temp.up = ( up * f2.down - down * f2.up );
    temp.down = ( down * f2.down );
    return temp;
}
fraction fraction::operator* ( const fraction& f2 ) const {
    fraction temp;
    temp.up = up * f2.up;
    temp.down = down * f2.down;
    return temp;
}
fraction fraction::operator/ ( const fraction& f2 ) const {
    fraction temp;
    temp.up = up * f2.down;
    temp.down = down * f2.up;
    return temp;
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