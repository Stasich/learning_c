// 1005_arrsum.cpp
#include <iostream>
using namespace std;

void sum_element( float*, float*, float*, int );

int main() {
    const int SZ = 80;
    float arr1[SZ];
    float arr2[SZ];
    float arr_sum[SZ];
    for (int j = 0; j < SZ; j++)
        *(arr1 + j) = j * 1.2;
    for (int j = 0, i = SZ; j < 80; j++, i--)
        *(arr2 + j) = i * 1.2;
    sum_element( arr1, arr2, arr_sum, SZ );
    for (int j = 0; j < SZ; j++)
        cout << *(arr1 + j) << " + " << *(arr2 + j) << " = " << *(arr_sum + j) << "  " << endl;
    cout << endl;
    return 0;
}

void sum_element ( float* ar1, float* ar2, float* ar3, int s ) {
    for ( int j = 0; j < s; j++ )
        *( ar3 + j ) = *( ar1 + j ) + *( ar2 + j );
}