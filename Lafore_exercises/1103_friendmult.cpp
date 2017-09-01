// 1103_friendmult.cpp
#include <iostream>
#include <iomanip>
using namespace std;

class Distance {
    private:
        int feet;
        float inches;
    public:
        Distance() : feet ( 0 ), inches ( 0.0 ) {}
        Distance ( float fl );
        Distance ( int f, float in ) : feet ( f ), inches ( in ) {}
        friend Distance operator* ( Distance , Distance );
        void display();
};

int main()
{
    Distance d1( 1, 0 );
    Distance d2, d3;
    d2 = d1 * 2.4;
    d1.display(); cout << " * 2.4 = "; d2.display(); cout << endl;
    d2 = 2.4 * d1;
    cout << "2.4 * "; d1.display(); cout << " = "; d2.display(); cout << endl;
    d3 = d1 * d2;
    d1.display(); cout << " * "; d2.display(); cout << " = "; d3.display(); cout << endl;
    return 0;
}
Distance::Distance(float fl) {
    feet = static_cast<int>( fl );
    inches = 12 * ( fl - feet );
}

Distance operator* ( Distance d1, Distance d2 )
{
    float inches_total = (d1.feet * 12 + d1.inches) * ( d2.feet * 12 + d2.inches );
    int feet = static_cast<int>( inches_total / 12 );
    inches_total -= feet * 12;
    return Distance ( feet, inches_total );
}

void Distance::display() {
    cout << feet << "\'-" << fixed << setprecision(2) << inches << "\"";
}