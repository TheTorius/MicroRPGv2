#include "knih.h"

void player::ini()
{
	char *p, radek[200],n[200];
	int kontrola=0;
	FILE *f;
	
	f = fopen("default.txt","r");
	while(fgets(radek,20,f)!=NULL)
	{
		p = strtok(radek,"|");
		strcpy(n,p);
		obraz = n[0];
		p = strtok(NULL,"|");
		strcpy(n,p);
		text = n[0];
	}
	fclose(f);
	
	string retezec = "color ";
	retezec = retezec + obraz + text;
	
	system(retezec.c_str());
	
	f = fopen("music.txt","r");
	
	if(f==NULL)
	{
		hudba = 0;
		fclose(f);
		f = fopen("music.txt","w");
		fprintf(f,"0|");
		fclose(f);
	}
	else
	{
		while(fgets(radek,20,f)!=NULL)
		{
			p = strtok(radek,"|");
			hudba = atoi(p);
		}
	}
	fclose(f);
	
	f = fopen("README.txt","w");
	fprintf(f,"Pro spusteni vlastni hudby vlozte do slozky s hrou hudbu s priponou .mp3\na hudbu pojmenujte jako 'custom'. Vysledkem tedy bude soubor\npojmenovany jako 'custom.mp3'");
	fprintf(f,"\nPokud se hudba nespusti, prekonvertujte hudbu do mp3 formatu pres\nprogram Audacity. Po konverzi by melo audio fungovat.");
	fclose(f);
	
	f = fopen("loading.txt","r");
	
	while(fgets(radek,20,f)!=NULL)
	{
		p = strtok(radek,"|");
		load = atoi(p);
	}
	
	fclose(f);
	
	system("mkdir saveslots");
	chdir("saveslots");
	f = fopen("saveslot1.txt","a"); fclose(f);
	f = fopen("saveslot2.txt","a"); fclose(f);
	f = fopen("saveslot3.txt","a"); fclose(f);
	f = fopen("autosave.txt","a"); fclose(f);
	system("mkdir saveslots1");
	system("mkdir saveslots2");
	system("mkdir saveslots3");
	chdir("saveslots1");
	f = fopen("slot1.txt","a"); fclose(f);
	f = fopen("slot2.txt","a"); fclose(f);
	f = fopen("slot3.txt","a"); fclose(f);
	f = fopen("slot4.txt","a"); fclose(f);
	f = fopen("slot5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots2");
	f = fopen("slot1.txt","a"); fclose(f);
	f = fopen("slot2.txt","a"); fclose(f);
	f = fopen("slot3.txt","a"); fclose(f);
	f = fopen("slot4.txt","a"); fclose(f);
	f = fopen("slot5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots3");
	f = fopen("slot1.txt","a"); fclose(f);
	f = fopen("slot2.txt","a"); fclose(f);
	f = fopen("slot3.txt","a"); fclose(f);
	f = fopen("slot4.txt","a"); fclose(f);
	f = fopen("slot5.txt","a"); fclose(f);
	chdir("..");
	chdir("..");
	
	system("mkdir inventory");
	chdir("inventory");
	f = fopen("inv1.txt","a"); fclose(f);
	f = fopen("inv2.txt","a"); fclose(f);
	f = fopen("inv3.txt","a"); fclose(f);
	f = fopen("autosave.txt","a"); fclose(f);
	system("mkdir saveslots1");
	system("mkdir saveslots2");
	system("mkdir saveslots3");
	chdir("saveslots1");
	f = fopen("slotinv1.txt","a"); fclose(f);
	f = fopen("slotinv2.txt","a"); fclose(f);
	f = fopen("slotinv3.txt","a"); fclose(f);
	f = fopen("slotinv4.txt","a"); fclose(f);
	f = fopen("slotinv5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots2");
	f = fopen("slotinv1.txt","a"); fclose(f);
	f = fopen("slotinv2.txt","a"); fclose(f);
	f = fopen("slotinv3.txt","a"); fclose(f);
	f = fopen("slotinv4.txt","a"); fclose(f);
	f = fopen("slotinv5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots3");
	f = fopen("slotinv1.txt","a"); fclose(f);
	f = fopen("slotinv2.txt","a"); fclose(f);
	f = fopen("slotinv3.txt","a"); fclose(f);
	f = fopen("slotinv4.txt","a"); fclose(f);
	f = fopen("slotinv5.txt","a"); fclose(f);
	
	chdir("..");
	chdir("..");
	
	system("mkdir achievementy");
	chdir("achievementy");
	f = fopen("achiev1.txt","a"); fclose(f);
	f = fopen("achiev2.txt","a"); fclose(f);
	f = fopen("achiev3.txt","a"); fclose(f);
	f = fopen("achievauto.txt","a"); fclose(f);
	system("mkdir saveslots1");
	system("mkdir saveslots2");
	system("mkdir saveslots3");
	chdir("saveslots1");
	f = fopen("slotachiev1.txt","a"); fclose(f);
	f = fopen("slotachiev2.txt","a"); fclose(f);
	f = fopen("slotachiev3.txt","a"); fclose(f);
	f = fopen("slotachiev4.txt","a"); fclose(f);
	f = fopen("slotachiev5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots2");
	f = fopen("slotachiev1.txt","a"); fclose(f);
	f = fopen("slotachiev2.txt","a"); fclose(f);
	f = fopen("slotachiev3.txt","a"); fclose(f);
	f = fopen("slotachiev4.txt","a"); fclose(f);
	f = fopen("slotachiev5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots3");
	f = fopen("slotachiev1.txt","a"); fclose(f);
	f = fopen("slotachiev2.txt","a"); fclose(f);
	f = fopen("slotachiev3.txt","a"); fclose(f);
	f = fopen("slotachiev4.txt","a"); fclose(f);
	f = fopen("slotachiev5.txt","a"); fclose(f);
	chdir("..");
	chdir("..");
	
	if(chdir("enemies"))
	{
		system("mkdir enemies");
		chdir("enemies");
		
		f = fopen("bandita.txt","w"); fprintf(f,"4|3|1|1|1|"); fclose(f);
		f = fopen("lesnizver.txt","w"); fprintf(f,"2|2|0|5|5|"); fclose(f);
		f = fopen("straz.txt","w"); fprintf(f,"5|4|1|2|1|"); fclose(f);
		
		system("copy bandita.txt bandita.BAK");
		system("copy lesnizver.txt lesnizver.BAK");
		system("copy straz.txt straz.BAK");
		
		kontrola = 1;
		
		chdir("..");
	}
	
	if(kontrola == 0)
	{
		chdir("..");
	}
	
	system("mkdir metadata");
	chdir("metadata");
	f = fopen("logfile.txt","a"); fclose(f);
	chdir("..");
	
	system("mkdir vysledky");
	chdir("vysledky");
	f = fopen("vysledky.txt","a"); fclose(f);
	chdir("..");
	
	system("mkdir harvest");
	chdir("harvest");
	f = fopen("harvest1.txt","a"); fclose(f);
	f = fopen("harvest2.txt","a"); fclose(f);
	f = fopen("harvest3.txt","a"); fclose(f);
	f = fopen("harvestautosave.txt","a"); fclose(f);
	system("mkdir saveslots1");
	system("mkdir saveslots2");
	system("mkdir saveslots3");
	chdir("saveslots1");
	f = fopen("harvest1.txt","a"); fclose(f);
	f = fopen("harvest2.txt","a"); fclose(f);
	f = fopen("harvest3.txt","a"); fclose(f);
	f = fopen("harvest4.txt","a"); fclose(f);
	f = fopen("harvest5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots2");
	f = fopen("harvest1.txt","a"); fclose(f);
	f = fopen("harvest2.txt","a"); fclose(f);
	f = fopen("harvest3.txt","a"); fclose(f);
	f = fopen("harvest4.txt","a"); fclose(f);
	f = fopen("harvest5.txt","a"); fclose(f);
	chdir("..");
	chdir("saveslots3");
	f = fopen("harvest1.txt","a"); fclose(f);
	f = fopen("harvest2.txt","a"); fclose(f);
	f = fopen("harvest3.txt","a"); fclose(f);
	f = fopen("harvest4.txt","a"); fclose(f);
	f = fopen("harvest5.txt","a"); fclose(f);
	chdir("..");
	chdir("..");
	chdir("harvest");
	system("del temporary.txt");
	chdir("..");
}
