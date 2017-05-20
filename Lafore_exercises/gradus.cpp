//gradus.cpp
#include <iostream>
using namespace std;

int main()
{	
	float temper;
	cout<<"Введите температуру в градусах по Цельсию:\n";
	cin>>temper;
	temper=temper*9/5+32;
	cout<<"Температура по Фаренгейту: "<<temper<<endl;
	return 0;
}
