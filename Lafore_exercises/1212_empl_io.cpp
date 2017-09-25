// empl_io.cpp
#include <fstream>
#include <iostream>
#include <typeinfo> // для typeid()
#include <stdlib.h> // для exit()
using namespace std;

const int LEN = 32;
const int MAXEM = 100;

enum employee_type { tmanager, tscientist, tlaborer };

class employee
{
    private:
        char name [ LEN ];
        unsigned long number;
        static int n;
        static employee* arrap[];
    public:
        virtual void getdata()
        {
            cin.ignore( 10, '\n' );
            cout << "Введите фамилию: "; cin >> name;
            cout << "Введите номер: "; cin >> number;
        }
        virtual void putdata()
        { cout << "\n Фамилия: " << name << "\n Номер: " << number; }
        virtual employee_type get_type();
        static void add();
        static void display();
        static void read();
        static void write();
        static void find();
};
int employee::n;
employee* employee::arrap[MAXEM];

class manager: public employee
{
    private:
        char title[LEN];
        double dues; //налоги
    public:
        void getdata()
        {
            employee::getdata();
            cout << "Введите title: "; cin >> title;
            cout << "Введите налоги: "; cin >> dues;
        }
        void putdata()
        {
            employee::putdata();
            cout << "\n Title: " << title << "\n Налоги: " << dues;
        }
};

class scientist : public employee
{
    private:
        int pubs;
    public:
        void getdata()
        {
            employee::getdata();
            cout << "Введите число побликаций: "; cin >> pubs;
        }
        void putdata()
        {
            employee::putdata();
            cout << "\n Публикаций: " << pubs;
        }
};

class laborer : public employee
{};
/////////////////////////////////////////////////////
int main()
{
    char ch;
    while (true)
    {
        cout << "'a' - добавление сведений о сотруднике"
                "\n'd' - вывести сведение обо всех работниках"
                "\n'w' - записать все данные в файл"
                "\n'r' - прочитать все данные из файла"
                "\n'f' - поиск"
                "\n'x' - выход"
                "\nВаш выбор: ";
        cin >> ch;
        switch ( ch )
        {
            case 'a': employee::add(); break;
            case 'd': employee::display(); break;
            case 'w': employee::write(); break;
            case 'r': employee::read(); break;
            case 'f': employee::find(); break;
            case 'x': exit(0);
            default: cout << "\nНеизвестная команда";
        }
    }
    return 0;
}
////////////////////////////////////////////////////
void employee::add() {
    char ch;
    cout << "'m' для добавления менеджера"
            "\n's' для добавления учёного"
            "\n'l' для добавления рабочего"
            "\nВаш выбор: ";
    cin >> ch;
    switch ( ch )
    {
        case 'm' : arrap[n] = new manager; break;
        case 's' : arrap[n] = new scientist; break;
        case 'l' : arrap[n] = new laborer; break;
        default:
            cout << "Неизвестный тип работника\n"; return;
    }
    arrap[ n++ ]->getdata();
}
//-----------------------------------------------------------
void employee::display() {
    for ( int j = 0; j < n; j++ )
    {
        cout << (j+1);
        switch ( arrap[j]->get_type() )
        {
            case tmanager: cout << ". Тип: менеджер"; break;
            case tscientist: cout << ". Тип: учёный"; break;
            case tlaborer: cout << ". Тип: рабочий"; break;
            default:
                cout << "неизвестный тип.";
        }
        arrap[j]->putdata();
        cout << endl;
    }
}
//-----------------------------------------------------------
employee_type employee::get_type() {
    if ( typeid( *this ) == typeid( manager ) )
        return tmanager;
    else if ( typeid( *this ) == typeid( scientist ) )
        return tscientist;
    else if ( typeid( *this ) == typeid( laborer ) )
        return tlaborer;
    else
    {cerr << "\nНеправильный тип работника!"; exit(1);}
}
//-----------------------------------------------------------
void employee::write() {
    int size;
    cout << "Идёт запись " << n << " работников.\n";
    ofstream ouf;
    employee_type etype;
    ouf.open( "employ.dat", ios::trunc | ios::binary );
    if ( !ouf )
    { cout << "\nНевозможно открыть файл\n"; return;}
    for ( int j = 0; j < n; j++ )
    {
        etype = arrap[ j ]->get_type();
        ouf.write( (char*)&etype, sizeof( etype ) );    //
        switch ( etype )
        {
            case tmanager: size = sizeof(manager); break;
            case tscientist: size = sizeof(scientist); break;
            case tlaborer: ; size = sizeof(laborer); break;
        }
        ouf.write( (char*)(arrap[j]), size );
        if ( !ouf )
        { cout << "\nЗапись в файл невозможна\n"; return;}
    }
}
//-------------------------------------------
void employee::read() {
    int size;
    employee_type etype;
    ifstream inf;
    inf.open( "employ.dat", ios::binary );
    if (!inf)
    {cout << "\nНевозможно открыть файл\n"; return;}
    n = 0;
    while (true)
    {
        inf.read( (char*)&etype, sizeof(etype) );
        if ( inf.eof() )
            break;
        if ( !inf )
        { cout << "\nНевозможно чтение типа\n"; return;}
        switch ( etype )
        {
            case tmanager:
                arrap[n] = new manager;         // стоит ли удалять сначала те данные на которые массив ссылался до этог?
                size = sizeof( manager );
                break;
            case tscientist:
                arrap[n] = new scientist;
                size = sizeof ( scientist );
                break;
            case tlaborer:
                arrap[n] = new laborer;
                size = sizeof ( laborer );
                break;
            default: cout << "\nНеизвестный тип в файле\n"; return;
        }
        inf.read( (char*)(arrap[n]), size );
        if ( !inf )
        { cout << "\nЧтение данных из файла невозможно\n"; return;}
        n++;
    }
    cout << "Идёт чтение " << n << " работников\n";
}

void employee::find()
{
    int numb, size;
    employee_type etype;
    employee* temp;
    cout << "Введите личный номер сотрудника: "; cin >> numb;
    ifstream inf ( "employ.dat", ios::binary );
    while ( true )
    {
        inf.read ( reinterpret_cast<char*>(&etype), sizeof(etype) );
        if ( inf.eof() )
            {cout << "Такого сотрудника нет\n"; break;}
        if ( !inf )
            {cerr << "Ошибка чтения файла\n"; exit(1); }
        switch ( etype )
        {
            case tmanager:
                temp = new manager;
                size = sizeof(manager);
                break;
            case tscientist:
                temp = new scientist;
                size = sizeof(scientist);
                break;
            case tlaborer:
                temp = new laborer;
                size = sizeof(laborer);
                break;
            default:
                cout << "Неизвестный тип\n";
                exit(1);
        }
        inf.read( reinterpret_cast<char*>( temp ), size );
        if ( !inf )
            { cerr << "Невозможно считать объект\n"; exit(1);}
        if ( temp->number == numb ) {
            temp->putdata();
            break;
        }
    }
    cout << endl;
    inf.close();
}