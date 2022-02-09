#include "Nag³ówek.h"



int main()
{
	
	GeometricSequence x1(2, 3);
	GeometricSequence x2(x1);
	GeometricSequence przenos(std::move(x2));


	system("pause");
	return 0;
}