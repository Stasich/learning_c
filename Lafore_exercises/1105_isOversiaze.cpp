// 1105_isOversize.cpp
#include <iostream>
using namespace std;

class publication {
    private:
        string name;
        float cost;
    public:
        publication() : name ( "None" ), cost ( 0.0 ){}
        virtual void getdata();
        virtual void putdata();
        virtual ~publication() {}
        virtual bool isOversize(){}
};

class book : public publication {
    private:
        int pages;
    public:
        book() : publication(), pages ( 0 ) {}
        void getdata();
        void putdata();
        bool isOversize();
};

class tape : public publication {
    private:
        float rectime;
    public:
        tape() : publication(), rectime ( 0.0 ) {}
        void getdata();
        void putdata();
        bool isOversize();
};

int main()
{
    publication* arr[ 100 ];
    char ch;
    int n = 0;
    do
    {
        cout << "Вводим данные книги(b) или аудиокниги(a)? (b/a): ";
        cin >> ch;
        if ( ch == 'b' )
            arr [ n ] = new book;
        else if ( ch == 'a' )
            arr [ n ] = new tape;
        else
        {
            cout << "Вы ошиблись при вводе.\n";
            continue;
        }
        cin.get();
        arr [ n ]->getdata();
        n++;
        cout << "Продолжить ввод? (y/n): "; cin >> ch; cin.get();
    } while ( ch != 'n' );
    for ( int j = 0; j < n; j++ ) {
        arr [ j ]->putdata();
        if ( arr [ j ]->isOversize() )
            cout << " Превышение размера! ";
        cout << endl;
    }
    return 0;
}

void publication::getdata() {
    cout << "Введите название книги: "; getline ( cin, name );
    cout << "Введите стоимость: "; cin >> cost; cin.get();
}
void publication::putdata() {
    cout << "Название: " << name << ". Цена: " << cost;
}
void book::getdata() {
    publication::getdata();
    cout << "Введите количество сраниц: "; cin >> pages; cin.get();
}
void book::putdata() {
    publication::putdata();
    cout << ". Страниц: " << pages;
}
void tape::getdata() {
    publication::getdata();
    cout << "Введите продолжительность касеты: "; cin >> rectime; cin.get();
}
void tape::putdata() {
    publication::putdata();
    cout << ". Длительность: " << rectime;
}

bool book::isOversize() {
    if ( pages > 800 )
        return true;
    else
        return false;
}

bool tape::isOversize() {
    if ( rectime > 90 )
        return true;
    else
        return false;
}