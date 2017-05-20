// 309_gosti.cpp
// Created by stasich on 21.04.17.
//

#include <iostream>
using namespace std;

int main()
{
    int gosti, stul, i;
    long rassadki;
    do {
        cout << "Введите количество гостей: ";
        cin >> gosti;
        cout << "Введите количество стульев: ";
        cin >> stul;
        if (gosti < stul)
            cout << "Число гостей не может быть меньше числа стульев" << endl;
    }while(gosti < stul);
    for (i = 0, rassadki = gosti; i < (stul-1); i++, gosti--)
        rassadki = rassadki * (gosti - 1);
    cout << "Количество вариантов рассадок: " << rassadki << endl;
    return 0;
}
