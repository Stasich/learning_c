// 909_add_date.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class date1{
    private:
        int year, month, day;
    public:
        date1() : year(0), month(0), day(0){}
        void getdate(){
            char ch = '/';
            cout << "Введите дату в формате yy/mm/dd: ";
            cin >> year >> ch >> month >> ch >> day;
        }
        void showdate() const {
            char ch = '/';
            cout << "\nДата: " << setw(2) << setfill('0') << year << ch << setw(2) << setfill('0') << month
                 << ch << setw(2) << setfill('0') << day;
        }
};

class publication
{
    private:
        string name;
        float price;
    public:
        publication(): name( "N/A" ), price ( 0.0 )
        {}
        void getdata();
        void putdata();
};

class publication2 : public publication
{
    private:
        date1 date;
    public:
        void getdata()
        {
            publication::getdata();
            date.getdate();
        }
        void putdata()
        {
            publication::putdata();
            date.showdate();
        }
};

class book : public publication2
{
    private:
        int pages;
    public:
        book(): publication2(), pages ( 0 ) {}
        void putdata();
        void getdata();
};

class type : public publication2
{
    private:
        float rec_time;
    public:
        type() : publication2(), rec_time( 0.0 ) {}
        void getdata();
        void putdata();
};


int main()
{
    book b1;
    type t1;
    b1.getdata();
    b1.putdata();
    t1.getdata();
    t1.putdata();
    return 0;
}

void publication::getdata() {
    cout << "\nВведиет название книги: "; getline( cin, name);
    cout << "Введите стоимость: "; cin >> price; cin.ignore( 50, '\n' );
}

void book::getdata() {
    publication2::getdata();
    cout << "Введите количетсво страниц: "; cin >> pages; cin.ignore( 50, '\n' );
}

void type::getdata() {
    publication2::getdata();
    cout << "Введите время записи: "; cin >> rec_time; cin.ignore( 50, '\n' );
}

void publication::putdata() {
    cout << "\nНазвание: " << name << "\nСтоимость: " << price;
}
void book::putdata() {
    publication2::putdata();
    cout << "\nКоличество страниц: " << pages << endl;
}

void type::putdata() {
    publication2::putdata();
    cout << "\nВремя записи: " << rec_time << endl;
}