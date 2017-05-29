//sterling.cpp

#include <iostream>
using namespace std;

struct sterling
{
    int pounds, shillings, pence;
};

sterling get_money();
sterling sum_money(sterling, sterling);
void display_money(sterling);

int main()
{
    sterling s1, s2, sum;
    s1 = get_money();
    s2 = get_money();
    sum = sum_money(s1, s2);
    display_money(s1);
    cout << " + ";
    display_money(s2);
    cout << " = ";
    display_money(sum);
    cout << endl;
    return 0;
}

sterling get_money()
{
    sterling babki;
    char ch = '.';
    cout << "Введите денежную сумму в формате Ja.b.c: J";
    cin >> babki.pounds >> ch >> babki.shillings >> ch >> babki.pence;
    return babki;
}

sterling sum_money(sterling s1, sterling s2)
{
    sterling sum;
    double sum_pence;
    sum_pence = s1.pounds * 240 + s1.shillings * 12 + s1.pence
            + s2.pounds * 240 + s2.shillings * 12 + s2.pence;
    sum.pounds = sum_pence / 240;
    sum.shillings = (sum_pence - sum.pounds*240) / 12;
    sum.pence = sum_pence - sum.pounds * 240 - sum.shillings * 12;
    return sum;
}

void display_money(sterling s)
{
    cout << "J" << s.pounds << "." << s.shillings << "." << s.pence;
}
