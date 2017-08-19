// 809_safearray.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

const int LIMIT = 100;
class safearray
{
    private:
        int arr[ LIMIT ];
        int top;
        int bot;
    public:
        safearray() : bot( 0 ), top ( LIMIT - 1 )
        {}
        safearray( int b, int t) : bot( b ), top( t )
        {   if ( (top - bot) >= LIMIT ) {
                cout << "Слишком длинный масив\n";
                exit(1);
            }
        }
        void is_in_limit( const int& n );
        int& operator[] ( int n ){
            is_in_limit( n );
            return arr[ n - bot ];
        }
};

int main()
{
    int bot, top;
    cout << "Введите через пробел нижнюю и верхнюю границу массива:";
    cin >> bot >> top;
    safearray arr( bot, top );
    for ( int j = bot; j <= top; j++ )
        arr[ j ] = j * 10;
    for ( int j = bot; j <= top; j++ )
        cout << arr[ j ] << " ";
    cout << endl;
    return 0;

}

void safearray::is_in_limit( const int& n ) {
    if ( n < bot || n > top )
    {
        cout << "неверный индекс\n";
        exit(1);
    }
}