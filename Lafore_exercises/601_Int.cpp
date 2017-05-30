// 601_Int.cpp

#include <iostream>
using namespace std;

class Int
{
private:
    int a;
public:
    Int() : a(0)
    {}
    Int(int x) : a(x)
    {}
    void showInt();
    void sumInt(Int, Int);
};

void Int::showInt() {
    cout << a;
}
void Int::sumInt(Int x, Int y) {
    a = x.a + y.a;
}

int main()
{
    Int first(3), second(10), sum;
    cout << "first: "; first.showInt();
    cout << "\nsecond: "; second.showInt();
    cout << "\nsum: "; sum.showInt();
    sum.sumInt(first, second);
    cout << "\nfirst: "; first.showInt();
    cout << "\nsecond: "; second.showInt();
    cout << "\nsum: "; sum.showInt(); cout << endl;
    return 0;
}