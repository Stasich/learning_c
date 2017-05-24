// 412_fraction_calc.cpp

#include <iostream>
using namespace std;

struct fraction
{
    int up, down;
};

int main()
{
    fraction f1, f2, rez;
    char znak, slesh = '/', ch;
    do
    {
        cout << "Введите выражение вида a/b+c/d: ";
        cin >> f1.up >> slesh >> f1.down >> znak >> f2.up >> slesh >> f2.down;
        switch(znak)
        {
            case '+':
                rez.up = (f1.up * f2.down + f1.down * f2.up);
                rez.down = (f1.down * f2.down);
                cout << "Результат сложения: " << rez.up << slesh << rez.down << endl;
                break;
            case '-':
                rez.up = (f1.up * f2.down - f1.down * f2.up);
                rez.down = (f1.down * f2.down);
                cout << "Результат вычитания: " << rez.up << slesh << rez.down << endl;
                break;
            case '*':
                rez.up = f1.up * f2.up;
                rez.down = f1.down * f2.down;
                cout << "Результат умножения: " << rez.up << slesh << rez.down << endl;
                break;
            case '/':
                rez.up = f1.up * f2.down;
                rez.down = f1.down * f2.up;
                cout << "Результат деления: " << rez.up << slesh << rez.down << endl;
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