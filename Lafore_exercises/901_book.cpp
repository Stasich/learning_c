// 901_book.cpp
#include <iostream>
#include <string>
using namespace std;

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

class book : private publication
{
    private:
        int pages;
    public:
        book(): publication(), pages ( 0 ) {}
        void putdata();
        void getdata();
};

class type : private publication
{
    private:
        float rec_time;
    public:
        type() : publication(), rec_time( 0.0 ) {}
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
    cout << "Введиет название книги: "; cin >> name;
    cout << "Введите стоимость: "; cin >> price; cin.ignore( 50, '\n' );
}

void book::getdata() {
    publication::getdata();
    cout << "Введите количетсво страниц: "; cin >> pages; cin.ignore( 50, '\n' );
}

void type::getdata() {
    publication::getdata();
    cout << "Введите время записи: "; cin >> rec_time; cin.ignore( 50, '\n' );
}

void publication::putdata() {
    cout << name << " " << price;
}
void book::putdata() {
    publication::putdata();
    cout << " " << pages << endl;
}

void type::putdata() {
    publication::putdata();
    cout << " " << rec_time << endl;
}