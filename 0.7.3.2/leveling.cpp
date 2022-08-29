#include "knih.h"

void player::lvl_check()
{
	switch(lvl)
	{
		case 0: if(xp>=10) lvlup(); break;
		case 1: if(xp>=50) lvlup(); break;
		case 2: if(xp>=100) lvlup(); break;
		case 3: if(xp>=150) lvlup(); break;
		case 4: if(xp>=200) lvlup(); break;
		case 5: if(xp>=250) lvlup(); break;
		case 6: if(xp>=325) lvlup(); break;
		case 7: if(xp>=400) lvlup(); break;
		case 8: if(xp>=475) lvlup(); break;
		case 9: if(xp>=550) lvlup(); break;
		case 10: if(xp>=625) lvlup(); break;
		case 11: if(xp>=750) lvlup(); break;
		case 12: if(xp>=875) lvlup(); break;
		case 13: if(xp>=1000) lvlup(); break;
		case 14: if(xp>=1200) lvlup(); break;
		case 15: if(xp>=1400) lvlup(); break;
		case 16: if(xp>=1750) lvlup(); break;
		case 17: if(xp>=2100) lvlup(); break;
		case 18: if(xp>=2500) lvlup(); break;
		case 19: if(xp>=3000) lvlup(); break;
	}
}

void player::lvlup()
{
	char znak[2];
	int vyber, counter = 0;
	
	next_step:
	system("cls");
	printf("\n\tPovysil sis na uroven: %d",lvl+1);
	printf("\n\n\tProsim prerozdel si body do svych schopnosti: (Zbyvajici body: %d)",4-counter);
	printf("\n\tUtok: %d",utok);
	printf("\n\tObrana: %d",obrana);
	printf("\n\tCharisma: %d",charisma);
	printf("\n\tRychost: %d",rychlost);
	printf("\n\tPohyblivost: %d",pohyblivost);
	
	znak[0] = getch();
	vyber = atoi(znak);
	
	switch(vyber)
	{
		case 1:
			utok++;
			break;
			
		case 2:
			obrana++;
			break;
				
		case 3:
			charisma++;
			break;
				
		case 4:
			rychlost++;
			break;
				
		case 5:
			pohyblivost++;
			break;
		
		default:
			goto next_step;
	}
	counter++;
	
	if(counter < 4)
	{
		goto next_step;
	}
	
	lvl++;
	lvlup_log();
	system("cls");
}

void player::lvl_zobraz()
{
	switch(lvl)
	{
		case 0: printf("%d/10",xp); break;
		case 1: printf("%d/50",xp); break;
		case 2: printf("%d/100",xp); break;
		case 3: printf("%d/150",xp); break;
		case 4: printf("%d/200",xp); break;
		case 5: printf("%d/250",xp); break;
		case 6: printf("%d/325",xp); break;
		case 7: printf("%d/400",xp); break;
		case 8: printf("%d/475",xp); break;
		case 9: printf("%d/550",xp); break;
		case 10: printf("%d/625",xp); break;
		case 11: printf("%d/750",xp); break;
		case 12: printf("%d/875",xp); break;
		case 13: printf("%d/1000",xp); break;
		case 14: printf("%d/1200",xp); break;
		case 15: printf("%d/1400",xp); break;
		case 16: printf("%d/1750",xp); break;
		case 17: printf("%d/2100",xp); break;
		case 18: printf("%d/2500",xp); break;
		case 19: printf("%d/3000",xp); break;
	}
}
