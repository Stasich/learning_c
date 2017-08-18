// 805_time_up.cpp
// 803_time.cpp
// 603_time.cpp modificate

#include <iostream>
#include <iomanip>

using namespace std;

class timew
{
private:
    int hour, min, sec;
public:
    timew() : hour(0), min(0), sec(0)
    {}
    timew(int h, int m, int s) : hour(h), min(m), sec(s)
    {}
    void display() const;
    void sum_time (timew tt1, timew tt2);
    timew operator+ ( const timew& t2 );
    timew operator++ ();
    timew operator++ ( int );
    timew operator-- ();
    timew operator-- ( int );
};

int main()
{
    timew tt1(20, 58, 55); timew tt2(10, 48, 50); timew tt3;
    cout << "t1: "; tt1.display(); cout << endl;
    cout << "t2: "; tt2.display(); cout << endl;
    cout << "t3: "; tt3.display(); cout << endl;
    cout << "Складываю t3 = t1 + t2..." << endl;
    tt3 = tt1 + tt2;
    cout << "t1: "; tt1.display(); cout << endl;
    cout << "t2: "; tt2.display(); cout << endl;
    cout << "t3: "; tt3.display(); cout << endl;
    ++tt3;
    cout << setw(11) << setfill( ' ' ) << setiosflags( ios::left ) << "++t3  " << "t3: "; tt3.display(); cout << endl;
    tt2 = tt3++;
    cout << setw(11) << setfill( ' ' ) << "t2 = t3++  " << "t2: "; tt2.display(); cout << endl;
    cout << setw(11) << setfill( ' ' ) << "  " << "t3: "; tt3.display(); cout << endl;
    --tt3;
    cout << setw(11) << setfill( ' ' ) << "--t3  " << "t3: "; tt3.display(); cout << endl;
    tt2 = tt3--;
    cout << setw(11) << setfill( ' ' ) << "t2 = t3--  " << "t2: "; tt2.display(); cout << endl;
    cout << setw(11) << setfill( ' ' ) << "  " << "t3: "; tt3.display(); cout << endl;
    return 0;
}

timew timew::operator+ ( const timew& t2 )
{
    timew temp( hour, min, sec );
    temp.sum_time( temp , t2);
    return temp;
}

void timew::display() const {
    cout << hour << ":" << setw(2) << setfill('0') << min << ":"
         << setw(2) << setfill('0') << sec;
}

void timew::sum_time(timew tt1, timew tt2) {
    unsigned int total_sec;
    total_sec = tt1.hour * 3600 + tt1.min * 60 + tt1.sec +
                tt2.hour * 3600 + tt2.min * 60 + tt2.sec;
    hour = total_sec / 3600;
    min = (total_sec - hour * 3600) / 60;
    sec = total_sec - hour*3600 - min*60;
}

timew timew::operator++ (){
    return timew ( hour, min, ++sec );
}
timew timew::operator++ ( int ){
    return timew ( hour, min, sec++ );
}
timew timew::operator-- (){
    return timew ( hour, min, --sec );
}
timew timew::operator-- ( int ){
    return timew ( hour, min, sec-- );
}