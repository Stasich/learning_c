// 1206_name.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class name
{
    private:
        string name, surname, patron;
        unsigned long number;
    public:
        void get_data();
        void show_data();
        void show_data( int );
};

int main()
{
    name n1;
    int n;
    char ch;
    do {
        n1.get_data();
        cout << "Повторить? (y/n):";
        cin >> ch;
        cin.ignore( 10, '\n' );
    } while ( ch!= 'n' );
    cout << "Введите номер человека: ";
    cin >> n;
    n1.show_data( n );
    cout << endl;
    n1.show_data();
    return 0;
}

void name::get_data() {
    ofstream outf ( "name.txt", ios::app );
    cout << "Введите имя: "; cin >> name; outf << name << " ";
    cout << "Введите фамилию: "; cin >> surname; outf << surname << " ";
    cout << "Введите отчество: "; cin >> patron; outf << patron << " ";
    cout << "Введите номер: "; cin >> number; outf << number;
    cin.ignore( 10, '\n' );
    outf.close();
}

void name::show_data( int n ) {
    ifstream inf ( "name.txt" );
    for ( int j = 0; j < n; j++ )
    {
        inf >> name >> surname >> patron >> number;

        if ( inf.eof() )
            break;
    }
    cout << "Выбранный человек: \n";
    cout << name << " " << surname << " " << patron << " " << number;
}

void name::show_data() {
    ifstream inf ( "name.txt" );
    cout << "Весь список: \n";
    while ( true )
    {
        inf >> name >> surname >> patron >> number;
        cout << name << " " << surname << " " << patron << " " << number << endl;
        if ( inf.eof() )
            break;
    }
}