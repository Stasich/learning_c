// 510_count.cpp

#include <iostream>
using namespace std;

int glob;

void counter_global();
void counter_local();

int main()
{
    cout << "С помощью глобальной переменной." << endl;
    for (int i = 0; i<10; i++)
        counter_global();
    cout << "С помощью статической локальной переменной." << endl;
    for (int i = 0; i<10; i++)
        counter_local();
    return 0;
}

void counter_global()
{
    glob++;
    cout << "Я счётчик вызова функции: " << glob << endl;
}

void counter_local()
{
    static int i;
    i++;
    cout << "Я счётчик вызова функции: " << i << endl;
}