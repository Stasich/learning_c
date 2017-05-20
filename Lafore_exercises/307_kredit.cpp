// 307_kredit.cpp
// Created by stasich on 20.04.17.
//
#include <iostream>
using namespace std;

int main()
{
    float vklad, stavka;
    int srok, i;
    cout << "Введите начальный вклад: "; cin >> vklad;
    cout << "Введите число лет: "; cin >> srok;
    cout << "Введите процентную ставку: "; cin >> stavka;
    for (i = 0; i < srok; i++)
        vklad = vklad + vklad*stavka/100;
    cout << "По окончании срока у Вас будет: " << vklad << endl;
    return 0;
}
