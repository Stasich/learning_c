#include <iostream>
using namespace std;

int main()
{
	int i;
	int sum=0;
	int a;
	int b;
	setlocale(0, "");
	cout<<"Сложение всех целых  чисел между двумя заданными с шагом равным 1"<<endl<<"Введите первое целое число:"<<endl;
	cin>>a;
	cout<<"Введите второе целое число не меньше первого:"<<endl;
	cin>>b;
	for (i=a; i<=b; i++)
	{
		sum=sum+i;
	}
	cout<<"Сумма всех чисел от "<<a<<" до "<<b<<" = "<<sum<<endl;
	return 0;
}
