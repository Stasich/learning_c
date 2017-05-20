//210_british_valut.cpp
#include <iostream>
using namespace std;

int main()
{
	int OldFunt, OldShiling, OldPeni, NewPeni, NewFunt, SumOldPeni;
	float SumNewPeni;
	char point='.';
	cout<<"Введите сумму в старом формате, в виде Ja.b.c: J";
	cin>>OldFunt>>point>>OldShiling>>point>>OldPeni;
	SumOldPeni=OldFunt*240+OldShiling*12+OldPeni;
	SumNewPeni=SumOldPeni/2.4;
	NewFunt=SumNewPeni/100;
	NewPeni=static_cast<int>(SumNewPeni)%100;
	cout<<"Сумма в новом формате: J"<<NewFunt<<point<<NewPeni<<endl;
	return 0;
}
