// 701_revers.cpp
#include <iostream>
#include <cstring>
using namespace std;

void reversit( wchar_t[] );

int main()
{
    locale::global( locale( "" ) );
    //ios::sync_with_stdio( false );

    const int MAX = 80;
    wchar_t str[MAX];
    wcout << L"Введите строку: ";
    wcin.get(str, MAX);
    reversit( str );
    wcout << L"Перевернутая строка: " << str << endl;
    return 0;
}

void reversit( wchar_t arr[] )
{
    wchar_t temp;
    int lenght = wcslen(arr);
    for (int j = 0; j < lenght/2; j++)
    {
        temp = arr[ j ];
        arr[ j ] = arr[ (lenght-1) - j ];
        arr[ (lenght-1) - j ] = temp;
    }
}