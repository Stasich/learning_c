#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int a,b;
	cout<<"Введите первое число"<<endl;
	cin>>a;
	cout<<"Введите второе число"<<endl;
	cin>>b;
	int c=a*b;
	cout<<"Произведение чисел А*Б = "<<c<<endl;
	return 0;
}
