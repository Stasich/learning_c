//islower.cpp
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	char bukva;
	int result;
	cout<<"введите любую букву, заглавную или строчную:"<<endl;
	cin>>bukva;
	result=islower(bukva);
	cout<<result<<endl;
	return 0;
}
