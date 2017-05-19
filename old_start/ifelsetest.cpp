#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	double num;
	
	cout<<"Введите любое число"<<endl;
	cin>>num;
	
	if (num<10) {
		cout<<"Число меньше 10"<<endl;
	}else if (num==10) {
		cout<<"Число равно 10"<<endl;
	}else {
		cout<<"Число больше 10"<<endl;		
	}
}
