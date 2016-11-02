#include <iostream>
using namespace std;

int main()
{
	int i=0;
	int sum=0;
	do {
	i++;
	sum +=i;
	} while (i<1000);
	cout<<"Сумма чисел 1 до 1000 = "<<sum<<endl;
	return 0;
}
