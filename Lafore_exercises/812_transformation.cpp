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
        long double return_numb()
            { return number; }
};

class sterlings
{
    private:
        int pounds, shillings, pence;
    public:
        sterlings(): pounds ( 0 ), shillings ( 0 ), pence ( 0 )
        {}
        sterlings( double d );
        sterlings( bMoney b2 );
        sterlings( int pou, int sh, int pen) : pounds ( pou ), shillings ( sh ), pence ( pen )
        {}
        void get_sterling();
        void put_sterling() const;
        sterlings operator+ ( const sterlings& s2 ) const;
        sterlings operator- ( const sterlings& s2 ) const;
        sterlings operator* ( const sterlings& s2 ) const;
        sterlings operator/ ( const sterlings& s2 ) const;
        sterlings operator/ ( const double& d2 ) const;
        operator double () const;
        operator bMoney () const;
};


int main()
{
    bMoney m1;                          //объект для $
    string str1;                        //строка для определя объекта в $
    sterlings s1;                       //объект для британской валюты, стерлинг
    s1.get_sterling();                  //получаем значение для британской валюты
    m1 = s1;                            // преобразуем британскую валюту в $
    s1.put_sterling(); cout << " = "; m1.show();    //выводим результат
    cout << "\nВведите строку в долларах: ";        //
    getline( cin, str1 );                           //получаем строку для $
    m1.putmoney( str1 );                            //передаём значение в $ объект
    s1 = m1;                                        // преобразуем $  в стерлинги
    m1.show(); cout << " = "; s1.put_sterling();    // выводим результат
    cout << endl;
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

sterlings::sterlings( double d ) {
    double sum_new_pence = d * 100;
    double sum_old_pence = sum_new_pence * 2.4;
    pounds = sum_old_pence / 240;
    shillings = ( sum_old_pence - pounds * 240 ) / 12;
    pence = sum_old_pence - pounds * 240 - shillings * 12;
}
sterlings::sterlings( bMoney b2 ) {
    long double sum_pence = b2.return_numb() * 240/50;
    pounds = sum_pence / 240;
    shillings = ( sum_pence - pounds * 240 ) / 12;
    pence = sum_pence - pounds * 240 - shillings * 12;
}

void sterlings::get_sterling() {
    char ch = '.';
    cout << "Введите значение в старом формате (J9.19.11) : J";
    cin >> pounds >> ch >> shillings >> ch >> pence;
    cin.get();
}
void sterlings::put_sterling() const {
    cout << "J" << pounds << "." << shillings << "." << pence;
}

sterlings sterlings::operator+ ( const sterlings& s2 ) const {
    return sterlings( double ( sterlings ( pounds, shillings, pence ) ) + double ( s2 ) );
}
sterlings sterlings::operator- ( const sterlings& s2 ) const {
    return sterlings( double ( sterlings ( pounds, shillings, pence ) ) - double ( s2 ) );
}
sterlings sterlings::operator* ( const sterlings& s2 ) const {
    return sterlings( double ( sterlings ( pounds, shillings, pence ) ) * double ( s2 ) );
}
sterlings sterlings::operator/ ( const sterlings& s2 ) const {
    return sterlings( double ( sterlings ( pounds, shillings, pence ) ) / double ( s2 ) );
}
sterlings sterlings::operator/ ( const double& d2 ) const {
    return sterlings( double ( sterlings ( pounds, shillings, pence ) ) /  d2 );
}

sterlings::operator double () const {
    double sum_new_pence = (pounds * 240 + shillings * 12 + pence) / 2.4 / 100;
    return sum_new_pence;
}

sterlings::operator bMoney() const {
    long double money = static_cast<long double>(pounds * 240 + shillings * 12 + pence) / 240 * 50;
    return bMoney( money );
}