// 1404_swaps.cpp
#include <iostream>
using namespace std;

template <class aType>
void swaps( aType&, aType& );

int main()
{
    int i1 = 1, i2 = 2;
    float f1 = 1.1, f2 = 2.2;
    char ch1 = 'a', ch2 = 'b';
    swaps( i1, i2 );
    swaps( f1, f2 );
    swaps( ch1, ch2 );
    cout << endl;
    return 0;
}

template <class aType>
void swaps( aType& a1, aType& a2 )
{
    cout << "\nПервый аргумент: " << a1 << " Второй аргумент: " << a2;
    cout << "\nМеняю местами....";
    aType temp;
    temp = a1;
    a1 = a2;
    a2 = temp;
    cout << "\nПервый аргумент: " << a1 << " Второй аргумент: " << a2 << endl;
}