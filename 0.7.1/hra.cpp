#include "knih.h"

void player::hra_standard()
{
	string tr;
	char znak[2];
	char strana[6] = " SVJZ";
	int vyb;
	switch(trida)
	{
		case 1:
			tr = "Warrior";
			break;
		
		case 2:
			tr = "Governor";
			break;
		
		case 3:
			tr = "Sprinter";
			break;
		
		case 4:
			tr = "Plebejec";
			break;
	}
	
	while(1)
	{
		system("cls");
		
		if(hp<=0)
		{
			endtitle();
		}
		lvl_check();
		
		printf("\n\t\tMOD: Normal");
		printf("\n\t%s                   %s",tr.c_str(),jmeno.c_str());
		printf("\n\tPocet HP: %d   Krok v tahu: %d/5",hp,podtah);
		printf("\n\t%d|%d     %c      Tah: %d  Level: %d  XP: ",poz_x-10000,poz_y-10000,strana[smer],tah,lvl);
		lvl_zobraz();
		printf("\n\n\t  1 - Jit dopredu");
		printf("\n\t  2 - Otocit se doprava");
		printf("\n\t  3 - Otocit se doleva");
		printf("\n\t  4 - Otocit se dozadu");
		printf("\n\t  5 - Ukoncit kolo");
		printf("\n\t  6 - Ulozit hru");
		printf("\n\t  7 - Inventar");
		printf("\n\t  8 - Zobrazit vlastnosti");
		printf("\n\t  9 - Farmarske menu");
		printf("\n\t  A - Achievementy");
		printf("\n\t  U - Ulozit hru na vlastni slot");
		printf("\n\t  I - Nacist hru z vlastniho slotu");
		printf("\n\tESC - Konec");
		printf("\n\n\tVyber: ");
		usleep(500000);
		znak[0] = getch();
		vyb = atoi(znak);
		
		if(znak[0] == 0x1B)
		{
			vyb = 0x1B;
		}
		
		if(znak[0] == 0x41 || znak[0] == 0x61)
		{
			vyb = 0x41;
		}
		
		if(znak[0] == 0x55 || znak[0] == 0x75)
		{
			vyb = 0x55;
		}
		
		if(znak[0] == 0x49 || znak[0] == 0x69)
		{
			vyb = 0x49;
		}
		
		switch(vyb)
		{
			case 1:
				switch(smer)
				{
					case 1:
						poz_y++;
						break;
					
					case 2:
						poz_x++;
						break;
					
					case 3:
						poz_y--;
						break;
					
					case 4:
						poz_x--;
						break;
				}
				podtah++;
				stepevent();
				
				if(podtah > 5)
				{
					podtah = 0;
					tah++;
					turnevent();
					konec_tahu();
					xp += 4;
				}
				
				if(typ_hry == 1)
				{
					kroky++;
				}
				
				break;
			
			case 2:
				smer++;
				if(smer>4)
				{
					smer = smer - 4;
				}
				break;
				
			case 3:
				smer--;
				if(smer<1)
				{
					smer = smer + 4;
				}
				break;
				
			case 4:
				smer = smer + 2;
				if(smer > 4)
				{
					smer = smer - 4;
				}
				break;
				
			case 5:
				tah++;
				podtah = 0;
				turnevent();
				konec_tahu();
				break;
				
			case 6:
				ulozit_hru();
				break;
				
			case 7:
				inventar();
				break;
				
			case 8:
				vlastnosti();
				break;
				
			case 9:
				farm_menu();
				break;
				
			case 0x41:
				achievement_menu();
				break;
				
			case 0x55:
				slots_save();
				break;
			
			case 0x49:
				slots_load();
				break;
				
			case 0x1B:
				logout();
				longjmp(jumpBuf,1);	
				
			default: break;
		}
		autosave();
	}
}

void player::hra_custom()
{
	string tr;
	char znak[2];
	char strana[6] = " SVJZ";
	int vyb;
	switch(trida)
	{
		case 1:
			tr = "Warrior";
			break;
		
		case 2:
			tr = "Governor";
			break;
		
		case 3:
			tr = "Sprinter";
			break;
		
		case 4:
			tr = "Plebejec";
			break;
	}
	
	while(1)
	{
		system("cls");
		
		if(hp<=0)
		{
			endtitle();
		}
		lvl_check();
		
		printf("\n\t\tMOD: Custom");
		printf("\n\t%s                   %s",tr.c_str(),jmeno.c_str());
		printf("\n\tPocet HP: %d   Krok v tahu: %d/5",hp,podtah);
		printf("\n\t%d|%d     %c      Tah: %d  Level: %d  XP: ",poz_x-10000,poz_y-10000,strana[smer],tah,lvl);
		lvl_zobraz();
		printf("\n\n\t  1 - Jit dopredu");
		printf("\n\t  2 - Otocit se doprava");
		printf("\n\t  3 - Otocit se doleva");
		printf("\n\t  4 - Otocit se dozadu");
		printf("\n\t  5 - Ukoncit kolo");
		printf("\n\t  6 - Ulozit hru");
		printf("\n\t  7 - Inventar");
		printf("\n\t  8 - Zobrazit vlastnosti");
		printf("\n\t  9 - Farmarske menu");
		printf("\n\t  A - Achievementy [Nejsou dostupne v rezimu custom]");
		printf("\n\t  U - Ulozit hru na vlastni slot");
		printf("\n\t  I - Nacist hru z vlastniho slotu");
		printf("\n\tESC - Konec");
		printf("\n\n\tVyber: ");
		usleep(500000);
		znak[0] = getch();
		vyb = atoi(znak);
		
		if(znak[0] == 0x1B)
		{
			vyb = 0x1B;
		}
		
		if(znak[0] == 0x41 || znak[0] == 0x61)
		{
			vyb = 0x41;
		}
		
		if(znak[0] == 0x55 || znak[0] == 0x75)
		{
			vyb = 0x55;
		}
		
		if(znak[0] == 0x49 || znak[0] == 0x69)
		{
			vyb = 0x49;
		}
		
		switch(vyb)
		{
			case 1:
				switch(smer)
				{
					case 1:
						poz_y++;
						break;
					
					case 2:
						poz_x++;
						break;
					
					case 3:
						poz_y--;
						break;
					
					case 4:
						poz_x--;
						break;
				}
				podtah++;
				stepevent();
				
				if(podtah > 5)
				{
					podtah = 0;
					tah++;
					turnevent();
					konec_tahu();
					xp += 4;
				}
				
				if(typ_hry == 1)
				{
					kroky++;
				}
				
				break;
			
			case 2:
				smer++;
				if(smer>4)
				{
					smer = smer - 4;
				}
				break;
				
			case 3:
				smer--;
				if(smer<1)
				{
					smer = smer + 4;
				}
				break;
				
			case 4:
				smer = smer + 2;
				if(smer > 4)
				{
					smer = smer - 4;
				}
				break;
				
			case 5:
				tah++;
				podtah = 0;
				turnevent();
				konec_tahu();
				break;
				
			case 6:
				ulozit_hru();
				break;
				
			case 7:
				inventar();
				break;
				
			case 8:
				vlastnosti();
				break;
				
			case 9:
				farm_menu();
				break;
				
			case 0x41:
				break;
				
			case 0x55:
				slots_save();
				break;
			
			case 0x49:
				slots_load();
				break;
				
			case 0x1B:
				logout();
				longjmp(jumpBuf2,1);
		}
		autosave();
	}
}

void player::hra_ironman()
{
	string tr;
	char znak[2];
	char strana[6] = " SVJZ";
	int vyb;
	switch(trida)
	{
		case 1:
			tr = "Warrior";
			break;
		
		case 2:
			tr = "Governor";
			break;
		
		case 3:
			tr = "Sprinter";
			break;
		
		case 4:
			tr = "Plebejec";
			break;
	}
	
	while(1)
	{
		system("cls");
		
		if(hp<=0)
		{
			endtitle();
		}
		lvl_check();
		
		printf("\n\t\tMOD: IRON MAN");
		printf("\n\t%s                   %s",tr.c_str(),jmeno.c_str());
		printf("\n\tPocet HP: %d   Krok v tahu: %d/5",hp,podtah);
		printf("\n\t%d|%d     %c      Tah: %d  Level: %d  XP: ",poz_x-10000,poz_y-10000,strana[smer],tah,lvl);
		lvl_zobraz();
		printf("\n\n\t  1 - Jit dopredu");
		printf("\n\t  2 - Otocit se doprava");
		printf("\n\t  3 - Otocit se doleva");
		printf("\n\t  4 - Otocit se dozadu");
		printf("\n\t  5 - Ukoncit kolo");
		printf("\n\t  6 - Ulozit hru [Neni mozne v Iron Man rezimu]");
		printf("\n\t  7 - Inventar");
		printf("\n\t  8 - Zobrazit vlastnosti");
		printf("\n\t  9 - Farmarske menu");
		printf("\n\t  A - Achievementy");
		printf("\n\t  U - Ulozit hru na vlastni slot [Neni mozne v Iron Man rezimu]");
		printf("\n\t  I - Nacist hru z vlastniho slotu [Neni mozne v Iron Man rezimu]");
		printf("\n\tESC - Konec");
		printf("\n\n\tVyber: ");
		usleep(500000);
		znak[0] = getch();
		vyb = atoi(znak);
		
		if(znak[0] == 0x1B)
		{
			vyb = 0x1B;
		}
		
		if(znak[0] == 0x41 || znak[0] == 0x61)
		{
			vyb = 0x41;
		}
		
		if(znak[0] == 0x55 || znak[0] == 0x75)
		{
			vyb = 0x55;
		}
		
		if(znak[0] == 0x49 || znak[0] == 0x69)
		{
			vyb = 0x49;
		}
		
		switch(vyb)
		{
			case 1:
				switch(smer)
				{
					case 1:
						poz_y++;
						break;
					
					case 2:
						poz_x++;
						break;
					
					case 3:
						poz_y--;
						break;
					
					case 4:
						poz_x--;
						break;
				}
				podtah++;
				stepevent();
				
				if(podtah > 5)
				{
					podtah = 0;
					tah++;
					turnevent();
					konec_tahu();
					xp += 4;
				}
				
				if(typ_hry == 1)
				{
					kroky++;
				}
				
				break;
			
			case 2:
				smer++;
				if(smer>4)
				{
					smer = smer - 4;
				}
				break;
				
			case 3:
				smer--;
				if(smer<1)
				{
					smer = smer + 4;
				}
				break;
				
			case 4:
				smer = smer + 2;
				if(smer > 4)
				{
					smer = smer - 4;
				}
				break;
				
			case 5:
				tah++;
				podtah = 0;
				turnevent();
				konec_tahu();
				break;
				
			case 6:
				break;
				
			case 7:
				inventar();
				break;
				
			case 8:
				vlastnosti();
				break;
				
			case 9:
				farm_menu();
				break;
				
			case 0x41:
				achievement_menu();
				break;
			
			case 0x55:
				break;
			
			case 0x49:
				break;
				
			case 0x1B:
				logout();
				longjmp(jumpBuf3,1);
		}
		ulozit_hru();
	}
}

void player::vlastnosti()
{
	system("cls");
	printf("\n\tJmeno postavy: %s",jmeno.c_str());
	printf("\n\tLevel:       %d",lvl);
	printf("\n\tXP:          %d",xp);
	printf("\n\tUtok:        %d",utok);
	printf("\n\tObrana:      %d",obrana);
	printf("\n\tCharisma:    %d",charisma);
	printf("\n\tRychlost:    %d",rychlost);
	printf("\n\tPohyblivost: %d",pohyblivost);
	printf("\n\tSaveslot:    %d",slot1);
	getch();
}

void player::inventar()
{
	int vyber;
	char znak[2];
	
	invent:
	
	system("cls");
	printf("\n\tMince:       %d",mince);
	printf("\n\tJidlo:       %d",jidlo);
	printf("\n\tSeno:        %d",seno);
	printf("\n\tSeminka:     %d",seminka);
	
	printf("\n\n\t1 - Crafting jidla");
	printf("\n\t2 - Doplneni HP pomoci jidla");
	printf("\n\t3 - Zpet");
	printf("\n\n\tVyber: ");
	znak[0] = getch();
	vyber = atoi(znak);
	
	switch(vyber)
	{
		case 1:
			craft_meal();
			goto invent;
			break;
		
		case 2:
			eat_meal();
			goto invent;
			break;
		
		case 3:
			break;
		
		default:
			goto invent;
			break;
	}	
}

void player::craft_meal()
{
	int vyber;
	char znak[2];
	
	reset:
	system("cls");
	opak:
	
	printf("\n\t1 jidlo = 3 sena");
	printf("\n\tKolik chces vycraftit: ");
	cin >> vyber;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
	
	if(vyber*3 > seno)
	{
		printf("\n\tNemas dostatek sena!");
		goto opak;
	}
	else
	{
		seno -= vyber*3;
		jidlo += vyber;
		craftlog(vyber);
		xp += vyber;
	}
}

void player::eat_meal()
{
	int vyber;
	char znak[2];
	
	opak:
		
	if(jidlo > 0 && hp != 100)
	{
		printf("\n\n\tChces si doplnit zivoty jidlem?");
		printf("\n\t1 - ANO | 2 - NE");
		printf("\n\tVyber: ");
		znak[0] = getch();
		vyber = atoi(znak);
		
		if(vyber == 1)
		{
			if(hp > 90)
			{
				hp = 100;
			}
			else
			{
				hp += 10;
			}
			jidlo -= 1;
			
			if(typ_hry == 1)
			{
				doplnene_zivoty+=10;
			}
			
			eatlog();
			goto opak;
		}
 	}
 	else
 	{
 		if(hp == 90)
 		{
 			printf("\n\n\tMas plne zivoty!");
		}
		else
		{
		 	printf("\n\n\tNemas zadne jidlo!");
		}
 		getch();
	}
}

void player::farm_menu()
{
	char znak[2];
	int vyber;
	
	farm:
	system("cls");
	
	printf("\n\t\tFarmarske menu");
	printf("\n\n\t1 - Zasadit seminko na aktualni pozici");
	printf("\n\t2 - Sklidit aktualni pozici");
	printf("\n\t3 - Zobrazit zasazene pozice");
	printf("\n\t4 - Zpet");
	printf("\n\n\tVyber: ");
	znak[0] = getch();
	vyber = atoi(znak);
	
	switch(vyber)
	{
		case 1:
			zasad();
			goto farm;
			break;
			
		case 2:
			sklid();
			goto farm;
			break;
			
		case 3:
			zobraz_farm();
			goto farm;
			break;
			
		case 4:
			break;
	}
}

void player::zobraz_farm()
{
	system("cls");
	char radek[200], *p;
	int kol, pozx, pozy;
	FILE *f;
	
	string nazev = "harvest";
	nazev = nazev + (char) (slot1+0x30) + ".txt";
	
	chdir("harvest");
	
	f = fopen("temporary.txt","r");
	
	while(fgets(radek,200,f)!=NULL)
	{
		p = strtok(radek,"|");
		kol = atoi(p);
		p = strtok(NULL,"|");
		pozx = atoi(p);
		p = strtok(NULL,"|");
		pozy = atoi(p);
		
		printf("\n\tZasazeno v %d. kole\tPozice: %d|%d",kol,pozx-10000,pozy-10000);
	}
	
	fclose(f);
	
	chdir("..");
	
	sleep(1);
	getch();
}

void player::sklid()
{
	system("cls");
	char radek[200], *p, znak[2];
	int kol, pozx, pozy, shoda=0, vyber, buffer;
	FILE *f, *k;
	
	string nazev = "harvest", soubor, prikaz = "del ";
	nazev = nazev + (char) (slot1+0x30) + ".txt";
	prikaz = prikaz + "temporary.txt";
	
	chdir("harvest");
	
	f = fopen("temporary.txt","r");
	
	while(fgets(radek,200,f)!=NULL)
	{
		p = strtok(radek,"|");
		kol = atoi(p);
		p = strtok(NULL,"|");
		pozx = atoi(p);
		p = strtok(NULL,"|");
		pozy = atoi(p);
		
		if(pozx == poz_x && pozy == poz_y)
		{
			shoda++;
			buffer = kol;
		}
	}
	
	fclose(f);
	
	if(shoda == 0)
	{
		printf("\n\n\tBohuzel se zde zadne seminko nenachazi.");
		getch();
	}
	else
	{
		if(tah < buffer+5)
		{
			printf("\n\tSeminko se zde sice nachazi, ale jeste nevyrostlo.");
			printf("\n\tSeminku zbyva: %d kol pro rust", buffer+5-tah);
			getch();
		}
		else
		{
			printf("\n\tPrejes si vyrostle jidlo sklidit?");
			printf("\n\t1 - ANO | 2 - NE");
			printf("\n\n\tVyber: ");
			znak[0] = getch();
			vyber = atoi(znak);
			
			if(vyber == 1)
			{
				f = fopen("temporary.txt","r");
				k = fopen("temporary1.txt","w");
				
				while(fgets(radek,200,f)!=NULL)
				{
					p = strtok(radek,"|");
					kol = atoi(p);
					p = strtok(NULL,"|");
					pozx = atoi(p);
					p = strtok(NULL,"|");
					pozy = atoi(p);
					
					if(pozx != poz_x || pozy != poz_y)
					{
						fprintf(k,"%d|%d|%d|\n",kol,pozx,pozy);
					}
				}
				
				fclose(f);
				fclose(k);
				
				system(prikaz.c_str());
				prikaz = "copy temporary1.txt ";
				prikaz = prikaz + "temporary.txt";
				system(prikaz.c_str());
				system("del temporary1.txt");
				
				seno = seno + 3;
				
				int cislo = numgen(100);
				if(cislo < 20 ||(cislo > 45 && cislo < 65) || cislo > 90)
				{
					seminka++;
				}
				
				if(typ_hry == 1)
				{
					pocet_sklizni++;
				}
				
				xp += 3;
			}
		}
	}
	
	chdir("..");
}

void player::zasad()
{
	system("cls");
	char radek[200], *p, znak[2];
	int kol, pozx, pozy, shoda=0, vyber;
	FILE *f;
	
	string nazev = "harvest";
	nazev = nazev + (char) (slot1+0x30) + ".txt";
	
	chdir("harvest");
	
	f = fopen("temporary.txt","r");
	
	while(fgets(radek,200,f)!=NULL)
	{
		p = strtok(radek,"|");
		kol = atoi(p);
		p = strtok(NULL,"|");
		pozx = atoi(p);
		p = strtok(NULL,"|");
		pozy = atoi(p);
		
		if(pozx == poz_x && pozy == poz_y) shoda++;
	}
	
	fclose(f);
	
	if(shoda!=0)
	{
		printf("\n\n\tBohuzel jsi nemohl(a) zasadit seminko, jelikoz se zde uz jedno nachazi!");
		getch();
	}
	else
	{
		printf("\n\tPrejes si opravdu zde zasadit seminko?");
		printf("\n\t1 - ANO | 2 - NE");
		printf("\n\n\tVyber: ");
		znak[0]=getch();
		vyber = atoi(znak);
		
		if(vyber == 1)
		{
			f = fopen("temporary.txt","a");
			
			fprintf(f,"%d|%d|%d|\n",tah,poz_x,poz_y);
			
			fclose(f);
			
			seminka--;
		}
	}
	
	chdir("..");
}

void player::achievement_menu()
{
	system("cls");
	char buff[10];
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 0F");
	 usleep(10);
	printf("\n\t\tAchievementy:");
	
	printf("\n\n\tNovy dobrodruh");
	printf("\n\tUjdi vice nez 100 kroku:\t");
	if(kroky>100) {
	 SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else {
		SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",kroky); SetConsoleTextAttribute(hConsole, 15);}
		
	printf("\n\n\tDobrodruh");
	printf("\n\tUjdi vice nez 1000 kroku:\t");
	if(kroky>1000){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",kroky); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tCestovatel sveta");
	printf("\n\tUjdi vice nez 10000 kroku:\t");
	if(kroky>10000){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",kroky); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tStistko");
	printf("\n\tUprchni aspon jednou z boje:\t");
	if(pocet_uprchu>0){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else {	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",pocet_uprchu); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tUprchlik");
	printf("\n\tUprchni 10x z boje:\t\t");
	if(pocet_uprchu>9){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",pocet_uprchu); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tDruha sance");
	printf("\n\tDopln si 100HP:\t\t\t");
	if(doplnene_zivoty>=100){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",doplnene_zivoty); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tKocka");
	printf("\n\tDopln si 900HP:\t\t\t");
	if(doplnene_zivoty>=900){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",doplnene_zivoty); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tBuh");
	printf("\n\tDopln si 5000 a vice HP:\t");
	if(doplnene_zivoty>=5000){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",doplnene_zivoty); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tPocinajici vrah");
	printf("\n\tZabij jednoho soupere:\t\t");
	if(zabiti>=1){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",zabiti); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tVrahoun");
	printf("\n\tZabij vice nez 10 souperu:\t");
	if(zabiti>9){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",zabiti); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tSeriovy vrah");
	printf("\n\tZabij vice nez 50 souperu:\t");
	if(zabiti>49){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",zabiti); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tBylinkar");
	printf("\n\tZasad a sklid aspon 10 seminek:\t");
	if(pocet_sklizni>9){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",pocet_sklizni); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tFarmar");
	printf("\n\tZasad a sklid vice nez 100 seminek:\t");
	if(pocet_sklizni>99){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",pocet_sklizni); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tBaron farem");
	printf("\n\tZasad a sklid vice nez 500 seminek:\t");
	if(pocet_sklizni>499){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",pocet_sklizni); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tPlebejec");
	printf("\n\tDosahni 1. urovne:\t");
	if(lvl>0){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",lvl); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tVenkovsky hrdina");
	printf("\n\tDosahni 5. urovne:\t");
	if(lvl>4){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else {	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",lvl); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tVojak ve stribrne zbroji");
	printf("\n\tDosahni 10. urovne:\t");
	if(lvl>9){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",lvl); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tVeteran");
	printf("\n\tDosahni 15. urovne:\t");
	if(lvl>14){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",lvl); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tLegenda");
	printf("\n\tDosahni maximalni 20. urovne:\t");
	if(lvl>19){ SetConsoleTextAttribute(hConsole, 10); printf("Dosazeno"); SetConsoleTextAttribute(hConsole, 15);}
	else{ 	SetConsoleTextAttribute(hConsole, 12); printf("Nedosazeno\t(%d)",lvl); SetConsoleTextAttribute(hConsole, 15);}
	
	printf("\n\n\tScrollováním se pohybuj v seznamu achievementu nahoru a dolu.");
	
	getch();
	
	string retezec = "color ";
	
	retezec = retezec + obraz + text;
	
	system(retezec.c_str());
}
