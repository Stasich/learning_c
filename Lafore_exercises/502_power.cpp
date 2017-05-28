// 502_power.cpp

#include <iostream>
using namespace std;

double power(double, int = 2);

int main()
{
    double n;
    char ch;
    int p;
    cout << "Введите число для возведения в степень: ";
    cin >> n;
    cout << "Степень возведения будет равна 2? (y/n): ";
    cin >> ch;
    if (ch == 'n')
    {
        cout << "Введите степень числа: ";
        cin >> p;
        cout << power(n, p) << endl;
    }
    else
        cout << power(n) << endl;
    return 0;
}

double power(double n, int p)
{
    double rez = n;
    if (p == 0)
        rez = 1;
    else
        for (int i = 1; i < p; i++)
            rez = rez * n;
    return rez;
}