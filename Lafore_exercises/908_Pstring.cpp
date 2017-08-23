// strconv.cpp
#include <iostream>
#include <string.h>
//#include <string>
using namespace std;

class String
{
    protected:
        static const int MAX = 80;
        char str [ MAX ];
    public:
        String()
        { str[0] = '\0';}
        String( const char s [] )
        { strcpy ( str, s ); }
        String( char s [] )
        { strcpy ( str, s ); }
        void display() const;
        operator char* ();
};
class Pstring : public String
{
    public:
        Pstring() : String() {}
        Pstring( const char s[] )
        {
            if ( strlen( s ) > MAX - 1 )
            {
                int j = 0;
                for ( j ; j < MAX -1; j++ )
                    str[ j ] = s [ j ];
                str [ j ] = '\0';
            }
            else
                strcpy( str, s );
        }
};

class Pstring2 : public Pstring
{
    public:
        Pstring2() : Pstring() {}
        Pstring2 ( const char s[] ) : Pstring ( s ) {}
        char& operator[] ( int n )
            { return str [ n ]; }
        void left ( Pstring2& p2, int n );
        void mid ( Pstring2& p2, int s, int n );
        void right ( Pstring2& p2, int n );
        //int strlen2 ( Pstring2 p2 )
        //{ return strlen (p2.str); }

};

int main()
{
    Pstring2 s1 = "This is very very long str. It is my program for education";
    Pstring2 s2, s3;
    s2.left( s1, 6 );
    cout << s2 << endl;
    s2.mid( s1, 6, 7 );
    cout << s2 << endl;
    s3.right( s1, 9 );
    cout << s3 << endl;
    return 0;
}

void String::display() const {
    cout << str << endl;
}
String::operator char*() {
    return str;
}

void Pstring2::left( Pstring2 &p2, int n) {
    int j;
    for ( j = 0; j < n; j++ )
        str [ j ] = p2[ j ];
    str [ j ] = '\0';
}

void Pstring2::mid( Pstring2& p2, int s, int n ) {
    int j, i;
    for ( i = 0, j = s - 1; j < s + n; j++, i++ )
        str [ i ] = p2[ j ];
    str [ i ] = '\0';
}

void Pstring2::right (Pstring2& p2, int n ) {
    int j, i;
    for ( i = 0, j = strlen(p2.str) - n; j < strlen(p2.str); j++, i++ )
        str [ i ] = p2 [ j ];
    str [ i ] = '\0';
}