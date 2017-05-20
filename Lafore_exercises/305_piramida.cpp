// 305_pirramida.cpp
// Created by stasich on 19.04.17.
//

#include <iostream>
using namespace std;

int main()
{
    int i,
        j,
        SumX = 1,
        KolX = 1;
    char x = 'x',
        pr = ' ';
    for (i = 1; i<20 ; i++)
    {
        SumX+=2;
    }
    for (i = 0; i <20; i++)
    {
        for (j = 0; j < (SumX/2-KolX/2); j++)
            cout << pr;
        for (j = 0; j < KolX; j++)
            cout << x;
        KolX+=2;
        cout << endl;
    }
    return 0;
}
