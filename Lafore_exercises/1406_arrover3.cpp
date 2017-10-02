// 1406_arrover3.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;
const int LIMIT = 60;

template <class aType>
class Safearray
{
    private:
        aType arr[ LIMIT ];
    public:
        aType& operator[]( int n )
        {
            if ( n < 0 || n >= LIMIT )
                { cout << "\nОшибочный индекс."; exit(1); }
            return arr[ n ];
        }
        void showArray();
};

int main()
{
    Safearray<int> intArr;
    Safearray<char> chArr;
    for ( int j = 0; j < LIMIT; j++ )
        intArr[j] = j;
    cout << "Массив int:\n";
    intArr.showArray();
    for ( int j = 0; j < LIMIT; j++ )
        chArr[j] = j;
    cout << "\n\nМассив char:\n";
    chArr.showArray();
    cout << endl;
    return 0;
}

template <class aType>
void Safearray<aType>::showArray()
{
    for ( int j = 0; j < LIMIT; j++ )
    {
        cout << j << ": " << arr[ j ] << "    ";
        if ( j%6 == 0 && j != 0)
            cout << endl;
    }
}