// 407_employee2.cpp

#include <iostream>
using namespace std;

struct employee
{
    int id;
    float coins;
};
enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct date
{
    int day, month, year;
};

struct people
{
    employee employee1;
    etype prof;
    date d1;
};
int main()
{
    people man1, man2, man3, temp;
    char ch = '/', prof;

    for (int i = 1; i < 4; i++)
    {
        cout << "Веведите id " << i << "-го сотрудника, размер пособия, первую букву должности\n"
                "(laborer, secretary, manager, accountant, executive, researcher) и дату приёма на работу\n"
                "в формате: 1 23 l xx/xx/xxxx: ";
        cin >> temp.employee1.id >> temp.employee1.coins >> prof >> temp.d1.day
            >> ch >> temp.d1.month >> ch >> temp.d1.year;
        switch (prof)
        {
            case 'l': temp.prof = laborer; break;
            case 's': temp.prof = secretary; break;
            case 'm': temp.prof = manager; break;
            case 'a': temp.prof = accountant; break;
            case 'e': temp.prof = executive; break;
            case 'r': temp.prof = researcher; break;
        }
        switch (i)
        {
            case 1: man1 = temp; break;
            case 2: man2 = temp; break;
            case 3: man3 = temp; break;
        }
    }
    for ( int i = 1; i < 4; i++)
    {
        switch (i)
        {
            case 1: temp = man1; break;
            case 2: temp = man2; break;
            case 3: temp = man3; break;
        }
        cout << "Данные " << i << "-го сотрудника:\nid: "<< temp.employee1.id
             << "\nпособие: " << temp.employee1.coins;
        switch (temp.prof)
        {
            case 0: cout << "\nдолжность: laborer\n"; break;
            case 1: cout << "\nдолжность: secretary\n"; break;
            case 2: cout << "\nдолжность: manager\n"; break;
            case 3: cout << "\nдолжность: accountant\n"; break;
            case 4: cout << "\nдолжность: executive\n"; break;
            case 5: cout << "\nдолжность: researcher\n"; break;
        }
        cout << "Дата приёма на работу: " << temp.d1.day << ch << temp.d1.month << ch << temp.d1.year << endl;
    }
    return 0;
}