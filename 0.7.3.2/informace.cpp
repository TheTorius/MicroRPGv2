#include "knih.h"

void player::informace()
{
	system("cls");
	printf("\n\n");
	system("echo	    V�t�m t�.");
	system("echo	    Tohle je hra naz�van� m�m stvo�itelem jako MicroRPG nebo tak� MicroGame");
	system("echo	    z�le�� jen na tob� jak m� bude� cht�t pojmenov�vat. Jsem hra, sna��c o");
	system("echo	    textov� proveden� RPG a nebo Rogue-like hry. Co ze m� bude je zat�m pouze");
	system("echo	    ve hv�zd�ch. Aktu�ln� nab�z�m to co nab�z�m a m��e� si m� zkusit v pln� par�d�");
	printf("\n");
	system("echo	    Aktu�ln� se jedn� o Rogue-like hru, kdy si zalo�� postavu a nejde ti o nic jin�ho");
	system("echo	    ne� se pokou�et ve h�e pokro�it co nejd�l, p�i�em� se t� hra bude sna�it co");
	system("echo	    mo�n� nejrychleji zne�kodnit. Hru si m��e� tak� ukl�dat pro p��pad, �e bys");
	system("echo	    pot�eboval/a nutn� odej�t. Av�ak ukl�d�n� ber v�n�. Nem��e� se jen tak vr�tit");
	system("echo	    a pokud naraz� na n�hodnou ud�lost tak nen� cesty zp�t. Boji se nevyhne� a");
	system("echo	    p��padn� smrti taky ne. Jakmile um�e� ztrat� t�m tak� i svou ulo�enou pozici.");
	system("echo	    Ve h�e takt� m��e� narazit na takov� ud�losti, kter� ti mohou pomoci.");
	system("echo	    M��e se v�ak st�t, �e t� n�kdo o�id� a nebo se t� pokus� zab�t. Va� tedy i sv�");
	system("echo	    p�erozd�l�v�n� bod� ve strom� dovednost�, a� se nestane� ob�t� p��li� brzy.");
	system("echo	    P�eji ti mnoho zdaru p�i tv� dobrodru�n� cest�.");
	printf("\n\n");
	system("echo	    Stiskni cokoliv pro n�vrat do hlavn�ho meny...");
	printf("\t");
	getch();
}

void player::titulky()
{
	system("cls");
	printf("\n\n\n\n");
	system("echo				Program vytvo�en: Luk� Hor�k");
	system("echo				Start projektu: 19.5.2022 v ~14:00");
	system("echo				Ukon�en� projektu: 1.7.2022 v 10:39");
	system("echo				Aktualizace projektu: 29.8.2022 v 12:44");
	system("echo                         Aktu�ln� build: 0.7.3.2");
	system("echo					      lukas.c�");
	printf("\n\n");
	printf("                        ");
	system("pause");
	system("cls");
}

void player::endtitle()
{
	int vyber;
	time_t t;
	
	string trida_postavy;
	
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
	
	system("cls");
	system("echo Tv� cesta ji� skon�ila mist�e/mistryn�.");
	system("echo Vydr�el/a jsi tak jak jsi jen mohl/a a to se cen�, av�ak tohle je konec.");
	system("echo D�ky, �e sis hru zahr�l/a a douf�m, �e se l�bila.");
	printf("\n\n\t");
	printf("Statistiky");
	printf("\n\tNazev hrdiny/nky: %s",jmeno.c_str());
	printf("\n\tTrida postavy: %s",trida_postavy.c_str());
	printf("\n\tDosazena uroven: %d",lvl);
	printf("\n\tPocet XP: %d",xp);
	printf("\n\n\n\tPocet odehranych tahu: %d",tah);
	printf("\n\tKonecna pozice: %d|%d",poz_x-10000,poz_y-10000);
	printf("\n\n\n\tUtok: %d\n\tObrana: %d\n\tCharisma: %d\n\tPohyblivost: %d\n\tRychlost: %d\n\t",utok,obrana,charisma,pohyblivost,rychlost);
	printf("\n\n\n\tPrejes si statistiky ulozit do souboru? (1-ANO/2-Ne)");
	printf("\n\tVyber: ");
	scanf("%d",&vyber);
	while(vyber<1||vyber>2)
	{
		printf("\n\n\tOpakuj vyber!");
		printf("\n\tVyber: ");
		scanf("%d",&vyber);
	}
	if(vyber==1)
	{
		FILE *f;
		f=fopen("./vysledky/vysledky.txt","a");
		fprintf(f,"-----------------------------------\n");
		fprintf(f,"\n\tStatistiky");
		fprintf(f,"\n\tNazev hrdiny/nky: %s",jmeno.c_str());
		fprintf(f,"\n\tTrida postavy: %s",trida_postavy.c_str());
		fprintf(f,"\n\tDosazena uroven: %d",lvl);
		fprintf(f,"\n\tPocet XP: %d",xp);
		fprintf(f,"\n\n\tPocet odehranych tahu: %d",tah);
		fprintf(f,"\n\tKonecna pozice: %d|%d",poz_x-10000,poz_y-10000);
		fprintf(f,"\n\n\tUtok: %d\n\tObrana: %d\n\tCharisma: %d\n\tPohyblivost: %d\n\tRychlost: %d\n\n",utok,obrana,charisma,pohyblivost,rychlost);
		time_t currentime = time(0);
		struct tm tm = *localtime(&currentime);
		fprintf(f,"\t%d/%d/%d %d:%d:%d\n\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
		fclose(f);
	}
	
	printf("\n\n\tStiskni cokoliv pro navrat do hlavniho menu...");
	getch();
	longjmp(jumpBuf4,1);
}

void player::vysvetleni()
{
	system("cls");
	
	printf("\n");
	system("echo Zdrav�m cizin�e, zde ti vysv�tl�m z�klad. (Pro verzi 0.6.1)");
	system("echo XP system:");
	system("echo XP system je nastaven� v tuto danou verzi na n�kolik z�kladn�ch akc�.");
	system("echo Zku�enostn� body dost�v� za sklize� ze sv� farmy, za zabit�, p�emluven�,");
	system("echo �t�k od protivn�ka a tak� za ka�d� p�e�it� tah. Mo�nosti se pozd�ji roz����.");
	printf("\n");
	system("echo Syst�m souboje:");
	system("echo Soubojov� syst�m je prost�. M� na v�b�r ze 3 mo�nost�, jak se v boji");
	system("echo zachovat. Nejd�le�it�j�� je, aby jste si vybral dle sv�ho nejlep��ho uv�en�");
	system("echo a v neposledn� �ad� tak� sv�ch schopnost�. Na ka�d�ho soupe�e se hod� trochu");
	system("echo jin� taktika a proto vhodn� uva� sv� rozhodnut�.");
	printf("\n");
	system("echo Farma�en�:");
	system("echo Farma�en� funguje na b�zi zasazen� a n�sledn�ho vy�k�n� po ur�itou dobu kol,");
	system("echo ne� sem�nka spr�vn� vyrostou. Z ka�d� sklizn� m� tak� ur�it� procento, �e");
	system("echo ti vypadne sem�nko zp�tky. Z ka�d� sklizn� dostane� 3 sena a ur�en� po�et XP.");
	printf("\n");
	system("echo Pohyb ve h�e:");
	system("echo Ve h�e samotn� se postava h�be dle Va�� volby. Je mo�n� oto�it se do 4");
	system("echo sv�tov�ch stran ozna�en�ch jako S, J, V, Z a n�sledn�ho postupu. Pokud budete");
	system("echo postupovat kup�edu danou sv�tovou stranou, budete se tak� h�bat na hern�m poli");
	system("echo o X a Y sou�adnic�ch. Mapa m� v aktu�ln� verzi nekone�n� hern� pole.");
	printf("\n");
	system("echo Iron Man m�d:");
	system("echo M�d na re�im Iron Man znamen�, �e hr�� nem� mo�nost si hru ukl�dat. Hra se");
	system("echo toti� napevno ukl�d� s ka�d�m rozhodnut�m, co ud�l�te. Zde nen� prostor na");
	system("echo chyby a je to m�d jen pro ty, co si troufaj� na v�zvu bez chyb.");
	printf("\n");
	system("echo Normal m�d:");
	system("echo Hra na re�im Normal umo��uje plnohodnotn� z�itek se v�emi vlastnostmi, co hra");
	system("echo dok�e nab�dnout. M� nekone�n� mo�nosti ukl�d�n�, ale d� se vybrat jen ur�it�");
	system("echo postava s ji� p�edem dan�mi attributy neboli vlastnostmi.");
	printf("\n");
	system("echo Custom m�d:");
	system("echo Custom m�d je to sam�, co Normal s t�m rozd�lem, �e zde m� mo�nost hr�� si");
	system("echo p�erozd�lit body dle sv�ch preferenc�. Nev�hodou tohoto re�imu je zamezen�");
	system("echo dost�vat achievementy, jeliko� by si n�sledn� mohl hr�� dle trofej� uzp�sobit.");
	printf("\n");
	system("echo Syst�m n�hodil�ch ud�ost�:");
	system("echo Nahodil� ud�losti se odehr�vaj� na konci tahu. Nen� na n�j v�ak 100% �ance");
	system("echo a proto ne v�dy se tato ud�lost stane. To, co se m��e p�ihodit z�stane zahaleno.");
	printf("\n");
	system("echo Benchmark:");
	system("echo Oproti jin�m hr�m, zde slou�� benchmark pro tv�rce, ale i pro hr��e, kter� si");
	system("echo chce ov��it sv� �t�st� v r�mci losov�n� ��sel. P�i zapnut� tohoto re�imu se do");
	system("echo souboru pojmenovan�m jako STATISTIKA.txt ukl�daj� ��sla do interval� po 5 ��slech.");
	system("echo (0-5 | 6-10 | 11- 15....), pokud hr���v PC vygeneruje ��slo v r�mci dan�ho");
	system("echo intervalu, ulo�� se do soubor� v tom dan�m intervalu. Hr�� by m�l m�t p�ibli�n�");
	system("echo rovnom�rn� pokryt� v�ech interval�. Pro lep�� statistiku se doporu�uje nechat");
	system("echo benchmark b�et v r�mci 5 minut. D�le ho pak ukon�it k��kem nebo zkratkou CTRL+C.");
	printf("\n");
	system("echo Obt�nost hry:");
	system("echo Hra m� st�le stejnou obt�nost. Je mo�no, �e v r�mci nov�ch build� se pozm�n�");
	system("echo procentu�ln� �ance na ur�it� ud�losti. Pokud se hr��i v ur�it� �as neda��, jedn�");
	system("echo se o �patn� RNG (Random number generator) neboli jednodu�e �e�eno. �patn� �ance");
	system("echo na dobr� ��sla vygenerovan� po��ta�em.");
	printf("\n");
	system("echo LogFile:");
	system("echo Ve slo�ce metadata se nach�z� soubor LogFile obsahuj�c� podrobn� informace o tom,");
	system("echo jak si hr�� zrovna vede v r�mci sv� kampan�. Je ve snaze zaznamenat opravdu v�e.");
	printf("\n");
	system("echo V�sledky kampan�:");
	system("echo Jako ka�d� jin� hr�� m�te pr�vo vid�t, jak se V�m v kampani da�ilo po jeho ukon�en�");
	system("echo ve slo�ce 'vysledky'. Pokud si chcete v�sledky ulo�it, je nutn�, abyste na konci sv�");
	system("echo cesty potvrdily z�pis do tohoto souboru.");
	printf("\n");
	system("echo Slo�ky vytvo�en� hrou:");
	system("echo D�razn� ��d�m, aby se nemazali ��dn� slo�ky ani soubory, kter� program vytvo�il.");
	system("echo V�echny soubory jsou pro spr�vn� chod hry d�le�it� a jejich smaz�n�m, by mohlo");
	system("echo doj�t k nep�edv�dateln�mu chov�n� programu. Pokud n�jak� soubor odstran�te, tak");
	system("echo sma�te v�echny soubory a� na samotnou hru a hru znovu spus�te. Hra si obnov�");
	system("echo sv� d�le�it� soubory. Pop��pad� si d�lejte z�lohy sv�ch her (slo�ka saveslots,");
	system("echo harvest, inventory a achievementy).");
	printf("\n");
	system("echo Enemies backup:");
	system("echo V p��pad�, �e nast�v� nep�edv�dateln� chov�n� v r�mci souboj�, doporu�uji");
	system("echo soubory s nep��teli (ve slo�ce 'enemies' a soubory s p��ponou .txt) smazat a ");
	system("echo p�epsat n�hradn� soubory, kter� se ve slo�ce nach�zej� (soubory s p��ponou .BAK) na");
	system("echo soubory s p��ponou .txt. Pop��pad� celou slo�ku 'enemies' odstra�te a restartujte hru.");
	printf("\n");
	system("echo default.txt:");
	system("echo Tento soubor stejn� tak jako 'STATISTIKA.txt' p�i prvn�m spu�t�n� neuvid�te, av�ak");
	system("echo vytvo�� se v p��pad� ud�l�n� ur�it�ch krok�. V r�mci default.txt se nastavuj� barvy");
	system("echo p�i spu�t�n� hry, kter� si u�ivatel nastavil v nastaven� barev. V p��pad�, �e je nutn�,");
	system("echo abyste barvy odstranili, je nutn� bu� soubor 'default.txt' smazat, nebo p�epsat jeho");
	system("echo data na:        0|F|");
	printf("\n");
	system("echo loading.txt:");
	system("echo Tento soubor slou�� pro v�choz� nastaven� rychlosti na��t�n� hry. Pro jeho restartov�n�");
	system("echo sta�� soubor smazat, nebo p�epsat jeho obsah na:           0|");
	
	printf("\n\n\t");
	system("echo Scrollujte nebo posu�te se v r�mci �ipek na prav� stran� obrazovky pro pohyb mezi v�emi"); 
	printf("\t");
	system("echo vysv�tlivkami.");
	getch();
}
