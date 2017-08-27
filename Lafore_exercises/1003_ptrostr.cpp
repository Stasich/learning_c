// 1003_ptrostr.cpp

#include <iostream>
#include <string.h>
using namespace std;

void bsort ( char** pp, int size );
int main()
{
    const int size = 7;
    char* days [ size ] = {(char *) "Monday", (char *) "Tuesday",
                           (char *) "Wednesday", (char *) "Thursday", (char *) "Friday",
                           (char *) "Saturday", (char *) "Sunday"};
    bsort( days, size );
    for ( int i = 0; i < size; i++ )
        cout << *(days + i) << endl;
    cout << endl;
}

void bsort ( char** pp, int size )
{
    void order ( char** p1, char** p2 );
        for ( int j = 0; j < size - 1; j++ )
            for ( int k = j+1; k < size; k++ )
                order( pp + j , pp + k );
}

void order ( char** p1, char** p2 ) {
    if ( **p1 > **p2 )
    {
         char* temp = *p2;
        *p2 = *p1;
        *p1 = temp;
    }
}