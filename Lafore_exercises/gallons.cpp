//gallons.cpp
#include <iostream>
using namespace std;

int main()
{
	float OneFut, size;
	int gallons;

	OneFut=7.481;	//1 кубический фут равен 7,481 галона
	cout<<"Введите число галонов:\n";
	cin>>gallons;
	size=gallons/OneFut;
	cout<<"Объём в кубических футах равен: "<<size<<endl;
	return 0;
}
