// 410_times.cpp

#include <iostream>
#include <iomanip>
using namespace std;

struct times
{
    int hours, minutes, seconds;
};

int main()
{
    times t1, t2, t_sum;
    unsigned long totalsecs_sum;
    char ch = ':';
    cout << "Ввидите первое значение времени в формате чч:мм:сс : ";
    cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
    cout << "Ввидите второе значение времени в формате чч:мм:сс : ";
    cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
    totalsecs_sum = t1.hours * 3600 + t1.minutes * 60 + t1.seconds
              + t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    t_sum.hours = totalsecs_sum / 3600;
    t_sum.minutes = totalsecs_sum % 3600 / 60;
    t_sum.seconds = totalsecs_sum % 3600 % 60;
    cout << "Сумма времени: " << setw(2) << setfill('0') << t_sum.hours << ch
         << setw(2) << setfill('0') << t_sum.minutes << ch
         << setw(2) << setfill('0') << t_sum.seconds << endl;
    return 0;
}