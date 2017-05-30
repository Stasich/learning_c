// 604_employee.cpp

#include <iostream>
using namespace std;

class employee
{
private:
    int number;
    float money;
public:
    employee() : number(0), money(0.0)
    {}
    void set_emp(){
        cout << "Введите номер: "; cin >> number;
        cout << "Введите оклад: "; cin >> money;
    }
    void dysplay() const
    { cout << " Номер: " << number << ". Оклад: " << money << endl; }
};

int main()
{
    employee e1, e2, e3;
    cout << "Первый работник.\n";
    e1.set_emp();
    cout << "Второй работник.\n";
    e2.set_emp();
    cout << "Третий работник.\n";
    e3.set_emp();
    cout << "Первый работник.";
    e1.dysplay();
    cout << "Второй работник.";
    e2.dysplay();
    cout << "Третий работник.";
    e3.dysplay();
    return 0;
}