// 512_calc_func.cpp

#include <iostream>
using namespace std;

struct fraction
{
    int up, down;
};

fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);

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
                rez = fadd(f1, f2);
                cout << "Результат сложения: " << rez.up << slesh << rez.down << endl;
                break;
            case '-':
                rez = fsub(f1, f2);
                cout << "Результат вычитания: " << rez.up << slesh << rez.down << endl;
                break;
            case '*':
                rez = fmul(f1, f2);
                cout << "Результат умножения: " << rez.up << slesh << rez.down << endl;
                break;
            case '/':
                rez = fdiv(f1, f2);
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

fraction fadd(fraction f1, fraction f2)
{
    fraction rez;
    rez.up = (f1.up * f2.down + f1.down * f2.up);
    rez.down = (f1.down * f2.down);
    return rez;
}
fraction fsub(fraction f1, fraction f2)
{
    fraction rez;
    rez.up = (f1.up * f2.down - f1.down * f2.up);
    rez.down = (f1.down * f2.down);
    return rez;
}
fraction fmul(fraction f1, fraction f2)
{
    fraction rez;
    rez.up = f1.up * f2.up;
    rez.down = f1.down * f2.down;
    return rez;
}
fraction fdiv(fraction f1, fraction f2)
{
    fraction rez;
    rez.up = f1.up * f2.down;
    rez.down = f1.down * f2.up;
    return rez;
}