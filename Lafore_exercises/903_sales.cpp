// 903_sales.cpp
#include <iostream>
#include <string>
using namespace std;

class sales
{
    protected:
        static const int SZ = 3;
        float arr[ SZ ];
    public:
        sales()
        { for ( int j = 0 ; j < SZ; j++)
            arr [ j ] = 0.0;
        }
        void getdata();
        void putdata();
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

class book : private publication, private sales
{
private:
    int pages;
public:
    book(): publication(), pages ( 0 ) {}
    void putdata();
    void getdata();
};

class type : private publication, private sales
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
    cout << "Введиет название книги: "; getline (cin, name);
    cout << "Введите стоимость: "; cin >> price; cin.ignore( 50, '\n' );
}

void book::getdata() {
    publication::getdata();
    sales::getdata();
    cout << "Введите количетсво страниц: "; cin >> pages; cin.ignore( 50, '\n' );
}

void type::getdata() {
    publication::getdata();
    sales::getdata();
    cout << "Введите время записи: "; cin >> rec_time; cin.ignore( 50, '\n' );
}

void sales::getdata() {
    for (int j = 0; j < SZ; j++)
    {
        cout << "Введите общую стоимость проданных книг за " << j+1 << " месяц: ";
        cin >> arr [ j ];
        cin.ignore( 50, '\n' );
    }
}

void publication::putdata() {
    cout << name << " " << price << endl;
}
void book::putdata() {
    publication::putdata();
    sales::putdata();
    cout << " " << pages << endl;
}

void type::putdata() {
    publication::putdata();
    sales::putdata();
    cout << " " << rec_time << endl;
}

void sales::putdata() {
    for (int j = 0; j < SZ; j++)
    {
        cout << "Продано за " << j+1 << " месяц: " << arr [ j ] << endl;
    }
}