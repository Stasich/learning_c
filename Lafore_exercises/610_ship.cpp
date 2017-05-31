// 610_ship.cpp

#include <iostream>
using namespace std;

class angle{
private:
    int grad;
    float min;
    char side;
public:
    void set_angle();
    void show_angle()const;
};

class ship{
private:
    angle dolgota, shirota;
    static int count;
    int number;
public:
    ship(){
        count++;
        number = count;
    }
    void set_koordinati();
    void show_dataShip()const;
};

int ship::count = 0;

int main()
{
    ship s1, s2, s3;
    s1.set_koordinati();
    s2.set_koordinati();
    s3.set_koordinati();
    s1.show_dataShip();
    s2.show_dataShip();
    s3.show_dataShip();
    return 0;
}
void angle::set_angle() {
    cin >> grad >> min >> side;
}
void angle::show_angle() const {
    cout << grad << "\xF8" << min << "\' " << side;
}
void ship::set_koordinati() {
    cout << "Введите через пробел координаты долготы " << number << " корабля.(180 33.5 W): ";
    dolgota.set_angle();
    cout << "Введите через пробел координаты широты " << number << " корабля.(88 31.3 S): ";
    shirota.set_angle();
}
void ship::show_dataShip() const {
    cout << "Данные " << number << " корабля.\n" << "Номер: " << number
         << ". Координаты: ";
    dolgota.show_angle(); cout << " "; shirota.show_angle();
    cout << endl;
}