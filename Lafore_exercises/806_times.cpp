// 806_times.cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
    private:
        int hour, min, sec;
    public:
        Time(): hour ( 0 ), min ( 0 ), sec ( 0 )
        {}
        Time( int h, int m, int s) : hour( h ), min( m ), sec( s )
        {}
        Time( long int total_sec );
        void display() const;
        Time operator- ( const Time& t2 ) const;
        Time operator* ( const Time& t2 ) const;
        Time operator* ( float f ) const;
        Time operator- ( float f ) const;
};

int main()
{
    Time t1( 5, 5, 5); Time t2( 2, 2 ,2); Time t3;
    float fl = 5.5;
    cout << "t1: "; t1.display(); cout << endl;
    cout << "t2: "; t2.display(); cout << endl;
    cout << "t3: "; t3.display(); cout << endl;
    cout << "fl: " << fl << endl;
    t3 = t1 - t2;
    cout << "t1 - t2: "; t3.display(); cout << endl;
    t3 = t1 * t2;
    cout << "t1 * t2: "; t3.display(); cout << endl;
    t3 = t1 * fl;
    cout << "t1 * fl: "; t3.display(); cout << endl;
    t3 = t1 - fl;
    cout << "t1 - fl: "; t3.display(); cout << endl;
}

void Time::display() const {
    cout << hour << ":" << setw(2) << setfill('0') << min << ":"
         << setw(2) << setfill('0') << sec;
}

Time Time::operator- ( const Time& t2 ) const {
    long int totatl_sec = hour * 3600 + min * 60 + sec - t2.hour * 3600 - t2.min * 60 - t2.sec;
    return Time ( totatl_sec );
}

Time Time::operator* ( const Time& t2 ) const {
    long int total_sec = (hour * 3600 + min * 60 + sec) *
                        (t2.hour * 3600 + t2.min * 60 + t2.sec);
    return Time ( total_sec );
}

Time::Time ( long int total_sec ) {
    hour = total_sec / 3600;
    min = (total_sec - hour * 3600) / 60;
    sec = total_sec - hour*3600 - min*60;
}

Time Time::operator* ( float f ) const {
    long int total_sec = (hour * 3600 + min * 60 + sec) * f;
    return Time ( total_sec );
}

Time Time::operator- ( float f ) const {
    long int total_sec = hour * 3600 + min * 60 + sec - f;
    return Time ( total_sec );
}