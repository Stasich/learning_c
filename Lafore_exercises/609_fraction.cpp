// 609_fraction.cpp

#include <iostream>
using namespace std;

class fraction{
private:
    int up, down;
public:
    void set_drob();
    fraction sum_drob(fraction) const;
    void display()const;
};

int main()
{
    fraction d1, d2, d3;
    char ch;
    do{
        d1.set_drob();
        d2.set_drob();
        d3 = d1.sum_drob(d2);
        d1.display(); cout << " + "; d2.display(); cout << " = ";
        d3.display();
        cout << endl << "Ещё раз?(y/n): ";
        cin >> ch;
    }while(ch != 'n');
    return 0;
}

void fraction::set_drob() {
    char slesh = '/';
    cout << "Введите дробь в формате x/y: ";
    cin >> up >> slesh >> down;
}
fraction fraction::sum_drob(fraction y) const {
    fraction temp;
    temp.up = up * y.down + y.up * down;
    temp.down = down * y.down;
    return temp;
}
void fraction::display()const {
    cout << up << "/" << down;
}