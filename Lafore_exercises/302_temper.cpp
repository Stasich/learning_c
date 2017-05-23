// 302_temper.cpp
// Created by stasich on 15.04.17.
//
#include <iostream>
#include "getch_stasich.h"
using namespace std;

int main()
{
    char n;
    float temp;
    cout << "Нажмите \"1\" для перевода шкалы Цельсия в шкалу Фаренгейта.\n"
         << "Нажмите \"2\" для перевода шкалы Фаренгейта в шкалу цельсия: ";
    n = getch();
    cout << n << endl;
    cout << "Введите значение: ";
    cin >> temp;
    switch(n)
    {
        case '1':
            cout << "Значение по Фаренгейту: " << (temp*1.8)+32 << endl;
            break;
        case '2':
            cout << "Значение по Цельсию: " << (temp-32)/1.8 << endl;
            break;
    }
    return 0;
}
