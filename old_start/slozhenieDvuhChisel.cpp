#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int a,b;
	cout << "введите число: ";
	cin >> a;
	cout << "введите второе число: ";
	cin >> b;
	int c=a+b;
	cout << "сумма а + б = " << c <<endl;
	return 0;
}
