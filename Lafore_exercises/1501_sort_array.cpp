// 1501_sort_array.cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    const int SIZE = 100;
    char ans;
    float arr[SIZE];
    int j;
    for ( j = 0; j < SIZE; j++ )
    {
        cout << "Введите число: ";
        cin >> arr[ j ];
        cout << "Повторить? (y/n):";
        cin >> ans;
        cin.ignore( 10, '\n' );
        if ( ans == 'n' )
            break;
    }
    sort( arr, arr + j);
    for ( int k = 0; k < j; k++ )
        cout << arr[k] << " ";
    cout << endl;
    return 0;
}