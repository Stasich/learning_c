// 503_zeroSmaller.cpp

#include <iostream>
using namespace std;

void zeroSmaller(int&, int&);

int main()
{
    int a,b;
    cout << "Введите первое число: "; cin >> a;
    cout << "Введите второе число: "; cin >> b;
    zeroSmaller(a, b);
    cout << "Первое чиисло: " << a << endl;
    cout << "Второе число: " << b << endl ;
    return 0;
}

void zeroSmaller(int& a, int& b)
{
    if (a < b)
        a = 0;
    else
        b = 0;
}