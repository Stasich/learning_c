#include <iostream>
using namespace std;

int main()
{
	int i;
	int sum=0;
	setlocale(0, "");
	for (i=1; i<=1000; i++)
	{
		sum=sum+i;
	}
	cout<<"Сумма всех чисел от 1 до 1000 = "<<sum<<endl;
	return 0;
}
