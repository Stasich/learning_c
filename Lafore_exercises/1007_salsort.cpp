// 1007_salsort.cpp
#include <iostream>
#include <string>
using namespace std;

class person {
protected:
    string name;
public:
    person() : name ( "None" ) {}
    void setName ()
    { cout << "Введите имя: "; cin >> name; }
    void printName ()
    { cout << "Имя: " << name; }
    string getName()
    { return name; }
};
class person2 : public person {
private:
    float salary;
public:
    person2() : person(), salary ( 0.0 ) {}
    void setData();
    void printData();
    float getSalary();
};
void psort_salar( person2**, int );

int main()
{
    person2* arr[ 100 ];
    char ch;
    int n = 0;              // количество элементов
    while ( ch != 'n' )
    {
        arr[ n ] = new person2;
        arr[ n ]->setData();
        n++;
        cout << "Ещё?(y/n): "; cin >> ch;
    }
    cout << "Несортированный массив: \n";
    for ( int j = 0; j < n; j++ ){
        arr[ j ]->printData();
        cout << endl;
    }
    psort_salar( arr, n );
    cout << "Сортированный массив: \n";
    for ( int j = 0; j < n; j++ ){
        arr[ j ]->printData();
        cout << endl;
    }
    return 0;
}

void person2::setData() {
    person::setName();
    cout << "Введите зарплату: "; cin >> salary; cin.get();
}

void person2::printData() {
    person::printName();
    cout << ". З/п: " << salary;
}

float person2::getSalary() {
    return salary;
}

void psort_salar( person2** p, int size ){
    void order ( person2**, person2** );

    for ( int j = 0; j < size-1; j++)
        for ( int i = j + 1; i < size; i++ )
            order ( p + j, p + i );
}

void order ( person2** p1, person2** p2) {
    if ( (*p1)->getSalary() > (*p2)->getSalary() ){
        person2* temp = *p2;
        *p2 = *p1;
        *p1 = temp;
    }
}