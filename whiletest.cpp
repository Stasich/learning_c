#include <iostream>
using namespace std;

int main()
{
	setlocale(0,"");
	int i=0;
	int sum=0;
	while (i<1000)
	{
	i++;
	sum +=i;
	}
	cout<<"сумма чисел от 1 до 1000 = "<<sum<<endl;
	return 0;
}
