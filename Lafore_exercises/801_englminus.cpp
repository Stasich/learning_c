// 801_engkminus.cpp
// engplus.cpp modification
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;
public:
    Distance() : feet ( 0 ), inches ( 0 )
    {}
    Distance( int f, float in ) : feet ( f ), inches ( in )
    {}
    void get_dist();
    void show_dist() const;
    Distance operator+ ( Distance d2 ) const;
    Distance operator- ( Distance d2 ) const;
};

int main()
{
    Distance d1, d2, d3,d4;
    d1.get_dist();
    d2.get_dist();
    d3 = d1 - d2;
    cout << "d3 = d1-d2 = ";
    d3.show_dist();
    cout << endl;
    d4 = d1 - d2 - d3;
    cout << "d1-d2-d3 = ";
    d4.show_dist();
    cout << endl;
    return 0;
}

void Distance::get_dist() {
    cout << "Введте футы: ";
    cin >> feet;
    cout << "Введите дюймы: ";
    cin >> inches;
}

void Distance::show_dist() const {
    cout << feet << "\'-" << inches << "\"";
}

Distance Distance::operator+ ( Distance d2 ) const {
    int f = feet + d2.feet;
    float in = inches + d2.inches;
    if ( in > 11 ){
        in -= 12;
        f++;
    }
    return Distance ( f, in );
}

Distance Distance::operator- ( Distance d2 ) const {
    int f = feet - d2.feet;
    float in = inches - d2.inches;
    if ( in < 0 ){
        in += 12;
        f--;
    }
    return Distance ( f, in );
}