// 1009_intarr10.cpp
#include <iostream>
using namespace std;

int main()
{
    int* arr [10];                      //массив указателей на массивы типа int
    for ( int j = 0; j < 10; j++ )      //выделяю в памяти место под 10 массивов из 10 int элементов
        *(arr + j) = new int [10];
    for ( int j = 0; j < 10; j++ )      //заполняю все массивы значениями
        for (int i = 0; i < 10; i++)
            *(*(arr + j) + i) = i * 10;
    for ( int j = 0; j < 10; j++ ){     //вывожу значение всех данных в массиве на экран
        cout << endl;
        for (int i = 0; i < 10; i++)
            cout << *(*(arr + j) + i) << " ";
    }
    for ( int j = 0; j < 10; j++ ){     //очищаю память
        delete [] *(arr + j);
    }
    cout << endl;
    return 0;
}