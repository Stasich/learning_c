// 310_let_vo_vklad.cpp
// Created by stasich on 21.04.17.
//
#include <iostream>
using namespace std;

int main()
{
    float vklad, stavka, sum;
    int srok = 0, i;
    cout << "Введите начальный вклад: "; cin >> vklad;
    /*cout << "Введите число лет: "; cin >> srok;*/
    cout << "Введите процентную ставку: "; cin >> stavka;
    cout << "Введите желаемую сумму: "; cin >> sum;
    while (vklad < sum)
    {
        vklad = vklad + vklad * stavka / 100;
        srok++;
    }
    cout << "Количество лет для достижения указанной суммы: " << srok << endl <<
         "Сумма на счёте будет: " << vklad << endl;
    return 0;
}
