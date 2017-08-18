// 802_strplus.cpp
// strplus.cpp modoficate
#include <iostream>
#include <string.h> // for strcpy, strcat
#include <stdlib.h> // for exit()
using namespace std;

class String
{
private:
    static const int MAX = 80;
    char str [ MAX ];
public:
    String()
    { strcpy ( str, "" ); }
    String( const char s [] )
    { strcpy ( str, s ); }
    String( char s [] )
    { strcpy ( str, s ); }
    String operator+ ( String s2 ) const;
    String operator+= ( const String&  s2 );
    void display() const
    { cout << str << endl; }
    void get_str();
};

int main()
{
    String s1, s2, s3;
    s1.get_str();
    s2.get_str();
    s1 += s2;
    cout << "s1 += s2 - ";
    s1.display();
    s3 = s1 += s2;
    cout << "s3 = s1 += s2 - ";
    s3.display();
    return 0;
}

String String::operator+ ( String s2 ) const {
    String temp;
    if ( strlen( str ) + strlen( s2.str ) < MAX )
    {
        strcpy ( temp.str, str );
        strcat (temp.str, s2.str );
        return temp;
    }
    else
    {
        cout << "Переполнение" << cout;
        exit(1);
    }
}

void String::get_str() {
    cout << "Введите строку: ";
    cin.get ( str, MAX );
    cin.get();
}

String String::operator+= ( const String& s2) {
    if ( strlen ( str ) + strlen ( s2.str ) < MAX )
    {
        strcat ( str, s2.str );
        return String ( str );
    }
    else
        return String ( "Слишком длинная строка" );
}