// 410_sterling.cpp
#include <iostream>
using namespace std;

struct sterling
{
    int pounds, shillings, pence;
};
int main()
{
    sterling New, Old;

    int SumNewPeni;
    float SumOldPeni;
    char point='.';
    cout << "Введите сумму в новом формате, в виде Ja.b: J";
    cin >> New.pounds >> point >> New.pence;
    SumNewPeni = New.pounds * 100 + New.pence;
    SumOldPeni = SumNewPeni * 2.4;
    Old.pounds = SumOldPeni/240;
    Old.shillings = (SumOldPeni - Old.pounds * 240)/12;
    Old.pence = SumOldPeni - Old.pounds * 240-Old.shillings * 12;
    cout<<"Сумма в старом формате: J"<<Old.pounds<<point<<Old.shillings<<point<<Old.pence<<endl;
    return 0;
}
