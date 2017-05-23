// 311_funt_kal.cpp
// Created by stasich on 21.04.17.
//
#include <iostream>
#include "getch_stasich.h"
using namespace std;

int main() {
    int funt1 = 0, funt2 = 0, funtSum = 0,
            shil1, shil2, shilSum,
            pens1, pens2, pensSum, k;
    char point = '.', ch, znak = '+';
    cout << "Введите операнд, операцию и  второй операнд: ";
    //заполняем все переменные, жаль что я не знаю массивы... или функции..
    while ((ch = getch()) != '.') {
        cout << ch;
        funt1 = funt1 * 10 + (ch - '0');
    }
    cout << point;
    while ((ch = getch()) != '.') {
        cout << ch;
        shil1 = shil1 * 10 + (ch - '0');
    }
    cout << point;
    while ((ch = getch()) != '.') {
        if (ch == '+' || ch == '-' || ch == '*')
            break;
        cout << ch;
        pens1 = pens1 * 10 + (ch - '0');
    }
    znak = ch;
    cout << znak;
    if (znak == '*')
        cin >> funt2;
    else
    {
        while((ch = getch()) != '.')
        {
            cout << ch;
            funt2 = funt2 * 10 + (ch - '0');
        }
        cout << point;
        while((ch = getch()) != '.')
        {
            cout << ch;
            shil2 = shil2*10 + (ch - '0');
        }
        cout << point;
        cin >> pens2;
    }

    switch(znak)
    {
        case '+':
            if ((pensSum = pens1 + pens2) > 11) {
                pensSum -= 12;
                k = 1;
            } else k = 0;
            if ((shilSum = shil1 + shil2 + k) > 19) {
                shilSum -= 20;
                k = 1;
            } else k = 0;
            funtSum = funt1 + funt2 + k;
            cout << "Сумма равна: J" << funtSum << point << shilSum << point << pensSum << endl;
            break;
        case '-':
            if (pens1 < pens2)
            {
                pensSum = pens1 + 12 - pens2;
                shil1--;
            }
            else
                pensSum = pens1 - pens2;
            if (shil1 < shil2)
            {
                shilSum = shil1 + 20 - shil2;
                funt1--;
            }
            else
                shilSum = shil1 - shil2;
            funtSum = funt1 - funt2;
            cout << "Результат вычитания: J" << funtSum << point << shilSum << point << pensSum << endl;
            break;
        case '*':
            if ((pensSum = pens1 * funt2) > 11) {
                pensSum = pensSum % 12;
                k = pensSum / 12;
            } else {pensSum = pens1 * funt2; k = 0;}
            if ((shilSum = shil1 * funt2 + k) > 19) {
                shilSum = shilSum % 20;
                k = shilSum / 20;
            } else {pensSum = pens1 * funt2; k = 0;}
            funtSum = funt1 * funt2 + k;
            cout << "Произведение равно: J" << funtSum << point << shilSum << point << pensSum << endl;
            break;
        default:
            cout << "Вы ввели не верный знак операции.";
    }
    return 0;
}
