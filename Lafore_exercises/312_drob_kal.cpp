// 312_drob_kal.cpp
// Created by stasich on 22.04.17.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b, c , d, i;
    char znak, slesh = '/', ch;
    do
    {
        cout << "Введите выражение вида a/b+c/d: ";
        cin >> a >> slesh >> b >> znak >> c >> slesh >> d;
        switch(znak)
        {
            case '+':
                a = (a*d + b*c);
                b = (b * d);
                cout << "Результат сложения: " << a << slesh << b << endl;
                break;
            case '-':
                a = (a*d - b*c);
                b = (b * d);
                cout << "Результат вычитания: " << a << slesh << b << endl;
                break;
            case '*':
                a = a * c;
                b = b * d;
                cout << "Результат умножения: " << a << slesh << b << endl;
                break;
            case '/':
                a = a * d;
                b = b * c;
                cout << "Результат деления: " << a << slesh << b << endl;
                break;
            default:
                cout << "Где-то возникла ошибка, попробуйте ещё раз" << endl;
                continue;
        }
        cout << "Ещё разок? (y/n): ";
        cin >> ch;
    }while( ch != 'n');
    return 0;
}