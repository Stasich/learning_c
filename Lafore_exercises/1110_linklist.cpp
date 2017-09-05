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
    linklist( linklist& ls );
    void additem ( int d );
    void display();
    linklist& operator= ( linklist& );
    ~linklist();
};

int main()
{
    linklist* li1 = new linklist;
    linklist li = *li1;
    li.additem(1);
    li.additem(2);
    li.additem(3);
    li.additem(5);
    li.additem(6);
    li.display();
    cout << endl;
    linklist li2( li );
    linklist li3 = li;

    delete  li1;
    li2.display();
    cout << endl;
    li3.display();
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
        //cout << "удаляю temp" << endl;
        delete temp;
    }
}

linklist::linklist(linklist &ls) {
    first = NULL;
    link* current = ls.first;
    while ( current )
    {
        link* temp = new link;
        temp->data = current->data;
        current = current->next;
        temp->next = first;
        first = temp;
    }
}

linklist& linklist::operator= ( linklist & ls) {
    delete this;
    first = NULL;
    link* current = ls.first;
    while ( current )
    {
        link* temp = new link;
        temp->data = current->data;
        temp->next = first;
        current = current->next;
        first = temp;
    }
    return *this;
}