// 707_buisnes.cpp
#include <iostream>
#include <string>

using namespace std;

class bis_type
{
    private:
        long double money;      // для хранения числа
        string smoney;          // для хранения числа в строке
    public:
        bis_type(): money(0) {}
        bis_type( long double m ) : money( m ) {}
        long double mstold( string str );   // из строки ищет цифры и делает число
        void show_money() const;            // вывод числа по условиям задания, в виде 1,222,333.44
};

int main()
{
    bis_type b1;
    string st;
    cout << "Введите денежное значение: ";
    getline( cin, st );
    b1.mstold( st );
    b1.show_money();
    cout << endl;
    return 0;
}

long double bis_type::mstold( string str )
{
    int size = str.size();              // узнаём размер строки
    for ( int i = 0; i < size; i++ )
    {
        int position = str.find_first_of( "0123456789." ); // ищем позицию первого встретившегося символа
        if ( position == -1)                               // если нужных символов нет, то выходим из цикла
            break;
        smoney += str.at( position );                      // пишем в строку только числа и точку
        str.replace( position, 1, "/" );                   // в исходной строке убираем найденый символ
    }                                                      // чтобы найти следующие
    money = stold( smoney );                               // преобразуем строку в число
    return money;
}

void bis_type::show_money() const
{
    int ofint = smoney.find( '.' ) - 1;     // количество цифр до плавающей точки
    int size = smoney.size();               // длина строки
    int first_comma = ofint % 3;            // вычисляем через сколько позиций должна быть первая запятая
    cout << "$";
    for (int j = 0; j < size; j++)
    {
        cout << smoney.at( j );                         // выводим строку посимвольно
        if ( (j-first_comma) % 3 == 0 && j < ofint )    // пока не дошли до десятичных, делим запятыми
            cout << ",";                                // на группы по 3 числа
    }
}