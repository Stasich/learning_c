// 1008_linklist.cpp
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
        linklist() { first = NULL;}
        void additem( int d );
        void display();
};

int main()
{
    linklist ll;
    ll.additem( 1 );
    ll.additem( 2 );
    ll.additem( 3 );
    ll.additem( 4 );
    ll.additem( 5 );
    ll.additem( 6 );
    ll.additem( 7 );
    ll.display();
    return 0;
}

void linklist::additem(int d) {
    if ( first == NULL )
    {
        link* newlink = new link;
        newlink->data = d;
        newlink->next = first;
        first = newlink;
    }
    else {
        link *current = first;
        while ( current->next ) {
            current = current->next;
        }
        link *newlink = new link;
        newlink->data = d;
        newlink->next = current->next;
        current->next = newlink;
    }
}

void linklist::display() {
    link* current = first;
    while( current )
    {
        cout << current->data << endl;
        current = current->next;
    }
}