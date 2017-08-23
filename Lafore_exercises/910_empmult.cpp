// 910_empmult.cpp
#include <iostream>
using namespace std;
const int LEN = 80;

class student
{
    private:
        char school[ LEN ];
        char degree[ LEN ];
    public:
        void getedu()
        {
            cout << "Введите название учебного заведения: ";
            cin >> school;
            cout << "Введите степень высшего образования: ";
            cout << "\n(неполное высшее, бакалавр, магистр) : ";
            cin >> degree;
        }
        void putedu()
            { cout << "\nSchool: " << school << "\nDegree: " << degree;}
};

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
            { cout << "\nИмя: " << name << "\nНомер: " << number;}
};

class manager : private student, private employee
 {
    private:
        char title[ LEN ];
        double dues;
    public:
        void getdata()
        {
            employee::getdata();
            student::getedu();
            cout << "\nВведите должность: "; cin >> title;
            cout << "Введите сумму взносов: "; cin >> dues;
        }
        void putdata()
        {
            employee::putdata();
            student::putedu();
            cout << "\nДолжность: " << title << "\nВзносы: " << dues;
        }
};

class executive : private manager
{
    private:
        double prize;
        double stock;
    public:
        void getdata()
        {
            manager::getdata();
            cout << "Введите размер годовой преми: "; cin >> prize;
            cout << "Введите количество акций: "; cin >> stock;
        }
        void putdata()
        {
            manager::putdata();
            cout << "\nПремия: " << prize << "\nАкции: " << stock;
        }
};

int main()
{
    executive e1;
    e1.getdata();
    e1.putdata();
    cout << endl;
    return 0;
}