// 409_time.cpp

#include <iostream>
using namespace std;

struct times
{
    int hours, minutes, seconds;
};

int main()
{
    times t1;
    unsigned long totalsecs;
    char ch = ':';
    cout << "Введите время в формате чч:мм:сс : ";
    cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
    totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    cout << "Время в секундах: " << totalsecs << endl;
    return 0;
}