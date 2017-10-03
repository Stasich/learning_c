// 1410_englerr.cpp
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int isFeet( string );

class Distance
{
    private:
        int feet;
        float inches;
    public:
        Distance()
            { feet = 0; inches = 0.0; }
        Distance( int ft, float in ) : feet( ft ), inches( in ) {}
        void showdist()
            { cout << feet << "\'-" << inches << "\""; }
    void getdist();
    class Fail{
        public:
        string str;
        int inches;
        Fail( string s ) : str( s )
        {
            cout << str << endl;
            cin.clear();
            cin.ignore( 10, '\n' );
        }
        Fail( string s, float in ) : str( s ), inches( in )
        {
            cout << str << "Вы ввели: " << inches << endl;
            cin.clear();
            cin.ignore( 10, '\n' );
        }
    };
};

int main()
{
    Distance d;
    char ans;
    do
    {
        try
        {
            d.getdist();
            cout << "Расстояние = ";
            d.showdist();
            cout << "\nЕщё раз? (y/n): ";
            cin >> ans;
            cin.ignore( 10, '\n' );
        }
        catch ( Distance::Fail ){}
    } while ( ans != 'n' );
    return 0;
}

void Distance::getdist()
{
    string instr;
    while (true)
    {
        cout << "\nВведите футы: ";
        cin.unsetf(ios::skipws);
        cin >> instr;
        if( isFeet( instr) )
        {
            cin.ignore( 10, '\n' );
            feet = atoi( instr.c_str() );
            break;
        }
        cout << "Футы должны быть целыми. и < 999\n";
    }

    while (true)
    {
        cout << "Введите дюймы: ";
        cin.unsetf(ios::skipws);
        cin >> inches;
        if ( inches >= 12 || inches < 0.0 )
        {
            throw Fail( "Дюймы должны быть между 0.0 и 11.99\n", inches );
        }
        if ( cin.good() )
        {
            cin.ignore( 10, '\n' );
            break;
        }
        throw Fail( "Неверно введены дюймы" );
    }
}

int isFeet( string str )
{
    int slen = str.size();              //получить длину
    if ( slen == 0 )                     //что бы не было слишком много данных
        throw Distance::Fail( "Ничего не введено");
    else if ( slen > 5 )
        throw Distance::Fail( "Слишком длинное число.");
    for ( int j = 0; j < slen; j++ )                                //проверить все элементы
        if ( ( str[j] < '0' || str[j] > '9') && str[j] != '-' )     //если не цифра и не минус
            throw Distance::Fail( "Не правильно введено число. Футы должны быть целыми." ); //строка не правиьлных футов
    int n = atoi( str.c_str() );
    if ( n < -999 || n > 999 )
        throw Distance::Fail( "Футы должны быть > 0 и < 999");
    return 1;
}

