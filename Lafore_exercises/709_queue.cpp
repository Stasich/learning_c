// 709_queue.cpp
#include <iostream>
#include <string>
using namespace std;

class queue
{
    private:
        static const int MAX = 10;
        int arr[ MAX ];
        int head,tail, sum; // sum - количество элементов в очереди
    public:
        queue(): head( 0 ), tail( 0 ), sum( 0 ) {}
        void put( const int& data );
        int get();
};

int main() {
    queue qu1;
    string str = "add";
    int number;
    do {
        if ( str == "add" ) {
            cout << "Введите число для добавления в очередь: ";
            cin >> number;
            qu1.put(number);
        } else if ( str == "get" )
            cout << qu1.get() << endl;
        else
            cout << "Введённая строка не соответствует предложенным вариантам." << endl;
        cout << "Для добавления числа в очередь введите \"add\", "
             << "для извлечения из очереди введите \"get\", для выхода введите \"q\"." << endl;
        cin >> str;
    } while (str != "q");
    return 0;
}

void queue::put( const int &data ) {
    if ( sum == MAX )
        cout << "В очереди нет места." << endl;
    else
    {
        arr[ tail++ ] = data;
        sum++;
        if ( tail == MAX )
            tail = 0;
    }
}
int queue::get() {
    if ( sum == 0 ){
        cout << "Элементов в очереди: ";
        return 0;
    }
    else {
        int data = arr[head++];
        sum--;
        if (head == MAX)
            head = 0;
        return data;
    }
}