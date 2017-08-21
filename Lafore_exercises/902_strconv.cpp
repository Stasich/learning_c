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
    { str[0] = '\0'; cout << "ска";}
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

int main()
{
    Pstring s1 = "This is very very long str. Ok my name is Stas and it is my program for education";
    cout << "Дллинная строка: "; s1.display();
    Pstring s2 = "This is short";
    cout << "Короткая строка: "; s2.display(); cout << endl;
    return 0;
}

void String::display() const {
    cout << str << endl;
}
String::operator char*() {
    return str;
}

/*Pstring::Pstring( const char s1[] )
{
    if ( strlen( s1 ) > (MAX - 1) )
    {
        int j = 0;
        for ( j ; j < MAX -1; j++ )
            str[ j ] = s1 [ j ];
        str [ j ] = '\0';
    }
    else
        String(s1);
}*/