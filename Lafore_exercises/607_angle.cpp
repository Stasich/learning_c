// 607_angle.cpp

#include <iostream>
using namespace std;

class angle{
private:
    int grad;
    float min;
    char side;
public:
    angle() {}
    angle(int g, float m, char s) : grad(g), min(m), side(s) {}
    void set_data();
    void show_data()const;
};

int main()
{
    angle a1(10,31.8, 'S');
    char ch;
    cout << "a1: ";
    a1.show_data();
    cout << endl;
    do {
        a1.set_data();
        cout << "a1: ";
        a1.show_data();
        cout << endl;
        cout << "Ещё раз? (y/n): ";
        cin >> ch;
    }while(ch != 'n');
    return 0;
}

void angle::set_data() {
    cout << "Введите через пробел количество градусов, минут и направление(N,S,E,W): ";
    cin >> grad >> min >> side;
}
void angle::show_data() const {
    cout << grad << "\xF8" << min << "\' " << side;
}