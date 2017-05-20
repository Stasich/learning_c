// 304_kalk.cpp
// Created by stasich on 19.04.17.
//

#include <iostream>
using namespace std;

int main()
{
    float a, b, rez;
    char znak = '/', ch;
    while (ch != 'n')
    {
        cout << "Введите выражение: ";
        cin >> a >> znak >> b;
        switch (znak) {
            case '+': rez = a + b; cout << rez << endl; break;
            case '-': rez = a - b; cout << rez << endl; break;
            case '*': rez = a * b; cout << rez << endl; break;
            case '/': rez = a / b; cout << rez << endl; break;
            default:
                cout << "Вы ввели не верный знак операции.";
        }
        cout << "Попробовать ещё раз? (y/n): ";
        cin >> ch;
    }
    return 0;
}

