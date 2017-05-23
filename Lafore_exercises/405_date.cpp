// 405_date.cpp

#include <iostream>
using namespace std;

struct date
{
    int day, month, year;
};

int main()
{
    date d1;
    char ch = '/';

    cout << "Введите дату в формате xx/xx/xxxx: ";
    cin >> d1.day >> ch >> d1.month >> ch >> d1.year;
    cout << "Вы ввели: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
    return 0;
}