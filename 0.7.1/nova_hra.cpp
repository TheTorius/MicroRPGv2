#include "knih.h"

void player::nova_hra()
{
	COORD c;
	c.X = 15;
	c.Y = 4;
	
	int iron = 2;
	
	system("echo Vítej cizinèe v této RPG høe. Nyní si projedeš poèátek");
	system("echo vytváøení nové postavy. Vyplò prosím následující formuláø");
	system("echo pro vytvoøení nové postavy:");
	printf("\n");
	system("echo Jméno postavy: ");
	system("echo Saveslot(1-3): ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	c.Y++;
	fflush(stdin);
	getline(cin,jmeno);
	reset:
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	cin >> slot1;
	
	if(cin.fail() || (slot1 > 3 || slot1 < 1))
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
	
	system("cls");
	
	system("echo Nyní si prosím vyber jednu ze tøíd. Vlasnosti");
	system("echo dané tøídy jsou uvedeny v závorkách.");
	
	printf("\n\t1 - Warrior");
	printf("\n\t2 - Governor");
	printf("\n\t3 - Sprinter");
	printf("\n\t4 - Plebejec");
	printf("\n\t5 - Custom [NEUMOZNUJE HRAT S ACHIEVEMENTY]\n\t");
	printf("\n\tVyber: ");
	
	reset2:
		
	cin >> trida;
	
	if(cin.fail() || (slot1 > 4 || slot1 < 1))
	{
		cin.clear();
		cin.ignore();
		goto reset2;
	}
	
	xp = 0;
	lvl = 0;
	hp = 100;
	poz_x = 10000;
	poz_y = 10000;
	smer = 1;
	tah = 0;
	podtah = 0;
	seno = 15;
	jidlo = 5;
	mince = 20;
	seminka = 5;
	
	if(trida > 0 && trida < 5)
	{
		re:
		system("cls");
		printf("\n\n\tChcete hrat na obtiznost IRON MAN?");
		printf("\n\t1 - ANO | 2 - NE : ");
		cin >> iron;
		
		if(cin.fail() || (iron < 1 || iron > 2))
		{
			cin.clear();
			cin.ignore();
			goto re;
		}
	}
	
	switch(trida)
	{
		
		case 1:
			utok = 5;
			obrana = 3;
			charisma = 0;
			rychlost = 2;
			pohyblivost = 2;
			typ_hry = 1;
			break;
			
		case 2:
			utok = 2;
			obrana = 1;
			charisma = 5;
			rychlost = 1;
			pohyblivost = 3;
			typ_hry = 1;
			break;
			
		case 3:
			utok = 1;
			obrana = 1;
			charisma = 1;
			rychlost = 5;
			pohyblivost = 4;
			typ_hry = 1;
			break;
			
		case 4:
			utok = 1;
			obrana = 1;
			charisma = 1;
			rychlost = 1;
			pohyblivost = 1;
			typ_hry = 1;
			break;
		
		case 5:
			custom_player();
			typ_hry = 2;
			break;
	}
	
	slot2 = 0;
	
	if(iron == 1)
	{
		typ_hry = 3;
	}
	
	nova_postava();     // LOGFILES
	login();			// LOGFILES
	
	switch(typ_hry)
	{
		case 1:
			hra_standard();
			break;
		
		case 2:
			hra_custom();
			break;
			
		case 3:
			hra_ironman();
			break;
	}
}

void player::custom_player()
{
	char znak[2];
	int vyber, counter = 0;
	COORD c;
	c.X = 15;
	c.Y = 4;
	
	next_step:
	
	system("cls");
	printf("\n\t1 - Utok:        %d",utok);
	printf("\n\t2 - Obrana:      %d",obrana);
	printf("\n\t3 - Charisma:    %d",charisma);
	printf("\n\t4 - Rychlost:    %d",rychlost);
	printf("\n\t5 - Pohyblivost: %d",pohyblivost);
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
	
	if(counter < 12)
	{
		goto next_step;
	}
}
