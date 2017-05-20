//kurs_valut.cpp
#include <iostream>
using namespace std;

int main()
{
	float dollar, funtst, franc, gitler, iena;
	cout<<"Введите количество долларов для перевода в другие валюты: ";
	cin>>dollar;
	funtst=1/1.487*dollar;
	franc=1/0.172*dollar;
	gitler=1/0.584*dollar;
	iena=1/0.00955*dollar;
	cout<<dollar<<" доллар(ов) это:"<<endl
	<<"Фунт стерлингов: "<<funtst<<endl
	<<"Франков: "<<franc<<endl
	<<"Немецких марок: "<<gitler<<endl
	<<"Японских йен: "<<iena<<endl;
	return 0;

}
