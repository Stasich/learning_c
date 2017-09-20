// 1205_time.cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    private:
        int hour, min, sec;
        int get_int();
        void get_hour();
        void get_min();
        void get_sec();
    public:
        Time(): hour ( 0 ), min ( 0 ), sec ( 0 ) {}
        void get_time();
        void put_time();
};
/////////////////////////////////////////////////////////
int main()
{
    Time t1;
    t1.get_time();
    t1.put_time();
    cout << endl;
    return 0;
}
/////////////////////////////////////////////////////////
void Time::get_time() {
    get_hour();
    get_min();
    get_sec();
}

void Time::get_hour() {
    while (true ){
        cout << "Введите часы: ";
        hour = get_int();
        if ( hour < 0 || hour > 24)
        {
            cout << "Часы не доджны быть меньше 0 и больше 24.\n";
            continue;
        }
        break;
    }
}

void Time::get_min() {
    while (true ){
        cout << "Введите минуты: ";
        min = get_int();
        if ( min < 0 || min > 59)
        {
            cout << "Минуты не доджны быть меньше 0 и больше 59.\n";
            continue;
        }
        break;
    }
}

void Time::get_sec() {
    while (true ){
        cout << "Введите секунды: ";
        sec = get_int();
        if ( sec < 0 || sec > 59)
        {
            cout << "Секунды не доджны быть меньше 0 и больше 59.\n";
            continue;
        }
        break;
    }
}

int Time::get_int(){
    cin.unsetf( ios::skipws );
    int n;
    while ( true )
    {
        cin >> n;
        if ( cin.good() )
        {
            cin.clear();
            cin.ignore( 10, '\n' );
            break;
        }
        cout << "Ошибка. Только целые числа. Повторите ввод: ";
        cin.clear();
        cin.ignore( 10, '\n' );
    }
    return n;
}

void Time::put_time() {
    cout << setw( 2 ) << setfill( '0' ) << hour << ":"
         << setw( 2 ) << setfill( '0' ) << min << ":"
         << setw( 2 ) << setfill( '0' ) << sec;
}