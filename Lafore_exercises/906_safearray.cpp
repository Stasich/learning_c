// 906_safearray.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

class array {
    protected:
        static const int LIMIT = 10;
        int arr[ LIMIT ];
    public:
        int& operator[]( int n )
        {
            return arr [ n ];
        }
};
class safearray : public array
{
    private:
        int top;
        int bot;
    public:
        safearray(): bot ( 0 ), top ( LIMIT ) {}
        safearray( const int& b, const int& t );
        int& operator[]( const int& n);
        void is_in_limit( const int& n ) const;
};

int main()
{
    int bot, top;
    cout << "Введите границы массива через пробел: ";
    cin >> bot >> top;
    safearray s1( bot, top );
    for ( int j = bot; j < top; j++ )
    {
        cout << "Введите значение " << j << " элемента: ";
        cin >> s1[ j ];
    }
    for ( int j = bot; j < top; j++ )
        cout << s1[ j ] << " ";
    cout << endl;
    cout << "Введите номер эелмента, что бы получить его значение: ";
    cin >> bot;
    cout << s1[ bot ] << endl;
    return 0;
}

safearray::safearray(const int &b, const int &t) {
    if ( t - b >=  LIMIT)
        {cout << "Вы задали слишком большой размер массива" << endl; exit(1);}
    bot = b;
    top = t;
}
void safearray::is_in_limit(const int &n) const {
    if ( n < bot || n > top -1 )
        {cout << "Выход за пределы массива." << endl; exit(1);}
}

int& safearray::operator[]( const int &n ) {
    is_in_limit( n );
    return arr [ n - bot ];
}