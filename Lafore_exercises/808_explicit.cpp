// 712_bmoney.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class bMoney {
private:
    long double number;       // число в лонг дабл
    string StrAsNumb;         // число в строковом типе
public:
    bMoney() {}
    explicit bMoney ( long double numb) : number( numb )
    { ldtostr( numb ); }
    bMoney ( string strmoney )
    { strtold( strmoney ); }
    void ldtostr ( long double numb );      // преобразую число в строку и сохраняю
    void strtold ( string strmoney );       // преобразую строку в число и сохраняю
    void putmoney ( long double numb );     // задать значения объкта с помощью метода
    void putmoney ( string strmoney );      //  *******
    bMoney operator+ ( const bMoney& b2 ) const; // сумма
    bMoney operator- ( const bMoney& b2 ) const;
    bMoney operator* ( long double ld2 ) const;
    long double operator/ ( const bMoney& b2 ) const;
    bMoney  operator/ ( long double ld2 ) const;
    void show() const;                  // вывод в денежном виде
};

int main()
{
    bMoney b1, b2, b3;
    string str;
    long double ld, result;
    char ch;
    while ( ch != 'n' ) {
        cout << "Введите первую денежную строку: ";
        getline( cin, str ); b1.putmoney( str );
        cout << "Введите вторую денежную строку: ";
        getline( cin, str ); b2.putmoney( str );
        cout << "Введите число с плавающей точкой: ";
        cin >> ld;
        cin.get();
        b3 = b1 + b2;
        b1.show(); cout << " + "; b2.show(); cout << " = "; b3.show(); cout << endl;
        b3 = b1 - b2;
        b1.show(); cout << " - "; b2.show(); cout << " = "; b3.show(); cout << endl;
        b3 = b1 * ld;
        b1.show(); cout << " * " << ld; cout << " = "; b3.show(); cout << endl;
        result = b1 / b2;
        b1.show(); cout << " / "; b2.show(); cout << " = " << result; cout << endl;
        b3 = b1 / ld;
        b1.show(); cout << " / " << ld; cout << " = "; b3.show(); cout << endl;
        cout << "Повторить?(y/n): ";
        cin >> ch;
        cin.get();
    }
    return 0;
}

void bMoney::ldtostr(long double numb) {
    number = numb;
    ostringstream ss;
    ss << setiosflags ( ios::fixed )     // нормальный не экспоненциальный вид
       << setiosflags ( ios::showpoint ) // всегда показывать точку
       << setprecision ( 2 )             // два знака после запятой
       << numb;
    StrAsNumb = ss.str();
}

void bMoney::strtold(string strmoney) {
    StrAsNumb = "";                          // очищаем данные из строки
    int size = strmoney.size();              // узнаём размер строки
    for ( int i = 0; i < size; i++ )
    {
        int position = strmoney.find_first_of( "0123456789." ); // ищем позицию первого встретившегося символа
        if ( position == -1)                                    // если нужных символов нет, то выходим из цикла
            break;
        StrAsNumb += strmoney.at( position );                   // пишем в строку только числа и точку
        strmoney.replace( position, 1, "/" );                   // в исходной строке убираем найденый символ
    }                                                           // чтобы найти следующие
    number = stold( StrAsNumb );                                // преобразуем строку в число
    ldtostr( number );                                          // для корректного заполнения строки нулями в конце
}
void bMoney::putmoney(string strmoney) {
    strtold( strmoney );
}
void bMoney::putmoney(long double numb) {
    number = numb;
    ldtostr( number );
}

void bMoney::show() const {
    int ofint = StrAsNumb.find( '.' ) - 1;     // количество цифр до плавающей точки
    int size = StrAsNumb.size();               // длина строки
    int first_comma = ofint % 3;               // вычисляем через сколько позиций должна быть первая запятая
    cout << "$";
    for (int j = 0; j < size; j++)
    {
        cout << StrAsNumb.at( j );                      // выводим строку посимвольно
        if ( (j-first_comma) % 3 == 0 && j < ofint )    // пока не дошли до десятичных, делим запятыми
            cout << ",";                                // на группы по 3 числа
    }
}

bMoney bMoney::operator+ ( const bMoney &b2 ) const {
    return bMoney( number + b2.number);
}
bMoney bMoney::operator- ( const bMoney &b2 ) const {
    return bMoney( number - b2.number );
}
bMoney bMoney::operator* ( long double ld2 ) const {
    return bMoney ( number * ld2 );
}
long double bMoney::operator/ ( const bMoney &b2 ) const {
    return number / b2.number;
}
bMoney bMoney::operator/ ( long double ld2 ) const {
    return bMoney( number / ld2 );
}