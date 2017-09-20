// 1201_diskfun.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Distance
{
    private:
        int feet;
        float inches;
    public:
        Distance(): feet( 0 ), inches( 0.0 ) {}
        Distance( int f, float in ): feet ( f ), inches ( in ) {}
        void getDist();
        void showDist();
};

int main()
{
    char ch;
    Distance d1;
    ofstream outFile;
    ifstream inFile;
    outFile.open ( "Dist.dat", ios::binary | ios::app );
    do{
        d1.getDist();
        outFile.write( reinterpret_cast<char*>( &d1 ), sizeof( Distance ) );
        cout << "Ещё? (y/n): ";
        cin >> ch;
        cin.ignore( 10, '\n' );
    } while ( ch != 'n' );
    outFile.close();
    inFile.open ( "Dist.dat", ios::binary );
    while (true)
    {
        inFile.read( reinterpret_cast<char*>( &d1 ), sizeof( Distance ) );
        if ( inFile.eof() )
            break;
        d1.showDist();
        cout << endl;
    }
    return 0;
}

void Distance::getDist() {
    cin.unsetf( ios::skipws );                  // отключил пропуск пробело при вводе
    while (true)                                // пока не будет введено число
    {
        cout << "Введите футы: "; cin >> feet;
        if ( cin.good() ){
            cin.ignore( 10, '\n' );
            break;
        }
        cin.clear();
        cin.ignore( 10, '\n' );
    }
    while (true)
    {
        cout << "Введите дюймы: "; cin >> inches;
        if ( cin.good() ){
            cin.ignore( 10, '\n' );
            break;
        }
        cin.clear();
        cin.ignore( 10, '\n' );
    }
}

void Distance::showDist() {
    cout << feet << "\'-" << inches << "\"";
}