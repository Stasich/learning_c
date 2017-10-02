// 1403_exception.cpp
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <class T>
class Queue
{
private:
    static const int MAX = 3;
    T arr[ MAX ];
    int top, head, dataCount;
public:
    class Full{
        public:
            string s1;
            Full()  {s1 = "Can't save number. Queue is full";}
    };
    class Empty{
        public:
            string s1;
            Empty() {s1 = "queue is empty.";}
    };
    Queue() : top( 0 ), head( 0 ), dataCount( 0 ){}
    void push( T var );
    T pop();
};

int main()
{
    char ans;
    int number;
    Queue<int> qInt;
    Queue<float> qFloat;
    Queue<char> qChar;
    do {
        try {
            cout << "\nPress \'a\' for add"
                 << "\nPress \'g\' for get"
                 << "\nPress \'q\' for quit"
                 << "\nYour chose: ";
            cin >> ans;
            switch (ans) {
                case 'a':
                    cout << "Enter the number: ";
                    cin >> number;
                    qInt.push(number);
                    break;
                case 'g':
                    cout << qInt.pop() << endl;
                    break;
                case 'q':
                    cout << "Quit.\n";
                    break;
                default:
                    cout << "Wrong input\n";
            }
        }
        catch (Queue<int>::Empty e1) {
            cout << e1.s1 << endl;
        }
        catch (Queue<int>::Full f1) {
            cout << f1.s1 << endl;
        }
    } while ( ans != 'q' );

    return 0;
}

template <class T>
void Queue<T>::push(T var)
{
    if ( top == MAX && head == 0 )
        throw Full();
    else if ( top == MAX )
    {
        top = 0;
        arr[ top++ ] = var;
    }
    else if ( top == head && dataCount != 0 )
        throw Full();
    else
        arr[ top++ ] = var;
    dataCount++;
    //cout << "\nзаписано " << arr [top-1] << " top = " << top-1;
}

template <class T>
T Queue<T>::pop()
{
    if ( dataCount == 0 )
        throw Empty();
    if ( head == MAX )
        head = 0;
    dataCount--;
    //cout << "\nВзято " << arr[head] << " head = " << head;
    return (T)arr[ head++ ];
}