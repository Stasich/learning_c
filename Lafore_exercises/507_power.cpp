// 502_power.cpp

#include <iostream>
using namespace std;

double power(double, int = 2);
int power(int);
long power(long);
double power(float);
void power(char);


int main()
{
    double n;
    char ch;
    int p, i;
    long l;
    float f;
    cout << "Введите число для возведения в квадрат(double): ";
    cin >> n;
    cout << "Введите любой символ: ";
    cin >> ch;
    cout << "Введите число для возведения в квадрат(int): ";
    cin >> i;
    cout << "Введите число для возведения в квадрат(long): ";
    cin >> l;
    cout << "Введите число для возведения в квадрат(float): ";
    cin >> f;
    cout << power(n) << endl;
    power(ch);
    cout << power(i) << endl;
    cout << power(l) << endl;
    cout << power(f) << endl;
    return 0;
}

double power(double n, int p)
{
    double rez = n;
    cout << "double: ";
    if (p == 0)
        rez = 1;
    else
        for (int i = 1; i < p; i++)
            rez = rez * n;
    return rez;
}
void power(char ch)
{
    cout << "Введныый символ: " << ch << endl;
}

int power(int n)
{
    cout << "int: ";
    return n * n;
}
long power(long n)
{
    cout << "long: ";
    return n * n;
}
double power(float n)
{
    cout << "float: ";
    return n * n;
}
