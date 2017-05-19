#include <iostream>
#include <string>

int main()
{
	std::string students[10]={
		"Стас-0", "Стас-1", "Стас-2", "Стас-3", "Стас-4", "Стас-5", "Стас-6", "Стас-7", "Стас-8", "Стас-9"
	};
	for (int i=0; i<10; i++) {
		std::cout<<students[i]<<std::endl;
	}
	return 0;
}
