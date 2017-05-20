// 308_funt_sum.cpp
// Created by stasich on 20.04.17.
//
#include <iostream>
using namespace std;

int main()
{
    int funt1, funt2, funtSum,
        shil1, shil2, shilSum,
        pens1, pens2, pensSum, k;
    char point = '.', ch;
    do {
        cout << "Введите первую сумму: J";
        cin >> funt1 >> point >> shil1 >> point >> pens1;
        cout << "Введите вторую сумму: J";
        cin >> funt2 >> point >> shil2 >> point >> pens2;
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
        cout << "Ещё раз? (y/n): "; cin >> ch;
    }while(ch != 'n');
     return 0;
}
