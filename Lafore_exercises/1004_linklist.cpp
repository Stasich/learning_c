// 1004_linklist.cpp
#include <iostream>
using namespace std;

struct link
{
    int data;
    link* next;
};

class linklist
{
    private:
        link* first;
    public:
        linklist()
            { first = NULL; }
        void additem ( int d );
        void display();
        ~linklist();
};

int main()
{
    linklist li;
    li.additem(1);
    li.additem(2);
    li.additem(3);
    li.additem(5);
    li.additem(6);
    li.display();
    cout << endl;
    return 0;
}

void linklist::additem ( int d ) {
    link* newlink = new link;
    newlink -> data = d;
    newlink -> next = first;
    first = newlink;
}

void linklist::display() {
    link* current = first;
    while ( current )
    {
        cout << current->data << " ";
        current = current->next;
    }
}

linklist::~linklist() {
    link* current = first;
    while ( current )
    {
        link* temp = current;
        current = current->next;
        cout << "удаляю temp" << endl;
        delete temp;
    }
}