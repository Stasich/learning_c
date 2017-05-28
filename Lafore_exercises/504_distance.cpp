// 504_distance.cpp

#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

Distance moreThenYou(Distance, Distance);
void displayDD(Distance);

int main()
{
    Distance d1, d2, dd;
    cout << "Введите число футов d1: "; cin >> d1.feet;
    cout << "Введите число дюймов d1: "; cin >> d1.inches;
    cout << "Введите число футов d2: "; cin >> d2.feet;
    cout << "Введите число дюймов d2: "; cin >> d2.inches;
    cout << "d1: "; displayDD(d1);
    cout << "d2: "; displayDD(d2);
    dd = moreThenYou(d1, d2);
    if (d1.feet == dd.feet && d1.inches == dd.inches)
        cout << "d1 >= d2" << endl;
    else
        cout << "d1 < d2" << endl;
    return 0;
}
Distance moreThenYou(Distance d1, Distance d2)
{
    float inches_d1, inches_d2;
    inches_d1 = d1.feet * 12 + d1.inches;
    inches_d2 = d2.feet * 12 + d2.inches;
    if (inches_d1 >= inches_d2)
        return d1;
    else
        return d2;
}

void displayDD(Distance dd)
{
    cout << dd.feet << "\'-" << dd.inches << "\"" << endl;
}