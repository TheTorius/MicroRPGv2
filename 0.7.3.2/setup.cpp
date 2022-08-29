#include "knih.h"

void player::setup()
{
	int end = 1, vyber;
	system("cls");
	
	while(end)
	{
		reset:
		system("cls");
		printf("\n\t\tNastaveni:");
		printf("\n\t1 - Nastaveni barev");
		printf("\n\t2 - Nastaveni nacitani");
		printf("\n\t3 - Nastaveni hudby");
		printf("\n\t5 - Zpet");
		printf("\n\n\tVyber: ");
		cin >> vyber;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			goto reset;
		}
		
		switch(vyber)
		{
			case 1:
				system("cls");
				setup_colors();
				break;
			
			case 2:
				system("cls");
				setup_loading();
				break;
			
			case 3:
				system("cls");
				setup_music_menu();
				break;
			
			case 5:
				end = 0;
		}
	}
}

void player::setup_colors()
{
	int end = 1, vyber;
	system("cls");
	
	while(end)
	{
		reset:
		system("cls");
		printf("\n\t\tNastaveni barev:");
		printf("\n\t1 - cerne pozadi | bily text");
		printf("\n\t2 - bile pozadi  | cerny text");
		printf("\n\t3 - cerve pozadi | bily text");
		printf("\n\t4 - modre pozadi | bily text");
		printf("\n\t5 - Vlastni");
		printf("\n\n\t6 - Ulozit nastaveni jako default");
		printf("\n\t7 - Zpet");
		printf("\n\n\tVyber: ");
		cin >> vyber;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			goto reset;
		}
		
		switch(vyber)
		{
			case 1:
				system("color 0F");
				obraz = '0';
				text = 'F';
				break;
				
			case 2:
				system("color F0");
				obraz = 'F';
				text = '0';
				break;
			
			case 3:
				system("color 4F");
				obraz = '4';
				text = 'F';
				break;
				
			case 4:
				system("color 1F");
				obraz = '1';
				text = 'F';
				break;
			
			case 5:
				setup_colors_custom();
				break;
				
			case 6:
				set_options();
				break;
				
			case 7:
				end = 0;
		}
	}
}

void player::setup_colors_custom()
{
//	string barva = "color ";
	char znak[5], barva2[10]= "color ", znaky[3], barva[10];
	COORD c;
	c.X = 30;
	c.Y = 1;
	
	system("cls");
	
	printf("\n\tZadejte si vlastni barvu: ")	;
	printf("\n\n\tVlastni barva se sklada ze dvou casti:");
	printf("\n\t\ta) barva pozadi");
	printf("\n\t\tb) barva textu");
	printf("\n\tHodnoty jsou v rozmezi hexadecimalni soustavy,");
	printf("\n\ttedy cisel 0-9 a pismen A-F reprezentujici 10-15.");
	printf("\n\tBarvu pozadi lze vzdy zmenit v hlavnim meny a");
	printf("\n\tpromita se i do samotne hry. Barvy vybirejte s");
	printf("\n\tohledem na to, ze s danyma barvama budete hrat!");
	printf("\n\n\tPriklad:");
	printf("\n\tF3");
	printf("\n\t05");
	printf("\n\n\tBarvy:");
	printf("\n\t0 = Black         1 = Blue	    2 = Green");
    printf("\n\t3 = Aqua	  4 = Red	    5 = Purple        ");
    printf("\n\t6 = Yellow	  7 = White         8 = Gray");
    printf("\n\t9 = Light Blue    A = Light Green   B = Light Aqua");
    printf("\n\tC = Light Red	  D = Light Purple  E = Light Yellow");
    printf("\n\t		  F = Bright White");
	printf("\n\tUpozorneni:");
	printf("\n\tHexadecimalni hodnoty vkladejte prosim s");
	printf("\n\tvelkymi pismeny. Jinak bude hodnota barvy neplatna.");
	printf("\n\n\tPotvrzuji barvu: _ (1-ANO/2-NE)");
	
	opak1:
	c.X = 34;
	c.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	printf("__");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	znak[0] = getch();
	printf("%c",znak[0]);
	
	if(znak[0] < 0x31 || (znak[0] > 0x39 && znak[0] < 0x41) || znak[0] > 0x46)
	{
		goto opak1;
	}
	
	opak2:
	c.X = 35;
	c.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	znak[1] = getch();
	printf("%c",znak[1]);
	
	if(znak[1] < 0x31 || (znak[1] > 0x39 && znak[1] < 0x41) || znak[1] > 0x46)
	{
		goto opak1;
	}
	
	znak[2] = ' ';
	strcpy(barva,barva2);
	strcat(barva,znak);
	
	system(barva);
	
	opak3:
	c.X = 25;
	c.Y = 27;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	znaky[0] = getch();
	printf("%c",znaky[0]);
	
	if(atoi(znaky)==2)
	{	
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
		printf("_");
		goto opak1;
		
	}
	
	else
	{
		if(atoi(znaky)==1);
		else
		{
			goto opak3;
		}
	}
	
	obraz = znak[0];
	text = znak[1];
}

void player::set_options()
{
	FILE *f;
	
	f = fopen("default.txt","w");
	
	fprintf(f,"%c|%c|",obraz,text);
	
	fclose(f);
}

void player::setup_loading()
{
	int vyber;
	system("cls");
	
	reset:
	system("cls");
	printf("\n\t\tNastaveni nacitani:");
	printf("\n\t1 - Defaultni nacitani");
	printf("\n\t2 - Urychlit nacitani");
	printf("\n\t3 - Zrusit nacitani");
	printf("\n\t4 - Zpet");
	printf("\n\n\tVyber: ");
	
	cin >> vyber;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
	}
	
	switch(vyber)
	{
		case 1:
			setup_loading_write(1);
			goto reset;
			break;
		
		case 2:
			setup_loading_write(2);
			goto reset;
			break;
		
		case 3:
			setup_loading_write(3);
			goto reset;
			break;
		
		case 4:
			break;
	}
}

void player::setup_loading_write(int cislo)
{
	FILE *f;
	
	f = fopen("loading.txt","w");
	
	if(cislo == 1) fprintf(f,"0|");
	if(cislo == 2) fprintf(f,"1|");
	if(cislo == 3) fprintf(f,"2|");
	
	fclose(f);
}

void player::setup_music_menu()
{
	int vyber;
	bool played;
	
	while(vyber!=9)
	{
		reset:
		system("cls");
	
		printf("\n\t\tMusic Menu:");
		printf("\n\t1 - Hrat 'Japan'");
		printf("\n\t2 - Hrat 'Nature'");
		printf("\n\t3 - Hrat 'Sci-fi'");
		printf("\n\t4 - Hrat vlastni hudbu [vice v README.txt]");
		printf("\n\t5 - Vypnout hudbu");
		printf("\n\t8 - Ulozit jako default");
		printf("\n\t9 - Zpet");
		printf("\n\n\tVyber: ");
	
		cin >> vyber;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			goto reset;
		}
		
		switch(vyber)
		{
			case 1:
				mciSendString("stop mp3", NULL, 0, NULL);
				mciSendString("close mp3", NULL, 0, NULL);
				mciSendString("open \"japan.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("play mp3 repeat", NULL, 0, NULL);
				hudba = 0;
				break;
			
			case 2:
				mciSendString("stop mp3", NULL, 0, NULL);
				mciSendString("close mp3", NULL, 0, NULL);
				mciSendString("open \"nature.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("play mp3 repeat", NULL, 0, NULL);
				hudba = 1;
				break;
			
			case 3:
				mciSendString("stop mp3", NULL, 0, NULL);
				mciSendString("close mp3", NULL, 0, NULL);
				mciSendString("open \"scifi.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("play mp3 repeat", NULL, 0, NULL);
				hudba = 2;
				break;
			
			case 4:
				mciSendString("stop mp3", NULL, 0, NULL);
				mciSendString("close mp3", NULL, 0, NULL);
				mciSendString("open \"custom.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
				mciSendString("play mp3 repeat", NULL, 0, NULL);
				hudba = 3;
				break;
			
			case 5:
				mciSendString("stop mp3", NULL, 0, NULL);
				mciSendString("close mp3", NULL, 0, NULL);
				hudba = 4;
				break;
				
			case 8:
				setup_music_set();
				break;
		}
	}
}

void player::setup_music_set()
{
	FILE *f;
	
	f = fopen("music.txt","w");
	
	if(hudba == 0) fprintf(f,"0|");
	if(hudba == 1) fprintf(f,"1|");
	if(hudba == 2) fprintf(f,"2|");
	
	fclose(f);
}
