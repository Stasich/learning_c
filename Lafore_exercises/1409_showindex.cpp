// 1408_arrover_exception.cpp
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
    class Overflow{
        public:
            int n;
            Overflow( int number ) : n (number) {}
    };
    aType& operator[]( int n )
    {
        if ( n < 0 || n >= LIMIT )
            throw Overflow( n );
        return arr[ n ];
    }
    void showArray();
};

int main()
{
    Safearray<int> intArr;
    Safearray<char> chArr;
    char ans;
    int number;
    for ( int j = 0; j < LIMIT; j++ )
        intArr[j] = j;
    for ( int j = 0; j < LIMIT; j++ ) //заполнения массива данными
        chArr[j] = j;
    do{
        cout << "Введите номер элемента массива: ";
        cin >> number;
        try{
            cout << "chArr[" << number << "] = " << chArr[ number ];
        }
        catch ( Safearray<char>::Overflow n )
        {
            cout << "Выход за пределы массива. Вы ввели: " << n.n;
        }
        cout << "\nПовторить?(y/n): ";
        cin >> ans;
    } while ( ans != 'n' );
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