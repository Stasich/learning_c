// 905_employ.cpp
#include <iostream>
using namespace std;
const int LEN = 80;

class employee
{
    private:
        char name[ LEN ];
        unsigned long number;
    public:
        void getdata()
        {
            cout << "\nВведите имя: "; cin >> name;
            cout << "Введите номер: "; cin >> number;
        }
        void putdata()
        {
            cout << "\nИмя: " << name << "\nНомер: " << number;
        }
};

class manager : private employee
{
    private:
        char title[ LEN ];
        double dues;
    public:
        void getdata()
        {
            employee::getdata();
            cout << "\nВведите должность: "; cin >> title;
            cout << "Введите сумму взносов: "; cin >> dues;
        }
        void putdata()
        {
            employee::putdata();
            cout << "\nДолжность: " << title << "\nСумма взносов: " << dues;
        }
};

class scientist : employee
{
    private:
        int pubs;
    public:
        void getdata()
        {
            employee::getdata();
            cout << "\nВведите количество публикаций: "; cin >> pubs;
        }
        void putdata()
        {
            employee::putdata();
            cout << "\nКол-во публикаций: " << pubs;
        }
};

class laborer : public employee
{
};

class employee2 : employee
{
    private:
        double compensation;
        enum Period { hour, week, month };
        Period period;
    public:
        void getdata()
        {
            char ch;
            cout << "\nВведите размер компенсации: "; cin >> compensation;
            cout << "Введите период (h/w/m): "; cin >> ch;
            switch (ch)
            {
                case 'h' : period = hour; break;
                case 'w' : period = week; break;
                case 'm' : period = month; break;
            }
        }
        void putdata()
        {
            cout << "\nкомпенсация: " << compensation;
            switch ( period )
            {
                case 0 : cout << "\nПериод: час"; break;
                case 1 : cout << "\nПериод: неделя"; break;
                case 2 : cout << "\nПериод: месяц"; break;
            }
        }
};

class manager2 : private manager, private employee2
{
    public:
        void putdata()
        {
            manager::putdata();
            employee2::putdata();
        }
        void getdata()
        {
            manager::getdata();
            employee2::getdata();
        }
};

class scientist2 : scientist, employee2
{
public:
    void putdata()
    {
        scientist::putdata();
        employee2::putdata();
    }
    void getdata()
    {
        scientist::getdata();
        employee2::getdata();
    }
};

class laborer2 : laborer, employee2
{
public:
    void putdata()
    {
        laborer::putdata();
        employee2::putdata();
    }
    void getdata()
    {
        laborer::getdata();
        employee2::getdata();
    }
};

int main()
{
    manager2 m1;
    scientist2 s1;
    laborer2 l1;
    m1.getdata();
    m1.putdata();
    s1.getdata();
    s1.putdata();
    l1.getdata();
    l1.putdata();
    cout << endl;
    return 0;
}