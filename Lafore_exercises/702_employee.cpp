// 702_employee.cpp
#include <iostream>
#include <string>
#include <locale>

using namespace std;

class employee
{
private:
    wstring name;
    long numb;
public:
    employee() : name(L"\0"), numb(0)
    {}
    employee(wstring nm, long nmb) : name(nm), numb(nmb)
    {}
    void get_data();
    void put_data() const;
};

int main()
{
    locale::global( locale( "" ) );
    ios::sync_with_stdio( false );
    const int MAX = 101;
    employee employees[MAX];
    wchar_t ch;
    int j = 0;
    do
    {
        employees[j].get_data();
        wcout << L"Продолжить ввод?(y/n): ";
        wcin >> ch;
        wcin.get();
        j++;
    } while( ch != 'n');
    for (int i =0; i < j; i++)
    {
        employees[i].put_data();
        wcout << endl;
    }
    return 0;
}

void employee::get_data()
{
    wcout << L"Введите имя сотрудника: ";
    getline( wcin, name );
    wcout << L"Введите номер сотрудника: ";
    wcin >> numb;

}
void employee::put_data() const
{
    wcout << L"Имя: " << name << L". Номер: " << numb;
}