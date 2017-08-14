// 708_safearray.cpp
#include <iostream>
using namespace std;

class safearray {
    private:
        static const int LIMIT = 80;
        int arr[ LIMIT ];
    public:
        void putel( const int& index, const int& val );
        int getel( const int& index ) const;
        int isInLimit (const int& index ) const;
};

int main()
{
    safearray sa1;
    int indx, value;
    char ch;
    while ( ch != 'n' )
    {
        cout << "Введите через пробед индекс масива и значение: ";
        cin >> indx >> value;
        sa1.putel( indx, value );
        cout << "Введите номер елемента массива: ";
        cin >> indx;
        cout << "Array[ " << indx << " ] = " << sa1.getel( indx ) << endl;
        return 0;
    }
}

void safearray::putel(const int& index, const int& val)
{
    if ( isInLimit( index ) > 0 )
        arr[ index ] = val;
    else
        cout << "Выход за пределы границы массива." << endl;
}
int safearray::getel(const int& index) const
{
    if ( isInLimit( index ) > 0 )
        return arr[ index ];
    else
        cout << "Выход за пределы границы массива." << endl;
}

int safearray::isInLimit(const int &index) const
{
    if ( index >= 0 && index < LIMIT )
        return 1;
    else
        return -1;
}