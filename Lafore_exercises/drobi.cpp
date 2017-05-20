//drobi.cpp
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, ch, zn;
	char razdel='/';
	cout<<"Приводим к одному знаменателю выражение a/b+c/d"<<endl
	<<"Введите a/b: ";
	cin>>a>>razdel>>b;
	cout<<"Введите c/d: ";
	cin>>c>>razdel>>d;
	ch=a*d+c*b;
	zn=b*d;
	cout<<"Сумма равна: "<<ch<<"/"<<zn<<endl;
	return 0;
}
