// 710_matrix.cpp
#include <iostream>
using namespace std;

class matrix
{
    private:
        int arr[ 10 ][ 10 ];
        int rows, columns;
    public:
        matrix(): rows( 10 ), columns( 10 ) {}
        matrix( int r, int c ): rows( r ), columns ( c ) {}
        void putel ( int row, int column, int data);
        int getel ( int row, int column );
        int isInLimit( const int& row, const int& column ) const;
};

int main()
{
    matrix m1;
    int temp = 12345;
    m1.putel( 7, 4, temp );
    temp = m1.getel( 7, 4 );
    cout << "temp = " << temp << endl;
    return 0;
}

void matrix::putel(int row, int column, int data) {
    if ( isInLimit( row, column ) > 0 )
        arr[ row ][ column ] = data;
    else
        cout << "Выход за пределы массива.";
}

int matrix::getel( int row, int column ) {
    if ( isInLimit( row, column ) > 0 )
        return arr[ row ][ column ];
    else
        cout << "Выход за пределы массива.";
}
int matrix::isInLimit( const int& row, const int& column ) const{
    if ( row >= 0 && row < rows && column >= 0 && column < columns )
        return 1;
    else
        return -1;
}