// 301_tab_umnozhenia
// Created by stasich on 15.04.17.
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    unsigned long x;
    cout << "Введите число: ";
    cin >> x;
    for (int j = 1; j<201; j++)
    {
        cout << setw(5) << (x*j) << " ";
        if (!(j%10))
            cout << endl;
    }
    return 0;
}
