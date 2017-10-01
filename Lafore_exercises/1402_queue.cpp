// 1402_queue.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class Queue
{
    private:
        static const int MAX = 3;
        T arr[ MAX ];
        int top, head, dataCount;
    public:
        Queue() : top( 0 ), head( 0 ), dataCount( 0 ){}
        void push( T var );
        T pop();
};

int main()
{
    char ans;
    Queue<int> qInt;
    Queue<float> qFloat;
    Queue<char> qChar;
    qInt.push(1);
    qInt.push(2);
    qInt.push(3);
    cout << "Test queue for integer: ";
    cout << qInt.pop() << " ";
    cout << qInt.pop() << " ";
    qInt.push(4);
    qInt.push(5);
    cout << qInt.pop() << " ";
    cout << qInt.pop() << " ";
    cout << qInt.pop() << endl;
    qFloat.push(1.1);
    qFloat.push(2.2);
    qFloat.push(3.3);
    cout << "Test queue for float: ";
    cout << qFloat.pop() << " ";
    cout << qFloat.pop() << " ";
    qFloat.push(4.4);
    qFloat.push(5.5);
    cout << qFloat.pop() << " ";
    cout << qFloat.pop() << " ";
    cout << qFloat.pop() << endl;
    qChar.push('H');
    qChar.push('e');
    qChar.push('l');
    cout << "Test queue for char: ";
    cout << qChar.pop() << " ";
    cout << qChar.pop() << " ";
    qChar.push('l');
    qChar.push('o');
    cout << qChar.pop() << " ";
    cout << qChar.pop() << " ";
    cout << qChar.pop() << endl;
    return 0;
}

template <class T>
void Queue<T>::push(T var)
{
    if ( top == MAX && head == 0 )
        { cout << "В очереди нет места\n"; return; }
    else if ( top == MAX )
    {
        top = 0;
        arr[ top++ ] = var;
    }
    else if ( top == head && dataCount != 0 )
        { cout << "В очереди нет места\n"; return; }
    else
        arr[ top++ ] = var;
    dataCount++;
    //cout << "\nзаписано " << arr [top-1] << " top = " << top-1;
}

template <class T>
T Queue<T>::pop()
{
    if ( dataCount == 0 )
        { cout << "Очередь пуста\n"; exit(1); }
    if ( head == MAX )
            head = 0;
    dataCount--;
    //cout << "\nВзято " << arr[head] << " head = " << head;
    return (T)arr[ head++ ];
}