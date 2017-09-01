// 1011_classarr.cpp для смены комита
#include <iostream>
using namespace std;

class arr1
{
    private:
        int* arr [ 10 ];
    public:
        arr1() {
            for ( int j = 0; j < 10; j++ )      //выделяю в памяти место под 10 массивов из 10 int элементов
            *(arr + j) = new int [10];
        }
        int& operator[] ( int n ){
            int j = n / 10;
            int i = n%10;
            return *( *(arr + j) + i );
        }
    ~arr1() {
        for ( int j = 0; j < 10; j++ ){
            cout << "Освобождаю память.  ";
            delete [] *( arr + j );}
        cout << endl;
    }
};

int main()
{
    arr1 a1;
    for ( int j = 0; j < 100; j++ )
        a1[ j ] = j;
    for ( int j = 0; j < 100; j++ )
        cout << a1[ j ] << " ";
    cout << endl;
    return 0;
}