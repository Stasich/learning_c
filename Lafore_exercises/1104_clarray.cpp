//  1104_clarray.cpp
#include <iostream>
using namespace std;

class Array {
    private:
        int* ptr;
        int size;
    public:
        Array() : size ( 0 ), ptr ( 0 ) {}
        Array( int );
        Array( Array& );
        Array& operator= ( Array& );
        int& operator[] ( int );
        ~Array();
};

int main()
{
    Array a1( 10 ), a2( 7 ), a3;
    for ( int j = 0; j < 10; j++ )
        a1[ j ] = j*j;
    for ( int j = 0; j < 10; j++ )
        cout << a1[ j ] << " ";
    cout << endl;
    Array a4( a1 );                 //конструктор копирования
    for ( int j = 0; j < 10; j++ )
        cout << a4[ j ] << " ";
    cout << endl;
    a3 = a2 = a1;                   //оператор присваивания
    for ( int j = 0; j < 10; j++ )
        cout << a3[ j ] << " ";
    cout << endl;
    return 0;
}

Array::Array( int s ) {
    ptr = new int [ s ];
    size =  s;
}
Array::Array( Array& a ) {
    size = a.size;
    ptr = new int [ size ];
    for ( int j = 0; j < size; j++ )
        *(ptr + j) = *(a.ptr + j);
}
int& Array::operator[] ( int n ) {
    return *( ptr + n );
}

Array& Array::operator= ( Array& a ) {
    delete [] ptr;
    size = a.size;
    ptr = new int [ size ];
    for ( int j = 0; j < size; j++ )
        *(ptr + j) = *(a.ptr + j);
    return *this;
}
Array::~Array() {
    delete [] ptr;
}