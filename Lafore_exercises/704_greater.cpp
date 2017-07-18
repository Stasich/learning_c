// 704_greater.cpp
#include <iostream>
using namespace std;

int comparison( int [], int );
int main()
{
    const int SIZE = 10;
    int arr1[ SIZE ];
    for (int j = 0; j < SIZE; j++)
    {
        cout << "Введите " << j+1 << "-е число:";
        cin >> arr1[ j ];
    }
    cout << "Наибольший элемент имеет индекс j=" << comparison( arr1, SIZE )
         << " и значение: " << arr1[ comparison( arr1, SIZE ) ] << endl;
    return 0;
}
int comparison ( int arr[], int lenght )
{
    int index = 0;
    for (int j = 1; j < lenght; j++)
        if (arr[ j ] > arr[ index ])
            index = j;
    return index;
}