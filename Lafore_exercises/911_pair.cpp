// 911_pair.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

struct pair1
{
    int x;
    int y;
};
class Stack
{
    protected:
        static const int MAX = 4;
        int st[ MAX ];
        int top;
    public:
        Stack()
            { top = -1; }
        void push ( int var );
        int pop ();
};

class pairStack : public Stack
{
    public:
        pairStack() : Stack() {}
        void push ( pair1 p2 );
        pair1 pop ();
};



void Stack::push(int var) {
    if ( top >= MAX -1 )
        { cout << "Ошибка, стек полон.\n"; exit(1);}
    st[ ++top ] = var;
}

int Stack::pop(){
    if ( top < 0 )
        { cout << "Ошибка, стек пуст.\n"; exit(1);}
    return st[ top-- ];
}

void pairStack::push( pair1 p2 ) {
    Stack::push( p2.x );
    Stack::push( p2.y );
}

pair1 pairStack::pop() {
    pair1 temp;
    temp.y = Stack::pop();
    temp.x = Stack::pop();
    return temp;
}

int main()
{
    pair1 p1;
    pairStack ps1;
    char ch;
    while ( ch != 'n' )
    {
        cout << "Введите через пробел значения \"x\" и \"y\": "; cin >> p1.x >> p1.y;
        cout << "Кладу в стек..." << endl;
        ps1.push( p1 );
        cout << "Повторить?(y/n): ";
        cin >> ch;
    }
    ch = '\0';
    while ( ch != 'n' )
    {
        p1 = ps1.pop();
        cout << "Достал из стека х = " << p1.x << " , y = " << p1.y << endl;
        cout << "Повторить?(y/n): ";
        cin >> ch;
    }
    return 0;
}