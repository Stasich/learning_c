// 1002_newstr.cpp
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String
{
    private:
        char* str;
    public:
        String ( char* s )
        {
            int length = strlen ( s );
            str = new char [ length + 1 ];
            strcpy ( str, s );
        }
        ~String()
        {
            cout << "Удаляем строку" << endl;
            delete [] str;
        }
        void display()
            { cout << str << endl; }
        void upit();
};

int main()
{

    char str[] = "Test for upper";
    String s1 = str;
    cout << "s1 = ";
    s1.display();
    s1.upit();
    cout << "s1 = ";
    s1.display();
    return 0;
}

void String::upit() {
    int len = strlen ( str );
    for ( int j = 0; j < len; j++ )
    {
        *( str + j ) = toupper ( *(str + j) );
    }
}