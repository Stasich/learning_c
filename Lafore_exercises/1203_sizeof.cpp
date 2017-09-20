// 1203_sizeof.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main ( int argc, char* argv[] )
{
    if ( argc != 2 )
        { cerr << "Неправильно введена команда. Пример: \"./1203_sizeof file\"\n"; exit(1);}
    ifstream inf;
    inf.open ( argv [ 1 ] );
    if ( !inf )
        { cerr << "Невозможно открыть файл\n"; exit(1);}
    inf.seekg( 0, ios::end );
    int n = inf.tellg();
    cout << "Размер файла \"" << argv [ 1 ] << "\" = " << n << " bytes." << endl;
    return 0;
}