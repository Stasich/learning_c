// 508_swap.cpp

#include <iostream>
using namespace std;

void swap(int&, int&);

int main()
{
    int a,b;
    cout << "Введите значение а: "; cin >> a;
    cout << "Введите значение b: "; cin >> b;
    swap(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}