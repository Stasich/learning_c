// 1001_average.cpp
#include <iostream>
using namespace std;

int main()
{
    float flnumb[ 100 ];
    int n = 0;
    char ch;
    do{
        cout << "Введите число: ";
        cin >> *( flnumb + n++ );
        cout << "Повторить?(y/n): ";
        cin >> ch;
    } while ( ch != 'n' );
    int j = 0;
    float* aver;
    float total = 0;
    while ( flnumb + n > flnumb + j )
        {
            float average;
            total += *( flnumb + j++ );
            average = (total/n);
            aver = &average;
        }
    cout << "Среднее значение: " << *aver << endl;
    return 0;
}