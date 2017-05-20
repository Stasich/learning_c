//211_setiosflags.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout<<setiosflags(ios::left)
	<<setw(9)<<"Familiia"<<setw(9)<<"Imia"<<setw(14)<<"adres"<<setw(18)<<"gorod"<<endl;
	cout<<setfill('-')<<setw(50)<<""<<endl;
	cout<<setfill(' ')<<setw(9)<<"Petrov"<<setw(9)<<"vasia"<<setw(14)<<"Klenovaia 16"<<setw(18)<<"Sankt-Peterburg"<<endl
	<<setw(9)<<"Ivanov"<<setw(9)<<"Serega"<<setw(14)<<"Osinovia 3"<<setw(18)<<"Nahodka"<<endl
	<<setw(9)<<"Sidorov"<<setw(9)<<"Ivan"<<setw(14)<<"Berezovaia 21"<<setw(18)<<"Kaliningrad"<<endl;
	return 0;
}
