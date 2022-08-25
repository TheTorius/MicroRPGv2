#include "knih.h"

void player::konec_tahu()
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Hrac/ka '%s' prave ukoncila %d kolo.",jmeno.c_str(),tah);
	
	fclose(f);
	chdir("..");
}

void player::nova_postava()
{
	string trida_postavy;
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	switch(trida)
	{
		case 1:
			trida_postavy = "Warrior";
			break;
		
		case 2:
			trida_postavy = "Governor";
			break;
		
		case 3:
			trida_postavy = "Sprinter";
			break;
		
		case 4:
			trida_postavy = "Plebejec";
			break;
		
		case 5:
			trida_postavy = "Custom";
			break;
	}
	
	fprintf(f,"Byla zalozena nova postava tridy %s se jmenem '%s' ",trida_postavy.c_str(),jmeno.c_str());
	
	fclose(f);
	chdir("..");
}

void player::login()
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Hrac/ka '%s' se prave prihlasil(a) do hry.",jmeno.c_str());
	
	fclose(f);
	chdir("..");
}

void player::logout()
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Hrac/ka '%s' se prave odhlasil(a) ze hry.",jmeno.c_str());
	
	fclose(f);
	chdir("..");
}

void player::endgame()
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Postava '%s' ukoncila svou cestu.",jmeno.c_str());
	
	fclose(f);
	chdir("..");
}

void player::afterfight(string druh)
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Postava '%s' byla napadena. Zbylo ji: %d HP",jmeno.c_str(),hp);
	
	fclose(f);
	chdir("..");
}

void player::eatlog()
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Postava '%s' se obcerstvila pro zvyseni HP na %d%%",jmeno.c_str(),hp);
	
	fclose(f);
	chdir("..");
}

void player::battlelog(int typ, int ztrata)
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	switch(typ)
	{
		case 1:
			fprintf(f,"Postava '%s' se stretla s banditou a ztratila %d HP",jmeno.c_str(),ztrata);
			break;
		
		case 2:
			fprintf(f,"Postava '%s' se stretla s lesni zveri a ztratila %d HP",jmeno.c_str(),ztrata);
			break;
		
		case 3:
			fprintf(f,"Postava '%s' se stretla se strazi a ztratila %d HP",jmeno.c_str(),ztrata);
			break;
	}
	
	fclose(f);
	chdir("..");
}

void player::eventlog(int typ, int ztrata, int akce, int rozhodnuti)
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	switch(typ)
	{
		case 1:
			switch(rozhodnuti)
			{
				case 1:
					switch(akce)
					{
						case 1:
							fprintf(f,"Postava '%s' se stretla s babickou, ta mela nuz a postavu zranila za %d HP",jmeno.c_str(),ztrata);
							break;
						
						case 2:
							fprintf(f,"Postava '%s' se stretla s babickou, postava si nedala pozor a byla okradena o %d minci.",jmeno.c_str(),ztrata);
							break;
						
						case 3:
							fprintf(f,"Postava '%s' se stretla s babickou, byla to vsak past a postava musela bojovat.",jmeno.c_str());
							break;
							
						case 4:
							fprintf(f,"Postava '%s' se stretla s babickou, postava byla za ochotu odmenena %d mincemi.",jmeno.c_str(), ztrata);
							break;
						
						case 5:
							fprintf(f,"Postava '%s' se stretla s babickou, postava byla za ochotu odmenena %d ks jidla.",jmeno.c_str(), ztrata);
							break;
						
						case 6:
							fprintf(f,"Postava '%s' se stretla s babickou, ta podekovala a nasledne se rozesli.",jmeno.c_str());
							break;
					}
					break;
				
				case 2:
					fprintf(f,"Postava '%s' se stretla s babickou, avsak ji ignorovala a sla dal.",jmeno.c_str(),ztrata);
					
			}
			break;
		
/*		case 2:
			fprintf(f,"Postava '%s' se stretla s lesni zveri a ztratila %d HP",jmeno.c_str(),ztrata);
			break;
		
		case 3:
			fprintf(f,"Postava '%s' se stretla se strazi a ztratila %d HP",jmeno.c_str(),ztrata);
			break;*/
	}
	
	fclose(f);
	chdir("..");
}

void player::craftlog(int pocet)
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Postava '%s' si vycraftila %d jidla",jmeno.c_str(),pocet);
	
	fclose(f);
	chdir("..");
}

void player::lvlup_log()
{
	FILE *f;
	
	chdir("metadata");
	
	f = fopen("logfile.txt","a");
	
	time_t currentime = time(0);
	struct tm tm = *localtime(&currentime);
	fprintf(f,"\t\n%d/%d/%d %d:%d:%d     ", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	fprintf(f,"Postava '%s' povysila na uroven %d!",jmeno.c_str(),lvl);
	
	fclose(f);
	chdir("..");
}
