#include "knih.h"

void player::battle()
{
	int enemy_type=0;
	
	enemy_type = numgen(3);
	
	switch(enemy_type)
	{
		case 1:
			bandit();
			break;
		
		case 2:
			lesnizver();
			break;
		
		case 3:
			straz();
			break;
	}
	xp = xp + 10;
}

int player::numgen(int cislo)		// dvojúrovòový náhodný generátor èísel
{
	int i=0;
	int cislo1[12], vyb, vys = 5;
	
	time_t t;
	srand((unsigned)time(0));
	
	while(i<10)
	{
		cislo1[i] = 1+rand() % cislo;
//		printf("\ncislo: %d",cislo1[i]);
		i++;
	}
	
	i=0;
	
	srand((unsigned)time(0));
	vyb = rand()%10;
	
	vys = cislo1[vyb];
	
//	printf("\n\n\tVysledek: %d",vys);
//	getch();
	return vys;
}

void player::bandit()
{
	int gcislo=0, ct=0, bt=0;
	enemy bandit;
	char radek[100];
	char *p;
	FILE *f;
	
	if(lvl==0)
	{
		gcislo = 1 + 3;
	}
	else
	{
		gcislo = lvl + 3;
	}
	
	chdir("enemies");
	
	f = fopen("bandita.txt","r");
	
	while(fgets(radek,100,f)!=NULL)
	{
		p = strtok(radek,"|");
		bandit.nastavUTOK(atoi(p));
		p = strtok(NULL,"|");
		bandit.nastavOBRANA(atoi(p));
		p = strtok(NULL,"|");
		bandit.nastavCHARISMA(atoi(p));
		p = strtok(NULL,"|");
		bandit.nastavRYCHLOST(atoi(p));
		p = strtok(NULL,"|");
		bandit.nastavPOHYBLIVOST(atoi(p));
	}
	
	fclose(f);
	chdir("..");
	
	bandit.nastavHP(100);
	bandit.nastavLEVEL(numgen(gcislo));
	
	switch(bandit.ukazLEVEL())
	{
		case 1:
		
		case 2:
			bandit.nastavUTOK(bandit.ukazUTOK()+2);
			bandit.nastavOBRANA(bandit.ukazOBRANA()+1);
			bandit.nastavRYCHLOST(bandit.ukazRYCHLOST()+1);
			break;
		
		case 3:
			bandit.nastavUTOK(bandit.ukazUTOK()+3);
			bandit.nastavPOHYBLIVOST(bandit.ukazPOHYBLIVOST()+2);
			bandit.nastavRYCHLOST(bandit.ukazRYCHLOST()+1);
			break;
		
		case 4:
			bandit.nastavOBRANA(bandit.ukazOBRANA()+4);
			bandit.nastavCHARISMA(bandit.ukazCHARISMA()+2);
			bandit.nastavRYCHLOST(bandit.ukazRYCHLOST()+2);
			bandit.nastavPOHYBLIVOST(bandit.ukazPOHYBLIVOST()+1);
			break;
		
		case 5:
			bandit.nastavUTOK(bandit.ukazUTOK()+2);
			bandit.nastavCHARISMA(bandit.ukazCHARISMA()+1);
			bandit.nastavPOHYBLIVOST(bandit.ukazPOHYBLIVOST()+2);
			bandit.nastavOBRANA(bandit.ukazOBRANA()+1);
			break;
	}
	
	int counter=0, vysledek=0, sance, akce, counter2 = 0;
	
	reset:
	system("cls");
	printf("\n\n\tByl(a) jsi prepadnut(a) banditou!");
	printf("\n\tCo budes delat?");
	printf("\n\t1 - Bojovat");
	printf("\n\t2 - Pokusit se utect");
//	printf("\n\t3 - Pokusit se uplatit");
	printf("\n\t3 - Pokusit se domluvit");
		
	printf("\n\n\tTve attributy:");
	printf("\n\tUtok:        %d",utok);
	printf("\n\tObrana:      %d", obrana);
	printf("\n\tCharisma:    %d",charisma);
	printf("\n\tRychlost:    %d",rychlost);
	printf("\n\tPohyblivost: %d",pohyblivost);
		
	printf("\n\n\tAttributy soupere:");
	printf("\n\tUtok:        %d",bandit.ukazUTOK());
	printf("\n\tObrana:      %d",bandit.ukazOBRANA());
	printf("\n\tCharisma:    %d",bandit.ukazCHARISMA());
	printf("\n\tRychlost:    %d",bandit.ukazRYCHLOST());
	printf("\n\tPohyblivost: %d",bandit.ukazPOHYBLIVOST());
		
	printf("\n\n\tVyber akce: ");
	cin >> akce;
		
	if(cin.fail() || (akce>3 && akce<1))
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
		
	while(counter<2 && counter2 < 4)
	{	
		switch(akce)
		{
			case 1:
				if(utok < bandit.ukazUTOK() && obrana < bandit.ukazOBRANA())
				{
					sance = numgen(100);
					if(sance < 20 || ((sance > 45 && sance <60) || sance > 75))	//ŠANCE NA ZÁSAH JE 60%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					if(utok < bandit.ukazUTOK() || obrana < bandit.ukazOBRANA())
					{
						sance = numgen(100);
						if(sance < 15 || ((sance > 50 && sance <60) || sance > 85))	// ŠANCE NA ZÁSAH JE 40%
						{
							counter++;
							hp = hp - 5;
							printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
						}
					}
					else
					{
						sance = numgen(100);
						if(sance < 10 || ((sance > 55 && sance <60) || sance > 95))	// ŠANCE NA ZÁSAH JE 20%
						{
							counter++;
							hp = hp - 5;
							printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
						}
					}
				}
				if(typ_hry == 1)
				{
					ct++;
				}
				break;
			
			case 2:
				if(rychlost > bandit.ukazRYCHLOST())
				{
					sance = numgen(100);
					if(sance < 10 || ((sance > 50 && sance <60) || sance > 90))	// ŠANCE NA ZÁSAH JE 35%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					sance = numgen(100);
					if(sance < 20 || ((sance > 40 && sance <60) || sance > 80))	// ŠANCE NA ZÁSAH JE 60%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				if(typ_hry == 1)
				{
					bt++;
				}
				break;
			
			case 3:
				if(charisma > bandit.ukazCHARISMA())
				{
					sance = numgen(100);
					if(sance < 17 || ((sance > 50 && sance <60) || sance > 93))	// ŠANCE NA ZÁSAH JE 33%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					sance = numgen(100);
					if(sance < 32 || ((sance > 43 && sance <60) || sance > 85))	// ŠANCE NA ZÁSAH JE 64%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				break;
		}
//		getch();
		counter2++;
	}
	if(ct>0)
	{
		zabiti++;
	}
	if(bt>0)
	{
		pocet_uprchu++;
	}
	battlelog(1,counter*5);
}

void player::lesnizver()
{
	int gcislo=0, ct=0, bt=0;
	enemy lesnizver;
	char radek[100];
	char *p;
	FILE *f;
	
	if(lvl==0)
	{
		gcislo = 1 + 3;
	}
	else
	{
		gcislo = lvl + 3;
	}
	
	chdir("enemies");
	
	f = fopen("lesnizver.txt","r");
	
	while(fgets(radek,100,f)!=NULL)
	{
		p = strtok(radek,"|");
		lesnizver.nastavUTOK(atoi(p));
		p = strtok(NULL,"|");
		lesnizver.nastavOBRANA(atoi(p));
		p = strtok(NULL,"|");
		lesnizver.nastavCHARISMA(atoi(p));
		p = strtok(NULL,"|");
		lesnizver.nastavRYCHLOST(atoi(p));
		p = strtok(NULL,"|");
		lesnizver.nastavPOHYBLIVOST(atoi(p));
	}
	
	fclose(f);
	chdir("..");
	
	lesnizver.nastavHP(100);
	lesnizver.nastavLEVEL(numgen(gcislo));
	
	switch(lesnizver.ukazLEVEL())
	{
		case 1:
		
		case 2:
			lesnizver.nastavUTOK(lesnizver.ukazUTOK()+1);
			lesnizver.nastavOBRANA(lesnizver.ukazOBRANA()+2);
			lesnizver.nastavRYCHLOST(lesnizver.ukazRYCHLOST()+3);
			break;
		
		case 3:
			lesnizver.nastavUTOK(lesnizver.ukazUTOK()+2);
			lesnizver.nastavPOHYBLIVOST(lesnizver.ukazPOHYBLIVOST()+4);
			lesnizver.nastavRYCHLOST(lesnizver.ukazRYCHLOST()+3);
			break;
		
		case 4:
			lesnizver.nastavOBRANA(lesnizver.ukazOBRANA()+4);
			lesnizver.nastavCHARISMA(lesnizver.ukazCHARISMA()+1);
			lesnizver.nastavRYCHLOST(lesnizver.ukazRYCHLOST()+3);
			lesnizver.nastavPOHYBLIVOST(lesnizver.ukazPOHYBLIVOST()+3);
			break;
		
		case 5:
			lesnizver.nastavUTOK(lesnizver.ukazUTOK()+3);
			lesnizver.nastavCHARISMA(lesnizver.ukazCHARISMA()+1);
			lesnizver.nastavPOHYBLIVOST(lesnizver.ukazPOHYBLIVOST()+4);
			lesnizver.nastavOBRANA(lesnizver.ukazOBRANA()+3);
			break;
	}
	
	int counter=0, vysledek=0, sance, akce, counter2 = 0;
	
	reset:
	system("cls");
	printf("\n\n\tByl(a) jsi prepadnut(a) lesni zveri!");
	printf("\n\tCo budes delat?");
	printf("\n\t1 - Bojovat");
	printf("\n\t2 - Pokusit se utect");
//	printf("\n\t3 - Pokusit se uplatit");
	printf("\n\t3 - Pokusit se domluvit");
		
	printf("\n\n\tTve attributy:");
	printf("\n\tUtok:        %d",utok);
	printf("\n\tObrana:      %d", obrana);
	printf("\n\tCharisma:    %d",charisma);
	printf("\n\tRychlost:    %d",rychlost);
	printf("\n\tPohyblivost: %d",pohyblivost);
		
	printf("\n\n\tAttributy soupere:");
	printf("\n\tUtok:        %d",lesnizver.ukazUTOK());
	printf("\n\tObrana:      %d",lesnizver.ukazOBRANA());
	printf("\n\tCharisma:    %d",lesnizver.ukazCHARISMA());
	printf("\n\tRychlost:    %d",lesnizver.ukazRYCHLOST());
	printf("\n\tPohyblivost: %d",lesnizver.ukazPOHYBLIVOST());
		
	printf("\n\n\tVyber akce: ");
	cin >> akce;
		
	if(cin.fail() || (akce>3 && akce<1))
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
		
	while(counter<2 && counter2 < 4)
	{	
		switch(akce)
		{
			case 1:
				if(utok < lesnizver.ukazUTOK() && obrana < lesnizver.ukazOBRANA())
				{
					sance = numgen(100);
					if(sance < 17 || ((sance > 50 && sance <60) || sance > 77))	//ŠANCE NA ZÁSAH JE 50%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					if(utok < lesnizver.ukazUTOK() || obrana < lesnizver.ukazOBRANA())
					{
						sance = numgen(100);
						if(sance < 15 || ((sance > 52 && sance <60) || sance > 90))	// ŠANCE NA ZÁSAH JE 33%
						{
							counter++;
							hp = hp - 5;
							printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
						}
					}
					else
					{
						sance = numgen(100);
						if(sance < 3 || ((sance > 58 && sance <60) || sance > 95))	// ŠANCE NA ZÁSAH JE 10%
						{
							counter++;
							hp = hp - 5;
							printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
						}
					}
				}
				if(typ_hry == 1)
				{
					ct++;
				}
				break;
			
			case 2:
				if(rychlost > lesnizver.ukazRYCHLOST())
				{
					sance = numgen(100);
					if(sance < 15 || ((sance > 50 && sance <60) || sance > 90))	// ŠANCE NA ZÁSAH JE 35%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					sance = numgen(100);
					if(sance < 10 || ((sance > 40 && sance <60) || sance > 80))	// ŠANCE NA ZÁSAH JE 70%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				if(typ_hry == 1)
				{
					bt++;
				}
				break;
			
			case 3:
				if(charisma > lesnizver.ukazCHARISMA())
				{
					sance = numgen(100);
					if(sance < 30 || ((sance > 40 && sance <60) || sance > 70))	// ŠANCE NA ZÁSAH JE 80%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					sance = numgen(100);
					if(sance < 35 || ((sance > 40 && sance <60) || sance > 68))	// ŠANCE NA ZÁSAH JE 87%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				break;
		}
	//	getch();
		counter2++;
	}
	if(ct>0)
	{
		zabiti++;
	}
	if(bt>0)
	{
		pocet_uprchu++;
	}
	battlelog(2,counter*5);
}

void player::straz()
{
	int gcislo=0;
	int ct=0, bt=0;
	enemy straz;
	char radek[100];
	char *p;
	FILE *f;
	
	if(lvl==0)
	{
		gcislo = 1 + 3;
	}
	else
	{
		gcislo = lvl + 3;
	}
	
	chdir("enemies");
	
	f = fopen("straz.txt","r");
	
	while(fgets(radek,100,f)!=NULL)
	{
		p = strtok(radek,"|");
		straz.nastavUTOK(atoi(p));
		p = strtok(NULL,"|");
		straz.nastavOBRANA(atoi(p));
		p = strtok(NULL,"|");
		straz.nastavCHARISMA(atoi(p));
		p = strtok(NULL,"|");
		straz.nastavRYCHLOST(atoi(p));
		p = strtok(NULL,"|");
		straz.nastavPOHYBLIVOST(atoi(p));
	}
	
	fclose(f);
	chdir("..");
	
	straz.nastavHP(100);
	straz.nastavLEVEL(numgen(gcislo));
	
	switch(straz.ukazLEVEL())
	{
		case 1:
		
		case 2:
			straz.nastavUTOK(straz.ukazUTOK()+5);
			straz.nastavOBRANA(straz.ukazOBRANA()+3);
			straz.nastavRYCHLOST(straz.ukazRYCHLOST()+1);
			break;
		
		case 3:
			straz.nastavUTOK(straz.ukazUTOK()+3);
			straz.nastavPOHYBLIVOST(straz.ukazPOHYBLIVOST()+3);
			straz.nastavRYCHLOST(straz.ukazRYCHLOST()+2);
			break;
		
		case 4:
			straz.nastavOBRANA(straz.ukazOBRANA()+2);
			straz.nastavCHARISMA(straz.ukazCHARISMA()+3);
			straz.nastavRYCHLOST(straz.ukazRYCHLOST()+2);
			straz.nastavPOHYBLIVOST(straz.ukazPOHYBLIVOST()+3);
			break;
		
		case 5:
			straz.nastavUTOK(straz.ukazUTOK()+5);
			straz.nastavCHARISMA(straz.ukazCHARISMA()+3);
			straz.nastavPOHYBLIVOST(straz.ukazPOHYBLIVOST()+1);
			straz.nastavOBRANA(straz.ukazOBRANA()+2);
			break;
	}
	
	int counter=0, vysledek=0, sance, akce, counter2 = 0;
	
	reset:
	system("cls");
	printf("\n\n\tByl(a) jsi prepadnut(a) strazcem!");
	printf("\n\tCo budes delat?");
	printf("\n\t1 - Bojovat");
	printf("\n\t2 - Pokusit se utect");
//	printf("\n\t3 - Pokusit se uplatit");
	printf("\n\t3 - Pokusit se domluvit");
		
	printf("\n\n\tTve attributy:");
	printf("\n\tUtok:        %d",utok);
	printf("\n\tObrana:      %d", obrana);
	printf("\n\tCharisma:    %d",charisma);
	printf("\n\tRychlost:    %d",rychlost);
	printf("\n\tPohyblivost: %d",pohyblivost);
		
	printf("\n\n\tAttributy soupere:");
	printf("\n\tUtok:        %d",straz.ukazUTOK());
	printf("\n\tObrana:      %d",straz.ukazOBRANA());
	printf("\n\tCharisma:    %d",straz.ukazCHARISMA());
	printf("\n\tRychlost:    %d",straz.ukazRYCHLOST());
	printf("\n\tPohyblivost: %d",straz.ukazPOHYBLIVOST());
		
	printf("\n\n\tVyber akce: ");
	cin >> akce;
		
	if(cin.fail() || (akce>3 && akce<1))
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
		
	while(counter<2 && counter2 < 4)
	{	
		switch(akce)
		{
			case 1:
				if(utok < straz.ukazUTOK() && obrana < straz.ukazOBRANA())
				{
					sance = numgen(100);
					if(sance < 30 || ((sance > 45 && sance <60) || sance > 70))	//ŠANCE NA ZÁSAH JE 75%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					if(utok < straz.ukazUTOK() || obrana < straz.ukazOBRANA())
					{
						sance = numgen(100);
						if(sance < 20 || ((sance > 50 && sance <60) || sance > 80))	// ŠANCE NA ZÁSAH JE 50%
						{
							counter++;
							hp = hp - 5;
							printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
						}
					}
					else
					{
						sance = numgen(100);
						if(sance < 10 || ((sance > 55 && sance <60) || sance > 95))	// ŠANCE NA ZÁSAH JE 20%
						{
							counter++;
							hp = hp - 5;
							printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
						}
					}
				}
				if(typ_hry == 1)
				{
					ct++;
				}
				break;
			
			case 2:
				if(rychlost > straz.ukazRYCHLOST())
				{
					sance = numgen(100);
					if(sance < 10 || ((sance > 50 && sance <60) || sance > 90))	// ŠANCE NA ZÁSAH JE 30%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					sance = numgen(100);
					if(sance < 20 || ((sance > 40 && sance <60) || sance > 80))	// ŠANCE NA ZÁSAH JE 60%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				if(typ_hry == 1)
				{
					bt++;
				}
				break;
			
			case 3:
				if(charisma > straz.ukazCHARISMA())
				{
					sance = numgen(100);
					if(sance < 25 || ((sance > 50 && sance <60) || sance > 85))	// ŠANCE NA ZÁSAH JE 50%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				else
				{
					sance = numgen(100);
					if(sance < 25 || ((sance > 40 && sance <60) || sance > 75))	// ŠANCE NA ZÁSAH JE 70%
					{
						counter++;
						hp = hp - 5;
						printf("\n\n\tByl(a) jsi zasahnut(a)! Bojuj dal!");
					}
				}
				break;
		}
//		getch();
		counter2++;
	}
	if(ct>0)
	{
		zabiti++;
	}
	if(bt>0)
	{
		pocet_uprchu++;
	}
	battlelog(3,counter*5);
}
