// 711_ldtoms.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class money
{
    private:
        string str;
        long double number;
    public:
        string ldtostr ( long double& numb );
        void show_money( long double& numb );
};

int main()
{
    money m1;
    char ch;
    long double numb;
    while ( ch != 'n' ){
        cout << "Введите число для преобразования в денежный тип: ";
        cin >> numb;
        m1.show_money( numb );
        cout << endl;
        cout << "Повторить?(y/n):";
        cin >> ch;
    }
    return 0;
}

string money::ldtostr(long double& numb) {
    if ( numb < 9999999999999990.00 ) {         //по условию задачи предельное число
        number = numb;
        ostringstream ss;
        ss << setiosflags ( ios::fixed )     // нормальный не экспоненциальный вид
           << setiosflags ( ios::showpoint ) // всегда показывать точку
           << setprecision ( 2 )             // два знака после запятой
           << numb;
        str = ss.str();
        return str;
    }
    else
        return "Слишком большое число.";
}

void money::show_money( long double& numb )
{
    if ( ldtostr( numb ) == "Слишком большое число." )
        cout << "Слишком большое число.";
    else {
        int ofint = str.find('.') - 1;     // количество цифр до плавающей точки
        int size = str.size();               // длина строки
        int first_comma = ofint % 3;            // вычисляем через сколько позиций должна быть первая запятая
        cout << "$";
        for (int j = 0; j < size; j++) {
            cout << str.at(j);                         // выводим строку посимвольно
            if ((j - first_comma) % 3 == 0 && j < ofint)    // пока не дошли до десятичных, делим запятыми
                cout << ",";                                // на группы по 3 числа
        }
    }
}