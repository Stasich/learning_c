// 703_average.cpp
#include <iostream>
using namespace std;

class Distance
{
private:
    static float sum_inches;
    static int count;
    int feet;
    float inches;
public:
    Distance() : feet( 0 ), inches( 0.0 )
    {}
    Distance( int ft, float inch ) : feet(ft), inches(inch)
    {}
    void get_dist();
    void show_average() const;
};

float Distance::sum_inches = 0;
int Distance::count = 0;

int main()
{
    const int MAX = 100;
    Distance dist1[MAX];
    char ch;
    int j = 0;
    do
    {
        dist1[j].get_dist();
        cout << "Ещё?(y/n):";
        cin >> ch;
    } while ( ch != 'n' && j < MAX);
    cout << "Среднее значение: ";
    dist1[0].show_average();
    cout << endl;
}

void Distance::get_dist()
{
    cout << "Введите футы: "; cin >> feet;
    cout << "Введите дюймы: "; cin >> inches;
    count++;
    sum_inches += feet * 12 + inches;
}
void Distance::show_average() const
{
    float aver_inches = sum_inches / count;
    int aver_feet = static_cast<int>( aver_inches / 12 );
    aver_inches = aver_inches - aver_feet * 12;
    cout << "Среднее значение: " << aver_feet << "\'-" << aver_inches << "\"";
}