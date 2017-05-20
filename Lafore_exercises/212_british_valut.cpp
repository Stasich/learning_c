//220_british_valut.cpp
#include <iostream>
using namespace std;

int main()
{
	int OldFunt, OldShiling, OldPeni, NewPeni, NewFunt, SumNewPeni;
	float SumOldPeni;
	char point='.';
	cout<<"Введите сумму в новом формате, в виде Ja.b: J";
	cin>>NewFunt>>point>>NewPeni;
	SumNewPeni=NewFunt*100+NewPeni;
	SumOldPeni=SumNewPeni*2.4;
	OldFunt=SumOldPeni/240;
	OldShiling=(SumOldPeni-OldFunt*240)/12;
	OldPeni=SumOldPeni-OldFunt*240-OldShiling*12;
	cout<<"Сумма в старом формате: J"<<OldFunt<<point<<OldShiling<<point<<OldPeni<<endl;
	return 0;
}
