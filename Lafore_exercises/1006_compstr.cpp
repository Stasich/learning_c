// 1006_compstr.cpp
#include <iostream>
#include <string.h>
using namespace std;
const int SZ = 80;

int compstr( char*, char* );
int order ( char*, char* );

int main()
{
    char str1[ SZ ], str2[ SZ ];
    cout << "Введите первую строку: ";
    cin.get ( str1, SZ); cin.get();
    cout << "Введите первую строку: ";
    cin.get ( str2, SZ); cin.get();
    cout << str1 << "||" << str2 << endl;
    cout << compstr( str1, str2 );
    cout << endl;
    return 0;
}

int compstr( char* s1, char* s2 )
{
    int n = 0, j = 0;
    while ( n == 0 && *(s1+j) != '\0' && *(s2+j) != '\0' && j < SZ){
        n = order( (s1+j) , (s2+j) );
        j++;
    }
    return n;
}

int order ( char* s1, char* s2 ) {
    if ( *(s1) < *(s2) )
        return -1;
    else if ( *(s1) > *(s2) )
        return 1;
    else
        return 0;
}
