// 1202_copy.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>          // для exit()
using namespace std;

void isFileExist ( char* file );
void isFileAbsent ( char* file );

int main( int argc, char* argv[] )
{
    if ( argc != 3 )                    //Должно быть обязательно 3 аргумента
        { cerr << "Не правильно введена команда. Пример: \"./1202_copy file1 file2\"\n"; exit(1); }
    isFileExist( argv[ 1 ] );           //Проверка сущестует ли копируемый файл
    isFileAbsent( argv[ 2 ] );          //Проверка не существует ли файл с таким же именем как создаваемый

    ifstream inf;
    ofstream outf;
    char ch;                            //символ для копирования
    inf.open ( argv [ 1 ] );
    outf.open ( argv [ 2 ] );
    while ( inf.get(ch) != 0 )
    {
        outf.put(ch);
    }
    cout << endl;
    return 0;
}

void isFileExist ( char* file ){
    ifstream inf;
    inf.open ( file );
    if ( !inf.good() )
    { cerr << "Файл \""<< file << "\" с таким названием не существует.\n"; exit(1);}
    inf.close();
}
void isFileAbsent ( char* file ){
    ifstream inf;
    inf.open ( file );
    if ( inf.good() )
    { cerr << "Файл \""<< file << "\" с таким названием уже существует.\n"; exit(1);}
    inf.close();
}