// 1401_average.cpp
#include <iostream>
using namespace std;

template <class T>
T average( T* arr, int size );

int main()
{
    int arrInt[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    long arrLong[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double arrDub[ 5 ] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    unsigned char arrChar[ 5 ] = { '3', '3', '3', '3' };
    cout << "int: " << average( arrInt, 10 ) << endl;
    cout << "Long: " << average( arrLong, 10 ) << endl;
    cout << "Double: " << average( arrDub, 5 ) << endl;
    cout << "Char: " << average( arrChar, 3 ) << endl;
    return 0;
}

template <class T>
T average( T* arr, int  size )
{
    T sum = 0;
    for ( int j = 0; j < size; j++ )
        sum += *( arr + j );
    return (T)sum/size;
}