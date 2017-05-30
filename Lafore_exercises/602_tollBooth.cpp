// 602_tollBooth.cpp

#include <iostream>
#include "getch_stasich.h"
using namespace std;

class tollBooth
{
private:
    unsigned int car;
    double money;
public:
    tollBooth () : car(0), money(0.0)
    {}
    void payingCar() {
        car++;
        money += 0.5;
    }
    void nopayCar() {
        car++;
    }
    void display() const{
        cout << "\nмашин проехало: " << car << "\nДенег заплачено: " << money << endl;
    }
};

int main()
{
    tollBooth parking;
    char ch = 'w';
    cout << "Вводите \"w\" для заплатившей машины и \"s\" для не заплатившей: " << endl
            << "Для выхода нажмите ESC." << endl;
    while ((ch=getch()) != 27)
    {
        if (ch == 'w'){
            parking.payingCar();
            cout << "проехала - заплатила" << endl;
        }
        else if (ch == 's'){
            parking.nopayCar();
            cout << "проехала - не заплатила" << endl;
        }
        else
            cout << "Вы ввели не тот символ, вводите \"w\" для заплатившей машины и \"s\" для не заплатившей"
                 << endl;
    }
    parking.display();
    return 0;
}
