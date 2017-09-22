// 1008_linklist.cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Link
{
    int data;
    Link* next;
};

class LinkList
{
private:
    Link* first;
public:
    LinkList() { first = NULL;}
    void addItem( int d );
    void display();
    void addToFile();
    void getFromFile();

};

int main()
{
    LinkList linkList;
    char ch;
    int data;
    while ( ch != 'e' )
    {
        cout << "Для добавления элемента в список введите \"а\"\n"
             << "Для вывода всех данных введите \"d\"\n"
             << "Для записи данных в файл введите \"t\"\n"
             << "Для считывания данных из файла введите \"g\"\n"
             << "Для выхода введите \"e\"\n"
             << "Ваш выбор: ";
        cin >> ch;
        switch ( ch )
        {
            case 'a' :
                cout << "Введите число: ";
                cin >> data;
                linkList.addItem( data );
                break;
            case 'd' :
                linkList.display();
                break;
            case 't' :
                linkList.addToFile();
                break;
            case 'g' :
                linkList.getFromFile();
            case 'e':
                break;
            default:
                cout << "Не верно введён символ.\n";
        }
    }
    return 0;
}

void LinkList::addItem(int d) {
    if ( first == NULL )
    {
        Link* newLink = new Link;
        newLink->data = d;
        newLink->next = first;
        first = newLink;
    }
    else {
        Link *current = first;
        while ( current->next ) {
            current = current->next;
        }
        Link *newLink = new Link;
        newLink->data = d;
        newLink->next = current->next;
        current->next = newLink;
    }
}

void LinkList::display() {
    Link* current = first;
    while( current )
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void LinkList::addToFile()
{
    ofstream outFile ( "linklist.txt" );
    Link* current = first;
    outFile << current->data;
    current = current->next;
    while( current )
    {
        outFile << " " << current->data;
        current = current->next;
    }
}

void LinkList::getFromFile()
{
    int temp;
    ifstream inFile ( "linklist.txt" );
    while ( !inFile.eof() )
    {
        inFile >> temp;
        addItem( temp );
    }
}