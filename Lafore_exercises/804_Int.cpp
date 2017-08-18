// 804_Int.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

class Int
{
    private:
        int numb;
    public:
        Int() : numb ( 0 ) {}
        Int( int n ) : numb ( n ) {}
        void set_numb();
        int get_numb() const;
        Int operator+ ( const Int& n2 ) const;
        Int operator- ( const Int& n2 ) const;
        Int operator* ( const Int& n2 ) const;
        Int operator/ ( const Int& n2 ) const;
        void is_in_limit( const int& n1, const int& n2, const char& ch ) const;
};

int main()
{
    Int n1, n2, n3;
    cout << "Введите первое целое число: ";
    n1.set_numb();
    cout << "Введите второе целое число: ";
    n2.set_numb();
    n3 = n1 + n2;
    cout << "n1 + n2 = " << n3.get_numb() << endl;
    n3 = n1 - n2;
    cout << "n1 - n2 = " << n3.get_numb() << endl;
    n3 = n1 * n2;
    cout << "n1 * n2 = " << n3.get_numb() << endl;
    n3 = n1 / n2;
    cout << "n1 / n2 = " << n3.get_numb() << endl;
    return 0;
}

void Int::is_in_limit( const int& n1, const int& n2, const char& ch ) const
{
    long double result;
    long double max = 2147483648;
    long double min = 2147483648;
    switch ( ch )
    {
        case '+': result = static_cast<long double>( n1 ) + n2; break;
        case '-': result = static_cast<long double>( n1 ) - n2; break;
        case '*': result = static_cast<long double>( n1 ) * n2; break;
        case '/': result = static_cast<long double>( n1 ) / n2; break;
        default: cout << "хуйня\n";
    }
    if ( result > max || result < -min )
    {
        cout << "Переполнение." << endl;
        exit(1);
    }
}
void Int::set_numb() {
    cin >> numb;
    cin.clear();
}
int Int::get_numb() const {
    return numb;
}
Int Int::operator+ ( const Int& n2 ) const {
    is_in_limit( numb, n2.numb, '+');
    return Int ( numb + n2.numb );
}
Int Int::operator- ( const Int& n2 ) const {
    is_in_limit( numb, n2.numb, '-');
    return Int ( numb - n2.numb );
}
Int Int::operator* ( const Int& n2 ) const {
    is_in_limit( numb, n2.numb, '*');
    return Int ( numb * n2.numb );
}
Int Int::operator/ ( const Int& n2 ) const {
    is_in_limit( numb, n2.numb, '/');
    return Int ( numb / n2.numb );
}