// 406_etype.cpp

#include <iostream>
#include "getch_stasich.h"
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
    etype prof;
    char ch;
    cout << "Введите первую букву должности "
            "(laborer, secretary, manager, accountant, executive, researcher): ";
    ch = getch();
    cout << ch;
    switch (ch)
    {
        case 'l': prof = laborer; break;
        case 's': prof = secretary; break;
        case 'm': prof = manager; break;
        case 'a': prof = accountant; break;
        case 'e': prof = executive; break;
        case 'r': prof = researcher; break;
        default: cout << "\nВы ввели не то, досвидания.\n   "; ch = '0';
    }
    if (ch != '0')
    {
        switch (prof)
        {
            case 0: cout << "\nПолное название должности: laborer\n"; break;
            case 1: cout << "\nПолное название должности: secretary\n"; break;
            case 2: cout << "\nПолное название должности: manager\n"; break;
            case 3: cout << "\nПолное название должности: accountant\n"; break;
            case 4: cout << "\nПолное название должности: executive\n"; break;
            case 5: cout << "\nПолное название должности: researcher\n"; break;
        }
    }
    return 0;
}