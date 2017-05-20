// 303_cin.cpp
// Created by stasich on 19.04.17.
//
#include <iostream>
#include "../listingls/part3/getch_stasich.h"
using namespace std;

int main()
{
    char ch;
    long x = 0;
    cout << "Введите число: ";
    while((ch = getch()) != '\n'){
        cout << ch;
        x = x * 10 + (ch - '0');
    }
    cout << endl << "Вы ввели: " << x << endl;
    return 0;
}
