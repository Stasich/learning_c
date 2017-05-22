// employee.cpp

#include <iostream>
using namespace std;

struct employee
{
    int id;
    float coins;
};

int main()
{
    employee sten, sam, kartmen;
    cout << "Веведите через пробел номер и величичну пособия Стена: ";
    cin >> sten.id >> sten.coins;
    cout << "Веведите через пробел номер и величичну пособия Сема: ";
    cin >> sam.id >> sam.coins;
    cout << "Веведите через пробел номер и величичну пособия Картмена: ";
    cin >> kartmen.id >> kartmen.coins;
    cout << "У Стена id = " << sten.id << " пособие $" << sten.coins << endl;
    cout << "У Сема id = " << sam.id << " пособие $" << sam.coins << endl;
    cout << "У Картмена id = " << kartmen.id << " пособие $" << kartmen.coins << endl;
    return 0;
}