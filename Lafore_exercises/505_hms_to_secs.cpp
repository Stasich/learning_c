// 505_hms_to_secs.cpp

#include <iostream>
using namespace std;

long hms_to_secs(int, int, int);

int main()
{
    int hours, min, sec;
    char ch = ':';
    cout << "Для выхода из программы введите время равное 00:00:00." << endl;
    while (!(hours == 0 && min == 0 && sec == 0))
    {
        cout << "Введите время в формате \"чч:мм:сс\" : ";
        cin >> hours >> ch >> min >> ch >> sec;
        cout << "Время в секундах: " << hms_to_secs(hours, min, sec) << endl;
    }
    return 0;
}
long hms_to_secs(int hours, int min, int sec)
{
    return hours * 3600 + min * 60 + sec;
}