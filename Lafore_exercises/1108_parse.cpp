// 1108_parse.cpp
#include <iostream>
#include <string.h>
using namespace std;

class base_for_stack {
    public:
        virtual char getchar() = 0;
        virtual float getnumb() = 0;
};

class number : public base_for_stack
{
    private:
        float numb;
    public:
        number() : numb ( 0 ){}
        number( float n ) : numb ( n ) {}
        float getnumb();
        char getchar(){}
};

class Sign : public base_for_stack
{
    private:
        char sign;
    public:
        Sign() : sign ( '\0' ){}
        Sign( char s ) : sign ( s ) {}
        char getchar();
        float getnumb(){}
};

class Stack {
    private:
        static const int MAX = 100;
        base_for_stack* st [ MAX ];
        int top;
    public:
        Stack() : top ( 0 ){}
        void push ( base_for_stack* );
        base_for_stack* pop();
        void uptop()
            {top++;}
        int gettop()
            { return top;}

};

class express {
    private:
        char* pStr;
        Stack s;
        int size;
    public:
        express( char* str )
        {
            pStr = str;
            size = strlen ( pStr );
        }
        void parse();
        float solve();
};
/////////////////////////////////////////////////////////////
int main()
{
    char ans;
    char string1[100];
    cout << "Введите арифметическое выражение в виде 2+3*4/3-2"
         "\nНе используйте пробелы и скобки";
    do{
        cout << "\nВыражение: ";
        cin >> string1;
        cin.get();
        express* eptr = new express ( string1 );
        eptr->parse();
        cout << "Результат: " << eptr->solve() << endl;
        delete eptr;
        cout << "ещё? (y/n):";
        cin >> ans;
        cin.get();
    } while ( ans == 'y' );
    return 0;
}
//////////////////////////////////////////////////////////////////
float number::getnumb() {
    return numb;
}

char Sign::getchar() {
    return sign;
}

void Stack::push( base_for_stack* bs ) {
    st [ ++top ] = bs;
}

base_for_stack* Stack::pop() {
    return st[ top-- ];
}

void express::parse() {         //разираю строку, заполняю стек

    base_for_stack* lastval;
    base_for_stack* lastop;
    float integer = 0;          //для перевода char в float
    float decimal = 0;          // -.-
    int n = 0;                  // -.-
    char symbol;                //что бы читать было приятнее
    bool separator = false;     // для перевода в float, собощает что был разделитель целой части от десятичной
    for ( int j = 0; j <= size; j++ )    // перебираем всю пришедшую строку
    {
        symbol = pStr[j];
        if ( symbol != '/' && symbol != '*' && symbol != '+' && symbol != '-' && symbol != '\0' )
        {
            bool change = ( symbol == '.' || symbol == ',' ) ? true : false;
            if ( change )
                separator = true;
            if  ( !separator )
                integer = integer * 10 + ( symbol - 48 );
            else
            {
                if ( symbol != '.' && symbol != ',')
                {
                    decimal = decimal * 10 + ( symbol - 48 );
                    n++;
                }
            }
        }
        else                //если встретился знак операции или конца строки
        {
            for (int j = 0; j < n; j++)     //вычисляю десятичную часть
                decimal /=10;
            integer += decimal;             //итоговое float
            s.push( new number ( integer ) );   // помещаю число в стек
            integer = 0; decimal = 0; n =0; separator = false; //скидываю все переменные в 0
            if ( symbol != '\0'){
                if ( s.gettop() == 1 )      //если никакого знака операции в стеке нет
                    s.push( new Sign ( symbol ) );  //добавляем туда знак
                else
                {
                    lastval = s.pop();
                    lastop = s.pop();
                    if ( (symbol == '*' || symbol == '/') && (lastop->getchar() == '+' || lastop->getchar() == '-') )
                    {
                        s.uptop(); s.uptop();
                        //s.push( lastop );
                        //s.push( lastval );
                    } else
                    {
                        base_for_stack* lastlastval = s.pop();
                        switch ( lastop->getchar() ) {
                            case '+':
                                s.push(new number(lastlastval->getnumb() + lastval->getnumb()));
                                delete lastlastval; delete lastval; delete lastop;
                                break;
                            case '-':
                                s.push(new number(lastlastval->getnumb() - lastval->getnumb()));
                                delete lastlastval; delete lastval; delete lastop;
                                break;
                            case '/':
                                s.push(new number(lastlastval->getnumb() / lastval->getnumb()));
                                delete lastlastval; delete lastval; delete lastop;
                                break;
                            case '*':
                                s.push(new number(lastlastval->getnumb() * lastval->getnumb()));
                                delete lastlastval; delete lastval; delete lastop;
                                break;
                            default:
                                cout << "Неизвестный оператор.\n";
                        }
                    }
                    if ( symbol != '\0' )
                        s.push(new Sign(symbol));
                }
            }
        }
    }
}

float express::solve() {
    while ( s.gettop() > 1 )
    {
        base_for_stack* lastval = s.pop();
        base_for_stack* lastop = s.pop();
        base_for_stack* lastlastval = s.pop();
        switch ( lastop->getchar() )
        {
            case '+':
                s.push(new number(lastlastval->getnumb() + lastval->getnumb()));
                delete lastlastval; delete lastval; delete lastop;
                break;
            case '-':
                s.push(new number(lastlastval->getnumb() - lastval->getnumb()));
                delete lastlastval; delete lastval; delete lastop;
                break;
            case '/':
                s.push(new number(lastlastval->getnumb() / lastval->getnumb()));
                delete lastlastval; delete lastval; delete lastop;
                break;
            case '*':
                s.push(new number(lastlastval->getnumb() * lastval->getnumb()));
                delete lastlastval; delete lastval; delete lastop;
                break;
            default:
                cout << "Неизвестный оператор\n";
        }
    }
    return s.pop()->getnumb();
}