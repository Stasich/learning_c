// 401_phone_number.cpp

#include <iostream>
using namespace std;

struct phone
{
    int gorod, stancia, number;
};

int main()
{
    phone number2, number1 = {212, 767, 8900};
    cout << "Введите номер телефона в формате \"123 456 7890\":\n";
    cin >> number2.gorod >> number2.stancia >> number2.number;
    cout << "Мой номер (" << number1.gorod << ") " << number1.stancia << "-" << number1.number << endl
         << "Ваш номер (" << number2.gorod << ") " << number2.stancia << "-" << number2.number << endl;
    return 0;
}