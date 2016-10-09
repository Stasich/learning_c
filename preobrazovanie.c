/*перевод сантиметров в дймы и обратно*/
#include <iostream>
using namespace std;

int main ()
{
	const float fac=2.54;
	float x, in, cm;
	char rz=0;

	cout << "Vvedite dlinu\n";
	cin >> x;
	cout << "Vvedite razmernost. c(cm)/d(duim)\n";
	cin >> rz;
	if (rz=='c')
	{
	cm=x;
	in=x*fac;
	cout << cm << "cm = " << in << " d\n";
	}
	else
	{
		if (rz=='d')
		{
		in=x;
		cm=x/fac;
		cout << in << "d = " << cm << " cm\n";
		}
		else
		{
		cout << "Vi ne vveli ili ne pravilno vveli razmernost";
		}

	}
}
