// 606_empl.cpp

#include <iostream>
#include <iomanip>
using namespace std;

class date1
{
private:
    int year, month, day;
public:
    date1() : year(0), month(0), day(0){}
    void get_date(){
        char ch = '/';
        cout << "Введите дату приёма на работу в формате yy/mm/dd: ";
        cin >> year >> ch >> month >> ch >> day;
    }
    void display_date() const{
        cout << setw(2) << setfill('0') << year << "/"
             << setw(2) << setfill('0') << month << "/"
             << setw(2) << setfill('0') << day;
    }
};

enum etype {manager, laborer, secretary, accountant, executive, researcher};

class emplyee {
private:
    int number;
    float money;
    etype prof;
public:
    date1 date_p;           //дата приёма на работу
    emplyee() : number(0), money(0.0){}
    void set_emp(){
        cout << "Введите id: "; cin >> number;
        cout << "Введите оклад: "; cin >> money;
    }
    void set_etype()
    {
        char ch;
        cout << "Введите первую букву должности "
                "(manager, laborer, secretary, accountant, executive, researcher): ";
        cin >> ch;
        switch (ch){
            case 'm': prof = manager; break;
            case 'l': prof = laborer; break;
            case 's': prof = secretary; break;
            case 'a': prof = accountant; break;
            case 'e': prof = executive; break;
            case 'r': prof = researcher; break;
        }
    }
    void getemploy(){
        set_emp();
        set_etype();
        date_p.get_date();
    }
    void putemploy()const{
        cout << "id: " << number << ". Оклад: " << money << ". Должность: ";
        switch (prof){
            case 0: cout << "manager."; break;
            case 1: cout << "laborer."; break;
            case 2: cout << "secretary."; break;
            case 3: cout << "accountant."; break;
            case 4: cout << "executive."; break;
            case 5: cout << "researcher."; break;
        }
        cout << "\nДата приёма на работу: ";
        date_p.display_date();
    }
};

int main()
{
    emplyee e1, e2, e3;
    cout << "Введите данные первого сотрудника.\n";
    e1.getemploy();
    cout << "\nВведите данные второго сотрудника.\n";
    e2.getemploy();
    cout << "\nВведите данные третьего сотрудника.\n";
    e3.getemploy();
    cout << "\nПервый сотрудник.";
    e1.putemploy();
    cout << "\nВторой сотрудник.";
    e2.putemploy();
    cout << "\nТретий сотрудник.";
    e3.putemploy();
    cout << endl;
    return 0;
}