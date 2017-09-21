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
        static fstream file;
    public:
        static void open_file();
        static void seekg_beg();
        void get_data();
        void show_data();
        void show_data( int );
};
fstream name::file;

int main()
{
    name n1;
    int n;
    char ch;
    name::open_file();
    do {
        n1.get_data();
        cout << "Повторить? (y/n):";
        cin >> ch;
        cin.ignore( 10, '\n' );
    } while ( ch!= 'n' );
    cout << "Введите номер человека: ";
    cin >> n;
    name::seekg_beg();
    n1.show_data( n );
    cout << endl;
    n1.show_data();
    return 0;
}

void name::get_data() {
    cout << "Введите имя: "; cin >> name; file << name << " ";
    cout << "Введите фамилию: "; cin >> surname; file << surname << " ";
    cout << "Введите отчество: "; cin >> patron; file << patron << " ";
    cout << "Введите номер: "; cin >> number; file << number;
    cin.ignore( 10, '\n' );
}

void name::show_data( int n ) {
    for ( int j = 0; j < n; j++ )
    {
        file >> name >> surname >> patron >> number;

        if ( file.eof() )
            break;
    }
    cout << "Выбранный человек: \n";
    cout << name << " " << surname << " " << patron << " " << number;
}

void name::show_data() {
    name::seekg_beg();
    cout << "Весь список: \n";
    while ( true )
    {
        file >> name >> surname >> patron >> number;
        cout << name << " " << surname << " " << patron << " " << number << endl;
        if ( file.eof() )
            break;
    }
}

void name::open_file() {
    file.open ( "name.txt", ios::in | ios::out | ios::app );
}

void name::seekg_beg() {
    file.seekg( 0, ios::beg );
}