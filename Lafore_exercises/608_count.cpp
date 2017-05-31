// 608_count.cpp

#include <iostream>
using namespace std;

class counter{
private:
    static int count;
    int number;
public:
    counter(){
        count++;
        number = count;
    }
    void my_number()const;
};

int counter::count = 0;

int main()
{
    counter c1, c2, c3;
    c1.my_number();
    c2.my_number();
    c3.my_number();
}

void counter::my_number() const {
    cout << "Мой номер: " << number << endl;
}