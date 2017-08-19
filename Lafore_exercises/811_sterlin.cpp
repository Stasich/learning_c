// 811_sterlin.cpp
#include <iostream>
using namespace std;

class sterlings
{
    private:
        int pounds, shillings, pence;
    public:
        sterlings(): pounds ( 0 ), shillings ( 0 ), pence ( 0 )
        {}
        sterlings( double d );
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
};

int main()
{
    sterlings s1, s2, s3;
    double d;
    s1.get_sterling();
    s1.put_sterling(); cout << endl;
    s2.get_sterling();
    cout << "Введие значение в новом десятичном виде(J1.66) : J";
    cin >> d;
    s3 = s1 + s2;
    cout << "s1 + s2 = "; s3.put_sterling(); cout << endl;
    s3 = s1 - s2;
    cout << "s1 - s2 = "; s3.put_sterling(); cout << endl;
    s3 = s1 * s2;
    cout << "s1 * s2 = "; s3.put_sterling(); cout << endl;
    s3 = s1 / s2;
    cout << "s1 / s2 = "; s3.put_sterling(); cout << endl;
    s3 = s1 / d;
    cout << "s1 / d = "; s3.put_sterling(); cout << endl;
    return 0;
}

sterlings::sterlings(double d) {
    double sum_new_pence = d * 100;
    double sum_old_pence = sum_new_pence * 2.4;
    pounds = sum_old_pence / 240;
    shillings = ( sum_old_pence - pounds * 240 ) / 12;
    pence = sum_old_pence - pounds * 240 - shillings * 12;
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