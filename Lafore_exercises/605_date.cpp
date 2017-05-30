// 605_date.cpp

#include <iostream>
#include <iomanip>
using namespace std;

class date1{
private:
    int year, month, day;
public:
    date1() : year(0), month(0), day(0){}
    void getdate(){
        char ch = '/';
        cin >> year >> ch >> month >> ch >> day;
    }
    void showdate() const {
        char ch = '/';
        cout << setw(2) << setfill('0') << year << ch << setw(2) << setfill('0') << month
        << ch << setw(2) << setfill('0') << day;
    }
};

int main()
{
    date1 d1;
    cout << "Введите дату в формате yy/mm/dd: ";
    d1.getdate();
    cout << "Вы ввели: ";
    d1.showdate();
    cout << endl;
    return 0;
}