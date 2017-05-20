//306_factor_for.cpp
// Created by stasich on 30.03.17.
//
#include <iostream>
using namespace std;

int main()
{
    unsigned int i, numb = 1;
    unsigned long fact = 1;
    while (numb != 0)
    {
        cout << "Введите целое число для расчёта факториала: ";
        cin >> numb;
        if (numb == 0)
            continue;
        for (i = numb; i > 1; i--) {
            fact *= i;
        }
        cout << "Факториал числа " << numb << " равен " << fact << endl;
    }
    return 0;
}
