#include "knih.h"

void player::stepevent()
{
	int gcislo;
	
	gcislo = numgen(100);
	
	if(gcislo < 5 || ((gcislo > 50 && gcislo < 55) || gcislo >95)) // �ANCE 15%
	{
		battle();
	}
}

void player::turnevent()
{
	int gcislo;
	
	gcislo = numgen(100);
	
	if(gcislo < 30 || ((gcislo > 40 && gcislo < 60) || gcislo > 80)) // �ANCE 70%
	{
		endturnevent();
	}
}
