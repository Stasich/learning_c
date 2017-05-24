// 408_drobi.cpp

#include <iostream>
using namespace std;

struct fraction
{
    int chisl;
    int znam;
};

int main()
{
    fraction dr1, dr2, sum;
    char ch = '/';
    cout << "Введите дробь в формате a/b+z/d: ";
    cin >> dr1.chisl >> ch >> dr1.znam >> ch >> dr2.chisl >> ch >> dr2.znam;
    sum.chisl = dr1.chisl * dr2.znam + dr2.chisl*dr1.znam;
    sum.znam = dr1.znam * dr2.znam;
    cout << "Сумма дроби равна: " << sum.chisl << ch << sum.znam << endl;
    return 0;
}