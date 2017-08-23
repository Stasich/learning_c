// 907_counten.cpp
#include <iostream>
using namespace std;

class Counter
{
    protected:
        int count;
    public:
        Counter() : count ( 0 ) {}
        Counter( int c ) : count ( c ) {}
        int get_count()
            { return count; }
        Counter operator++()
            { return Counter ( ++count ); }
};
class CounterDn : public Counter
{
    public:
        CounterDn () : Counter () {}
        CounterDn ( int c ): Counter ( c ) {}
        CounterDn operator-- ()
            { return CounterDn ( --count ); }
};

class CounterN : public CounterDn
{
    public:
        CounterN() : CounterDn () {}
        CounterN( int c ) : CounterDn ( c ) {}
        CounterN operator-- ( int )
              { return CounterN( count-- ); }
        CounterN operator-- () {
            CounterDn::operator--();
        }
        CounterN operator++ ( int )
            { return CounterN( count++ ); }
        CounterN operator++ ( )
            { CounterDn::operator++(); }
};


int main()
{
    CounterN c1;
    CounterN c2;
    ++c1; ++c1; c1++; --c1; c1--;
    ++c2; ++c2; c2++; --c2; c2--;

    cout << c1.get_count() << c2.get_count() << endl;
    return 0;
}