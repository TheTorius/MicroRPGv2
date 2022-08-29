#include "knih.h"

void player::ulozit_hru()
{
	FILE *f;
	char radek[500];
	
	string nazev = "saveslot";
	string inven = "inv";
	string trofej= "achiev";
	string harves= "harvest";
	nazev = nazev + (char) (slot1+0x30) + ".txt";
	inven = inven + (char) (slot1+0x30) + ".txt";
	trofej= trofej+ (char) (slot1+0x30) + ".txt";
	harves= harves+ (char) (slot1+0x30) + ".txt";
	
	chdir("saveslots");
	
	int n = nazev.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, nazev.c_str());
	printf("\n\t%d          %s                 ",slot1,char_array);
	if(slot1 > 0 && slot1 < 4)
	{
		f = fopen(char_array,"w");
		
		fprintf(f,"%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|",jmeno.c_str(),lvl,xp,hp,utok,obrana,charisma,rychlost,pohyblivost,slot1,slot2,trida,typ_hry, poz_x, poz_y, smer, tah, podtah);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("inventory");
	
	n = inven.length();
	char char_array2[n + 1];
	strcpy(char_array2,inven.c_str());
	
	if(slot1 > 0 && slot1 < 4)
	{
		f = fopen(char_array2,"w");
		
		fprintf(f,"%d|%d|%d|%d|",mince, jidlo, seno, seminka);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("achievementy");
	
	n = trofej.length();
	char char_array3[n + 1];
	strcpy(char_array3,trofej.c_str());
	
	if(slot1 > 0 && slot1 < 4)
	{
		f = fopen(char_array3,"w");
		
		fprintf(f,"%d|%d|%d|%d|%d|",kroky,zabiti,pocet_sklizni,doplnene_zivoty,pocet_uprchu);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("harvest");
	
	string nazevi = "harvest";
	nazevi = nazevi + (char) (slot1+0x30) + ".txt";
	string prikaz = "copy temporary.txt ";
	prikaz = prikaz + nazevi;
	
	system(prikaz.c_str());
	
	chdir("..");
	
	system("cls");
}

void player::nacist_hru()
{
	reset:
	system("cls");
	
	int vyb;
	
	char radek[500];
	char *p;
	char n1[50], n2[50], n3[50], n4[50];
	int t1,t2,t3,t4;
	char vyber[2];
	
	char naz1[50] = "Saveslot: ";
	char naz2[50] = "Saveslot: ";
	char naz3[50] = "Saveslot: ";
	char naz4[50] = "Autosaveslot: ";
	
	FILE *f;
	
	chdir("saveslots");
	
	f = fopen("saveslot1.txt","r");
	
	if(fgets(radek,500,f)==NULL) strcpy(n1,"EMPTY");
	rewind(f);
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		strcpy(n1,p);
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		t1 = atoi(p);
		
	}
	
	fclose(f);
	
	f = fopen("saveslot2.txt","r");
	
	if(fgets(radek,500,f)==NULL) strcpy(n2,"EMPTY");
	rewind(f);
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		strcpy(n2,p);
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		t2 = atoi(p);
	}
	
	fclose(f);
	
	f = fopen("saveslot3.txt","r");
	
	if(fgets(radek,500,f)==NULL) strcpy(n3,"EMPTY");
	rewind(f);
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		strcpy(n3,p);
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		t3 = atoi(p);
	}
	
	fclose(f);
	
	f = fopen("autosave.txt","r");
	
	if(fgets(radek,500,f)==NULL) strcpy(n4,"EMPTY");
	rewind(f);
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		strcpy(n4,p);
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		p = strtok(NULL,"|"); 
		t4 = atoi(p);
	}
	
	fclose(f);
	
	printf("\n\t1 - %s",strcat(naz1,n1)); if(t1 == 3) printf(" (IRON MAN)");
	printf("\n\t2 - %s",strcat(naz2,n2)); if(t2 == 3) printf(" (IRON MAN)");
	printf("\n\t3 - %s",strcat(naz3,n3)); if(t3 == 3) printf(" (IRON MAN)");
	printf("\n\t4 - %s",strcat(naz4,n4)); if(t4 == 3) printf(" (IRON MAN)");
	printf("\n\n\t5 - Smazat pozici");
	printf("\n\t6 - Zpet");
	vyber[0] = getch();
	
	vyb = atoi(vyber);
	
	switch(vyb)
	{
		case 1:
			if(strcmp(n1,"EMPTY")==0) goto reset;
			nacti1();
			break;
			
		case 2:
			if(strcmp(n2,"EMPTY")==0) goto reset;
			nacti2();
			break;
			
		case 3:
			if(strcmp(n3,"EMPTY")==0) goto reset;
			nacti3();
			break;
			
		case 4:
			if(strcmp(n4,"EMPTY")==0) goto reset;
			autoreload();
			break;
		
		case 5:
			smazat_pozici();
			goto reset;
			break;
		
		case 6:
			break;
	}
}

void player::smazat_pozici()
{
	char vyber[10];
	int vyb;
	
	system("cls");
	printf("\n\t1 - Smazat pozici 1");
	printf("\n\t2 - Smazat pozici 2");
	printf("\n\t3 - Smazat pozici 3");
	printf("\n\n\t4 - Zpet");
	vyber[0] = getch();
	
	vyb = atoi(vyber);
	
	switch(vyb)
	{
		case 1:
			system("del saveslot1.txt");
			system("cd saveslots1");
			system("del slot1.txt");
			system("del slot2.txt");
			system("del slot3.txt");
			system("del slot4.txt");
			system("del slot5.txt");
			chdir("..");
			break;
			
		case 2:
			system("del saveslot2.txt");
			system("cd saveslots1");
			system("del slot1.txt");
			system("del slot2.txt");
			system("del slot3.txt");
			system("del slot4.txt");
			system("del slot5.txt");
			chdir("..");
			break;
			
		case 3:
			system("del saveslot3.txt");
			system("cd saveslots1");
			system("del slot1.txt");
			system("del slot2.txt");
			system("del slot3.txt");
			system("del slot4.txt");
			system("del slot5.txt");
			chdir("..");
			break;
		
		case 4:
			break;
			
	}
}

void player::nacti1()
{
	char radek[500];
	char *p;
	FILE *f;
	
	f = fopen("saveslot1.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		jmeno = p;
		p = strtok(NULL,"|");
		lvl = atoi(p);
		p = strtok(NULL,"|");
		xp = atoi(p);
		p = strtok(NULL,"|");
		hp = atoi(p);
		p = strtok(NULL,"|");
		utok = atoi(p);
		p = strtok(NULL,"|");
		obrana = atoi(p);
		p = strtok(NULL,"|");
		charisma = atoi(p);
		p = strtok(NULL,"|");
		rychlost = atoi(p);
		p = strtok(NULL,"|");
		pohyblivost = atoi(p);
		p = strtok(NULL,"|");
		slot1 = atoi(p);
		p = strtok(NULL,"|");
		slot2 = atoi(p);
		p = strtok(NULL,"|");
		trida = atoi(p);
		p = strtok(NULL,"|");
		typ_hry = atoi(p);
		p = strtok(NULL,"|");
		poz_x = atoi(p);
		p = strtok(NULL,"|");
		poz_y = atoi(p);
		p = strtok(NULL,"|");
		smer = atoi(p);
		p = strtok(NULL,"|");
		tah = atoi(p);
		p = strtok(NULL,"|");
		podtah = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("achievementy");
	
	f = fopen("achiev1.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		kroky = atoi(p);
		p = strtok(NULL,"|");
		zabiti = atoi(p);
		p = strtok(NULL,"|");
		pocet_sklizni = atoi(p);
		p = strtok(NULL,"|");
		doplnene_zivoty = atoi(p);
		p = strtok(NULL,"|");
		pocet_uprchu = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("inventory");
	
	f = fopen("inv1.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		mince = atoi(p);
		p = strtok(NULL,"|");
		jidlo = atoi(p);
		p = strtok(NULL,"|");
		seno = atoi(p);
		p = strtok(NULL,"|");
		seminka = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("harvest");
	
	system("copy harvest1.txt temporary.txt");
	
	chdir("..");
	
	login();
	
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

void player::nacti2()
{
	char radek[500];
	char *p;
	FILE *f;
	
	f = fopen("saveslot2.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		jmeno = p;
		p = strtok(NULL,"|");
		lvl = atoi(p);
		p = strtok(NULL,"|");
		xp = atoi(p);
		p = strtok(NULL,"|");
		hp = atoi(p);
		p = strtok(NULL,"|");
		utok = atoi(p);
		p = strtok(NULL,"|");
		obrana = atoi(p);
		p = strtok(NULL,"|");
		charisma = atoi(p);
		p = strtok(NULL,"|");
		rychlost = atoi(p);
		p = strtok(NULL,"|");
		pohyblivost = atoi(p);
		p = strtok(NULL,"|");
		slot1 = atoi(p);
		p = strtok(NULL,"|");
		slot2 = atoi(p);
		p = strtok(NULL,"|");
		trida = atoi(p);
		p = strtok(NULL,"|");
		typ_hry = atoi(p);
		p = strtok(NULL,"|");
		poz_x = atoi(p);
		p = strtok(NULL,"|");
		poz_y = atoi(p);
		p = strtok(NULL,"|");
		smer = atoi(p);
		p = strtok(NULL,"|");
		tah = atoi(p);
		p = strtok(NULL,"|");
		podtah = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("achievementy");
	
	f = fopen("achiev2.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		kroky = atoi(p);
		p = strtok(NULL,"|");
		zabiti = atoi(p);
		p = strtok(NULL,"|");
		pocet_sklizni = atoi(p);
		p = strtok(NULL,"|");
		doplnene_zivoty = atoi(p);
		p = strtok(NULL,"|");
		pocet_uprchu = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("inventory");
	
	f = fopen("inv2.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		mince = atoi(p);
		p = strtok(NULL,"|");
		jidlo = atoi(p);
		p = strtok(NULL,"|");
		seno = atoi(p);
		p = strtok(NULL,"|");
		seminka = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("harvest");
	
	system("copy harvest2.txt temporary.txt");
	
	chdir("..");
	
	login();
	
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

void player::nacti3()
{
	char radek[500];
	char *p;
	FILE *f;
	
	f = fopen("saveslot3.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		jmeno = p;
		p = strtok(NULL,"|");
		lvl = atoi(p);
		p = strtok(NULL,"|");
		xp = atoi(p);
		p = strtok(NULL,"|");
		hp = atoi(p);
		p = strtok(NULL,"|");
		utok = atoi(p);
		p = strtok(NULL,"|");
		obrana = atoi(p);
		p = strtok(NULL,"|");
		charisma = atoi(p);
		p = strtok(NULL,"|");
		rychlost = atoi(p);
		p = strtok(NULL,"|");
		pohyblivost = atoi(p);
		p = strtok(NULL,"|");
		slot1 = atoi(p);
		p = strtok(NULL,"|");
		slot2 = atoi(p);
		p = strtok(NULL,"|");
		trida = atoi(p);
		p = strtok(NULL,"|");
		typ_hry = atoi(p);
		p = strtok(NULL,"|");
		poz_x = atoi(p);
		p = strtok(NULL,"|");
		poz_y = atoi(p);
		p = strtok(NULL,"|");
		smer = atoi(p);
		p = strtok(NULL,"|");
		tah = atoi(p);
		p = strtok(NULL,"|");
		podtah = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("achievementy");
	
	f = fopen("achiev3.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		kroky = atoi(p);
		p = strtok(NULL,"|");
		zabiti = atoi(p);
		p = strtok(NULL,"|");
		pocet_sklizni = atoi(p);
		p = strtok(NULL,"|");
		doplnene_zivoty = atoi(p);
		p = strtok(NULL,"|");
		pocet_uprchu = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("inventory");
	
	f = fopen("inv3.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		mince = atoi(p);
		p = strtok(NULL,"|");
		jidlo = atoi(p);
		p = strtok(NULL,"|");
		seno = atoi(p);
		p = strtok(NULL,"|");
		seminka = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("harvest");
	
	system("copy harvest3.txt temporary.txt");
	
	chdir("..");
	
	login();
	
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

void player::autosave()
{
	FILE *f;
	
	chdir("saveslots");
	
	f = fopen("autosave.txt","w");
	
	fprintf(f,"%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|",jmeno.c_str(),lvl,xp,hp,utok,obrana,charisma,rychlost,pohyblivost,slot1,slot2,trida,typ_hry, poz_x, poz_y, smer, tah, podtah);
	
	fclose(f);
	
	chdir("..");
	chdir("achievementy");
	
	f = fopen("achievauto.txt","w");
	
	fprintf(f,"%d|%d|%d|%d|%d|",kroky,zabiti,pocet_sklizni,doplnene_zivoty,pocet_uprchu);
	
	fclose(f);
	
	chdir("..");
	chdir("inventory");
	
	f = fopen("autosave.txt","w");
	
	fprintf(f,"%d|%d|%d|%d|",mince, jidlo, seno, seminka);
	
	fclose(f);
	
	chdir("..");
}

void player::autoreload()
{
	char radek[500];
	char *p;
	FILE *f;
	
	chdir("saveslots");
	
	f = fopen("autosave.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		jmeno = p;
		p = strtok(NULL,"|");
		lvl = atoi(p);
		p = strtok(NULL,"|");
		xp = atoi(p);
		p = strtok(NULL,"|");
		hp = atoi(p);
		p = strtok(NULL,"|");
		utok = atoi(p);
		p = strtok(NULL,"|");
		obrana = atoi(p);
		p = strtok(NULL,"|");
		charisma = atoi(p);
		p = strtok(NULL,"|");
		rychlost = atoi(p);
		p = strtok(NULL,"|");
		pohyblivost = atoi(p);
		p = strtok(NULL,"|");
		slot1 = atoi(p);
		p = strtok(NULL,"|");
		slot2 = atoi(p);
		p = strtok(NULL,"|");
		trida = atoi(p);
		p = strtok(NULL,"|");
		typ_hry = atoi(p);
		p = strtok(NULL,"|");
		poz_x = atoi(p);
		p = strtok(NULL,"|");
		poz_y = atoi(p);
		p = strtok(NULL,"|");
		smer = atoi(p);
		p = strtok(NULL,"|");
		tah = atoi(p);
		p = strtok(NULL,"|");
		podtah = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("achievementy");
	
	f = fopen("achievauto.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		kroky = atoi(p);
		p = strtok(NULL,"|");
		zabiti = atoi(p);
		p = strtok(NULL,"|");
		pocet_sklizni = atoi(p);
		p = strtok(NULL,"|");
		doplnene_zivoty = atoi(p);
		p = strtok(NULL,"|");
		pocet_uprchu = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("inventory");
	
	f = fopen("autosave.txt","r");
	
	while(fgets(radek,500,f)!=NULL)
	{
		p = strtok(radek,"|");
		mince = atoi(p);
		p = strtok(NULL,"|");
		jidlo = atoi(p);
		p = strtok(NULL,"|");
		seno = atoi(p);
		p = strtok(NULL,"|");
		seminka = atoi(p);
	}
	
	fclose(f);
	
	chdir("..");
	
	chdir("harvest");
	
	system("copy harvestautosave.txt temporary.txt");
	
	chdir("..");
	
	login();
	
	usleep(100);
	
	hra_standard();
}

void player::slots_save()
{	
	FILE *f;
	char radek[500], *p, n1[50];
	int ihp, ixp, ilvl, k;
	int i = 0, vyb;
	string naz = "saveslots";
	res:
		
	system("cls");
	printf("\n\tUlozene pozice pro hrace: %s\n",jmeno.c_str());
	
	chdir("saveslots");
	naz = naz + (char) (slot1+0x30);
	chdir(naz.c_str());
	
	for(i=1;i<6;i++)
	{
		k = 0;
		naz = "slot";
		naz = naz + (char) (i+0x30) + ".txt";
		f=fopen(naz.c_str(),"r");
		
		if(fgets(radek,200,f)==NULL)
		{
			strcpy(n1,"EMPTY");
			k++;
		} 
		rewind(f);
		
		while(fgets(radek,200,f)!=NULL)
		{
			p = strtok(radek,"|");
			p = strtok(NULL,"|");
			ilvl = atoi(p);
			p = strtok(NULL,"|");
			ixp = atoi(p);
			p = strtok(NULL,"|");
			ihp = atoi(p);
		}
		
		if(k==1)
		{
			printf("\n\tSlot%d: %s",i,n1);
		}
		else
		{
			printf("\n\tSlot%d: Lvl(%d)  XP(%d)  HP(%d)",i,ilvl,ixp,ihp);
		}
	}
	printf("\n\t6 - Zpet");
	printf("\n\n\tVyber slot nebo prikaz: ");
	cin >> vyb;
	
	if(cin.fail() || (vyb < 1 || vyb > 6))
	{
		cin.clear();
		cin.ignore();
		goto res;
	}
	
	if(vyb!=6)
	{
		slot2 = vyb;
	
		chdir("..");
		chdir("..");
	
		string nazev = "slot";
		string inven = "slotinv";
		string trofej= "slotachiev";
		string sl = "saveslots";
		nazev = nazev + (char) (slot2+0x30) + ".txt";
		inven = inven + (char) (slot2+0x30) + ".txt";
		trofej= trofej+ (char) (slot2+0x30) + ".txt";
		sl = sl + (char) (slot1+0x30);
	
		chdir("saveslots");
		chdir(sl.c_str());
	
		int n = nazev.length();
 
    	// declaring character array
    	char char_array[n + 1];
 
	    // copying the contents of the
    	// string to char array
    	strcpy(char_array, nazev.c_str());
		printf("\n\t%d          %s                 ",slot2,char_array);
		if(slot2 > 0 && slot2 < 6)
		{
			f = fopen(char_array,"w");
		
			fprintf(f,"%s|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|",jmeno.c_str(),lvl,xp,hp,utok,obrana,charisma,rychlost,pohyblivost,slot1,slot2,trida,typ_hry, poz_x, poz_y, smer, tah, podtah);
		}
	
		fclose(f);
		chdir("..");
		chdir("..");
	
		chdir("inventory");
		chdir(sl.c_str());
	
		n = inven.length();
		char char_array2[n + 1];
		strcpy(char_array2,inven.c_str());
	
		if(slot2 > 0 && slot2 < 4)
		{
			f = fopen(char_array2,"w");
		
			fprintf(f,"%d|%d|%d|%d|",mince, jidlo, seno, seminka);
		}
	
		fclose(f);
	
		chdir("..");
		chdir("..");
	
		chdir("achievementy");
		chdir(sl.c_str());
	
		n = trofej.length();
		char char_array3[n + 1];
		strcpy(char_array3,trofej.c_str());
	
		if(slot2 > 0 && slot2 < 4)
		{
			f = fopen(char_array3,"w");
		
			fprintf(f,"%d|%d|%d|%d|%d|",kroky,zabiti,pocet_sklizni,doplnene_zivoty,pocet_uprchu);
		}
	
		fclose(f);
	
		chdir("..");
		chdir("..");
	
		chdir("harvest");
	
		string nazevi = " ", nazvy;
		nazvy =  "saveslots";
		nazvy = nazvy + (char) (slot1+0x30);
		printf("\n\n\t%s\n\n\t",nazvy.c_str());
		nazevi = nazvy + "\\" + "harvest" + (char) (slot2+0x30) + ".txt";
		string prikaz = "copy temporary.txt ";
		prikaz = prikaz + nazevi;
	
		system(prikaz.c_str());
		chdir("..");
	}
	
}

void player::slots_load()
{
	FILE *f;
	char radek[500], *p, n1[50], n2[50], n3[50], n4[50], n5[50], n6[50];
	int ihp, ixp, ilvl, k;
	int i = 0, vyb;
	string naz = "saveslots", nazv;
	res:
	system("cls");
	printf("\n\tNacteni pozice pro hrace: %s\n",jmeno.c_str());
	
	chdir("saveslots");
	naz = naz + (char) (slot1+0x30);
	chdir(naz.c_str());
	
	for(i=1;i<6;i++)
	{
		k = 0;
		nazv = "slot";
		nazv = nazv + (char) (i+0x30) + ".txt";
		f=fopen(nazv.c_str(),"r");
		
		if(fgets(radek,200,f)==NULL)
		{
			strcpy(n1,"EMPTY");
			switch(i)
			{
				case 1:
					strcpy(n2,"EMPTY");
					break;
				
				case 2:
					strcpy(n3,"EMPTY");
					break;
				
				case 3:
					strcpy(n4,"EMPTY");
					break;
				
				case 4:
					strcpy(n5,"EMPTY");
					break;
				
				case 5:
					strcpy(n6,"EMPTY");
					break;
			}
			k++;
		} 
		rewind(f);
		
		while(fgets(radek,200,f)!=NULL)
		{
			p = strtok(radek,"|");
			p = strtok(NULL,"|");
			ilvl = atoi(p);
			p = strtok(NULL,"|");
			ixp = atoi(p);
			p = strtok(NULL,"|");
			ihp = atoi(p);
		}
		
		if(k==1)
		{
			printf("\n\tSlot%d: %s",i,n1);
		}
		else
		{
			printf("\n\tSlot%d: Lvl(%d)  XP(%d)  HP(%d)",i,ilvl,ixp,ihp);
		}
	}
	printf("\n\t6 - Zpet");
	printf("\n\n\tVyber slot nebo prikaz: ");
	cin >> vyb;
	
	if(cin.fail() || (vyb < 1 || vyb > 6))
	{
		cin.clear();
		cin.ignore();
		goto res;
	}
	
	switch(vyb)
	{
		case 1:
			if(strcmp(n2,"EMPTY")==0) goto res;
			f = fopen("slot1.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				jmeno = p;
				p = strtok(NULL,"|");
				lvl = atoi(p);
				p = strtok(NULL,"|");
				xp = atoi(p);
				p = strtok(NULL,"|");
				hp = atoi(p);
				p = strtok(NULL,"|");
				utok = atoi(p);
				p = strtok(NULL,"|");
				obrana = atoi(p);
				p = strtok(NULL,"|");
				charisma = atoi(p);
				p = strtok(NULL,"|");
				rychlost = atoi(p);
				p = strtok(NULL,"|");
				pohyblivost = atoi(p);
				p = strtok(NULL,"|");
				slot1 = atoi(p);
				p = strtok(NULL,"|");
				slot2 = atoi(p);
				p = strtok(NULL,"|");
				trida = atoi(p);
				p = strtok(NULL,"|");
				typ_hry = atoi(p);
				p = strtok(NULL,"|");
				poz_x = atoi(p);
				p = strtok(NULL,"|");
				poz_y = atoi(p);
				p = strtok(NULL,"|");
				smer = atoi(p);
				p = strtok(NULL,"|");
				tah = atoi(p);
				p = strtok(NULL,"|");
				podtah = atoi(p);
			}
	
			fclose(f);
			chdir("..");
			chdir("..");
			
			chdir("achievementy");
			chdir(naz.c_str());
			
			f = fopen("slotachiev1.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				kroky = atoi(p);
				p = strtok(NULL,"|");
				zabiti = atoi(p);
				p = strtok(NULL,"|");
				pocet_sklizni = atoi(p);
				p = strtok(NULL,"|");
				doplnene_zivoty = atoi(p);
				p = strtok(NULL,"|");
				pocet_uprchu = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("inventory");
			chdir(naz.c_str());
			f = fopen("slotinv1.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				mince = atoi(p);
				p = strtok(NULL,"|");
				jidlo = atoi(p);
				p = strtok(NULL,"|");
				seno = atoi(p);
				p = strtok(NULL,"|");
				seminka = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");	
			
			chdir("harvest");
			chdir(naz.c_str());
			
			system("copy harvest1.txt ..\\temporary.txt");
	
			chdir("..");
			chdir("..");
			
			break;
			
		case 2:
			if(strcmp(n3,"EMPTY")==0) goto res;
			f = fopen("slot2.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				jmeno = p;
				p = strtok(NULL,"|");
				lvl = atoi(p);
				p = strtok(NULL,"|");
				xp = atoi(p);
				p = strtok(NULL,"|");
				hp = atoi(p);
				p = strtok(NULL,"|");
				utok = atoi(p);
				p = strtok(NULL,"|");
				obrana = atoi(p);
				p = strtok(NULL,"|");
				charisma = atoi(p);
				p = strtok(NULL,"|");
				rychlost = atoi(p);
				p = strtok(NULL,"|");
				pohyblivost = atoi(p);
				p = strtok(NULL,"|");
				slot1 = atoi(p);
				p = strtok(NULL,"|");
				slot2 = atoi(p);
				p = strtok(NULL,"|");
				trida = atoi(p);
				p = strtok(NULL,"|");
				typ_hry = atoi(p);
				p = strtok(NULL,"|");
				poz_x = atoi(p);
				p = strtok(NULL,"|");
				poz_y = atoi(p);
				p = strtok(NULL,"|");
				smer = atoi(p);
				p = strtok(NULL,"|");
				tah = atoi(p);
				p = strtok(NULL,"|");
				podtah = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("achievementy");
			chdir(naz.c_str());
	
			f = fopen("slotachiev2.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				kroky = atoi(p);
				p = strtok(NULL,"|");
				zabiti = atoi(p);
				p = strtok(NULL,"|");
				pocet_sklizni = atoi(p);
				p = strtok(NULL,"|");
				doplnene_zivoty = atoi(p);
				p = strtok(NULL,"|");
				pocet_uprchu = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("inventory");
			chdir(naz.c_str());
	
			f = fopen("slotinv2.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				mince = atoi(p);
				p = strtok(NULL,"|");
				jidlo = atoi(p);
				p = strtok(NULL,"|");
				seno = atoi(p);
				p = strtok(NULL,"|");
				seminka = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("harvest");
			chdir(naz.c_str());
	
			system("copy harvest2.txt ..\\temporary.txt");
	
			chdir("..");
			chdir("..");
			break;
			
		case 3:
			if(strcmp(n4,"EMPTY")==0) goto res;
			f = fopen("slot3.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				jmeno = p;
				p = strtok(NULL,"|");
				lvl = atoi(p);
				p = strtok(NULL,"|");
				xp = atoi(p);
				p = strtok(NULL,"|");
				hp = atoi(p);
				p = strtok(NULL,"|");
				utok = atoi(p);
				p = strtok(NULL,"|");
				obrana = atoi(p);
				p = strtok(NULL,"|");
				charisma = atoi(p);
				p = strtok(NULL,"|");
				rychlost = atoi(p);
				p = strtok(NULL,"|");
				pohyblivost = atoi(p);
				p = strtok(NULL,"|");
				slot1 = atoi(p);
				p = strtok(NULL,"|");
				slot2 = atoi(p);
				p = strtok(NULL,"|");
				trida = atoi(p);
				p = strtok(NULL,"|");
				typ_hry = atoi(p);
				p = strtok(NULL,"|");
				poz_x = atoi(p);
				p = strtok(NULL,"|");
				poz_y = atoi(p);
				p = strtok(NULL,"|");
				smer = atoi(p);
				p = strtok(NULL,"|");
				tah = atoi(p);
				p = strtok(NULL,"|");
				podtah = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("achievementy");
			chdir(naz.c_str());
	
			f = fopen("slotachiev3.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				kroky = atoi(p);
				p = strtok(NULL,"|");
				zabiti = atoi(p);
				p = strtok(NULL,"|");
				pocet_sklizni = atoi(p);
				p = strtok(NULL,"|");
				doplnene_zivoty = atoi(p);
				p = strtok(NULL,"|");
				pocet_uprchu = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("inventory");
			chdir(naz.c_str());
	
			f = fopen("slotinv3.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				mince = atoi(p);
				p = strtok(NULL,"|");
				jidlo = atoi(p);
				p = strtok(NULL,"|");
				seno = atoi(p);
				p = strtok(NULL,"|");
				seminka = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("harvest");
			chdir(naz.c_str());
	
			system("copy harvest3.txt ..\\temporary.txt");
	
			chdir("..");
			chdir("..");
			break;
			
		case 4:
			if(strcmp(n5,"EMPTY")==0) goto res;
			f = fopen("slot4.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				jmeno = p;
				p = strtok(NULL,"|");
				lvl = atoi(p);
				p = strtok(NULL,"|");
				xp = atoi(p);
				p = strtok(NULL,"|");
				hp = atoi(p);
				p = strtok(NULL,"|");
				utok = atoi(p);
				p = strtok(NULL,"|");
				obrana = atoi(p);
				p = strtok(NULL,"|");
				charisma = atoi(p);
				p = strtok(NULL,"|");
				rychlost = atoi(p);
				p = strtok(NULL,"|");
				pohyblivost = atoi(p);
				p = strtok(NULL,"|");
				slot1 = atoi(p);
				p = strtok(NULL,"|");
				slot2 = atoi(p);
				p = strtok(NULL,"|");
				trida = atoi(p);
				p = strtok(NULL,"|");
				typ_hry = atoi(p);
				p = strtok(NULL,"|");
				poz_x = atoi(p);
				p = strtok(NULL,"|");
				poz_y = atoi(p);
				p = strtok(NULL,"|");
				smer = atoi(p);
				p = strtok(NULL,"|");
				tah = atoi(p);
				p = strtok(NULL,"|");
				podtah = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("achievementy");
			chdir(naz.c_str());
	
			f = fopen("slotachiev4.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				kroky = atoi(p);
				p = strtok(NULL,"|");
				zabiti = atoi(p);
				p = strtok(NULL,"|");
				pocet_sklizni = atoi(p);
				p = strtok(NULL,"|");
				doplnene_zivoty = atoi(p);
				p = strtok(NULL,"|");
				pocet_uprchu = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("inventory");
			chdir(naz.c_str());
	
			f = fopen("slotinv4.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				mince = atoi(p);
				p = strtok(NULL,"|");
				jidlo = atoi(p);
				p = strtok(NULL,"|");
				seno = atoi(p);
				p = strtok(NULL,"|");
				seminka = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("harvest");
			chdir(naz.c_str());
	
			system("copy harvest4.txt ..\\temporary.txt");
	
			chdir("..");
			chdir("..");
			break;
		
		case 5:
			if(strcmp(n6,"EMPTY")==0) goto res;
			f = fopen("slot5.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				jmeno = p;
				p = strtok(NULL,"|");
				lvl = atoi(p);
				p = strtok(NULL,"|");
				xp = atoi(p);
				p = strtok(NULL,"|");
				hp = atoi(p);
				p = strtok(NULL,"|");
				utok = atoi(p);
				p = strtok(NULL,"|");
				obrana = atoi(p);
				p = strtok(NULL,"|");
				charisma = atoi(p);
				p = strtok(NULL,"|");
				rychlost = atoi(p);
				p = strtok(NULL,"|");
				pohyblivost = atoi(p);
				p = strtok(NULL,"|");
				slot1 = atoi(p);
				p = strtok(NULL,"|");
				slot2 = atoi(p);
				p = strtok(NULL,"|");
				trida = atoi(p);
				p = strtok(NULL,"|");
				typ_hry = atoi(p);
				p = strtok(NULL,"|");
				poz_x = atoi(p);
				p = strtok(NULL,"|");
				poz_y = atoi(p);
				p = strtok(NULL,"|");
				smer = atoi(p);
				p = strtok(NULL,"|");
				tah = atoi(p);
				p = strtok(NULL,"|");
				podtah = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("achievementy");
			chdir(naz.c_str());
	
			f = fopen("slotachiev5.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				kroky = atoi(p);
				p = strtok(NULL,"|");
				zabiti = atoi(p);
				p = strtok(NULL,"|");
				pocet_sklizni = atoi(p);
				p = strtok(NULL,"|");
				doplnene_zivoty = atoi(p);
				p = strtok(NULL,"|");
				pocet_uprchu = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("inventory");
			chdir(naz.c_str());
	
			f = fopen("slotinv5.txt","r");
	
			while(fgets(radek,500,f)!=NULL)
			{
				p = strtok(radek,"|");
				mince = atoi(p);
				p = strtok(NULL,"|");
				jidlo = atoi(p);
				p = strtok(NULL,"|");
				seno = atoi(p);
				p = strtok(NULL,"|");
				seminka = atoi(p);
			}
	
			fclose(f);
	
			chdir("..");
			chdir("..");
			
			chdir("harvest");
			chdir(naz.c_str());
	
			system("copy harvest5.txt ..\\temporary.txt");
	
			chdir("..");
			chdir("..");
			break;
		
		case 6:
			break;
	}
}
