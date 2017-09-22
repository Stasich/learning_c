// 807_fraction.cpp

// 611_fraction.cpp modificated

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
using namespace std;

class fraction {
    private:
        int up, down;
    public:
        fraction(): up(0), down(1) {}
        fraction(int u, int d) : up( u ), down( d ) {}

        fraction operator+ ( const fraction& f2 ) const;
        fraction operator- ( const fraction& f2 ) const;
        fraction operator* ( const fraction& f2 ) const;
        fraction operator/ ( const fraction& f2 ) const;
        friend istream& operator>> ( istream& s, fraction& f );
        friend ostream& operator<< ( ostream& s, fraction& f );
        void lowterms();
};

int main()
{
    fraction f1, f2, rez;
    char znak, ch;
    cout << "Введите выражение в виде 1/3+2/4: ";
    cin >> f1 >> znak >> f2;
    switch(znak){
        case '+': rez = f1 + f2; rez.lowterms(); break;
        case '-': rez = f1 - f2; rez.lowterms(); break;
        case '*': rez = f1 * f2; rez.lowterms(); break;
        case '/': rez = f1 / f2; rez.lowterms() ;break;
    }
    cout << f1 << " " << znak << " " << f2 << " = " << rez << endl;
    return 0;
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

istream& operator>> ( istream& s, fraction& f )
{
    char slesh = '/';
    s >> f.up >> slesh >> f.down;
    if ( f.up == 0 || f.down == 0)
    {cout << "Ошибка, один из аргументов равен 0!" << endl; exit(1);}
    return s;
}

ostream& operator<< ( ostream& s, fraction& f )
{
    if ( labs( f.up ) == labs( f.down) )
    {
        if ( (f.up > 0 && f.down > 0) || ( f.up < 0 && f.down < 0 ) )
            s << 1;
        else
            s << -1;
    }
    else
        s << f.up << "/" << f.down;
    return s;
}