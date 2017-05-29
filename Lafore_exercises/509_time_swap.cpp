// 509_time_swap.cpp

#include <iostream>
using namespace std;

struct times
{
    int hours, min, sec;
};

void swap(times&, times&);

int main()
{
    times t1, t2;
    char ch = ':';
    cout << "Введите значение времени t1 в виде \"чч:мм:сс\": ";
    cin >> t1.hours >> ch >> t1.min >> ch >> t1.sec;
    cout << "Введите значение времени t1 в виде \"чч:мм:сс\": ";
    cin >> t2.hours >> ch >> t2.min >> ch >> t2.sec;
    swap(t1, t2);
    cout << "t1 = " << t1.hours << ch << t1.min << ch << t1.sec << endl;
    cout << "t2 = " << t2.hours << ch << t2.min << ch << t2.sec << endl;
    return 0;
}

void swap(times& t1, times& t2)
{
    times temp;
    temp = t1;
    t1 = t2;
    t2 = temp;
}