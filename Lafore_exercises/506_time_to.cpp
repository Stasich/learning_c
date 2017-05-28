// 506_time_to.cpp

#include <iostream>
#include <iomanip>
using namespace std;

struct times
{
    int hours, minutes, seconds;
};

unsigned long time_to_sec(times);
times sec_to_time(unsigned long);

int main()
{
    times t1, t2, t_sum;
    unsigned long totalsecs_sum;
    char ch = ':';
    cout << "Ввидите первое значение времени в формате \"чч:мм:сс\" : ";
    cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
    cout << "Ввидите второе значение времени в формате \"чч:мм:сс\" : ";
    cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
    totalsecs_sum = time_to_sec(t1) + time_to_sec(t2);
    t_sum = sec_to_time(totalsecs_sum);
    cout << "Сумма времени: " << setw(2) << setfill('0') << t_sum.hours << ch
         << setw(2) << setfill('0') << t_sum.minutes << ch
         << setw(2) << setfill('0') << t_sum.seconds << endl;
    return 0;
}

unsigned long time_to_sec(times tt)
{
    return tt.hours * 3600 + tt.minutes * 60 + tt.seconds;
}

times sec_to_time(unsigned long total_sec)
{
    times tt;
    tt.hours = total_sec / 3600;
    tt.minutes = total_sec % 3600 / 60;
    tt.seconds = total_sec % 3600 % 60;
    return tt;
}