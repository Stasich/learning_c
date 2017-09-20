// 1204_data.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name[80];
    unsigned long number;
    char ch;
    ofstream  outf( "data.txt" );
    do{
        cout << "Введите имя: "; cin >> name; outf << name << " ";
        cout << "Введите фамилию: "; cin >> name; outf << name << " ";
        cout << "Введите отчество: "; cin >> name; outf << name << " ";
        cout << "Введите номер: "; cin >> number; outf << number;
        cin.ignore( 10, '\n' );
        cout << "Повторить? (y/n): ";
        cin >> ch;
    } while ( ch != 'n' );
    outf.close();
    ifstream inf ( "data.txt" );
    while ( !inf.eof() )
    {
        for ( int j = 0; j < 3; j++ )
        {
            inf >> name;
            cout << name << " ";
        }
        inf >> number;
        cout << number << endl;
    }
    inf.close();
    return 0;
}