// 1405_amax.cpp
#include <iostream>
using namespace std;

template <class aType>
aType amax( aType*, int );

int main()
{
    int arrInt[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    long arrLong[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double arrDub[ 5 ] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    unsigned char arrChar[ 5 ] = { 'a', 'b', '3', 'f' };
    cout << "int: " << amax( arrInt, 10 ) << endl;
    cout << "Long: " << amax( arrLong, 10 ) << endl;
    cout << "Double: " << amax( arrDub, 5 ) << endl;
    cout << "Char: " << amax( arrChar, 4 ) << endl;
    return 0;
}

template <class aType>
aType amax( aType* arr, int size)
{
    return (aType)*(arr + size-1);
}