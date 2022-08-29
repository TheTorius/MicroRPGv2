#include "knih.h"

void player::informace()
{
	system("cls");
	printf("\n\n");
	system("echo	    Vítám tì.");
	system("echo	    Tohle je hra nazıvaná mım stvoøitelem jako MicroRPG nebo také MicroGame");
	system("echo	    záleí jen na tobì jak mì budeš chtít pojmenovávat. Jsem hra, snaíc o");
	system("echo	    textové provedení RPG a nebo Rogue-like hry. Co ze mì bude je zatím pouze");
	system("echo	    ve hvìzdách. Aktuálnì nabízím to co nabízím a mùeš si mì zkusit v plné parádì");
	printf("\n");
	system("echo	    Aktuálnì se jedná o Rogue-like hru, kdy si zaloíš postavu a nejde ti o nic jiného");
	system("echo	    ne se pokoušet ve høe pokroèit co nejdál, pøièem se tì hra bude snait co");
	system("echo	    moná nejrychleji zneškodnit. Hru si mùeš také ukládat pro pøípad, e bys");
	system("echo	    potøeboval/a nutnì odejít. Avšak ukládání ber vánì. Nemùeš se jen tak vrátit");
	system("echo	    a pokud narazíš na náhodnou událost tak není cesty zpìt. Boji se nevyhneš a");
	system("echo	    pøípadné smrti taky ne. Jakmile umøeš ztratíš tím také i svou uloenou pozici.");
	system("echo	    Ve høe takté mùeš narazit na takové události, které ti mohou pomoci.");
	system("echo	    Mùe se však stát, e tì nìkdo ošidí a nebo se tì pokusí zabít. Va tedy i své");
	system("echo	    pøerozdìlávání bodù ve stromì dovedností, a se nestaneš obìtí pøíliš brzy.");
	system("echo	    Pøeji ti mnoho zdaru pøi tvé dobrodruné cestì.");
	printf("\n\n");
	system("echo	    Stiskni cokoliv pro návrat do hlavního meny...");
	printf("\t");
	getch();
}

void player::titulky()
{
	system("cls");
	printf("\n\n\n\n");
	system("echo				Program vytvoøen: Lukáš Horák");
	system("echo				Start projektu: 19.5.2022 v ~14:00");
	system("echo				Ukonèení projektu: 1.7.2022 v 10:39");
	system("echo				Aktualizace projektu: 29.8.2022 v 12:44");
	system("echo                         Aktuální build: 0.7.3.2");
	system("echo					      lukas.c®");
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
	system("echo Tvá cesta ji skonèila mistøe/mistrynì.");
	system("echo Vydrel/a jsi tak jak jsi jen mohl/a a to se cení, avšak tohle je konec.");
	system("echo Díky, e sis hru zahrál/a a doufám, e se líbila.");
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
	system("echo Zdravím cizinèe, zde ti vysvìtlím základ. (Pro verzi 0.6.1)");
	system("echo XP system:");
	system("echo XP system je nastavenı v tuto danou verzi na nìkolik základních akcí.");
	system("echo Zkušenostní body dostáváš za sklizeò ze své farmy, za zabití, pøemluvení,");
	system("echo útìk od protivníka a také za kadı pøeitı tah. Monosti se pozdìji rozšíøí.");
	printf("\n");
	system("echo Systém souboje:");
	system("echo Soubojovı systém je prostı. Máš na vıbìr ze 3 moností, jak se v boji");
	system("echo zachovat. Nejdùleitìjší je, aby jste si vybral dle svého nejlepšího uváení");
	system("echo a v neposlední øadì také svıch schopností. Na kadého soupeøe se hodí trochu");
	system("echo jiná taktika a proto vhodnì uva své rozhodnutí.");
	printf("\n");
	system("echo Farmaøení:");
	system("echo Farmaøení funguje na bázi zasazení a následného vyèkání po urèitou dobu kol,");
	system("echo ne semínka správnì vyrostou. Z kadé skliznì máš také urèité procento, e");
	system("echo ti vypadne semínko zpátky. Z kadé skliznì dostaneš 3 sena a urèenı poèet XP.");
	printf("\n");
	system("echo Pohyb ve høe:");
	system("echo Ve høe samotné se postava hıbe dle Vaší volby. Je moné otoèit se do 4");
	system("echo svìtovıch stran oznaèenıch jako S, J, V, Z a následného postupu. Pokud budete");
	system("echo postupovat kupøedu danou svìtovou stranou, budete se také hıbat na herním poli");
	system("echo o X a Y souøadnicích. Mapa má v aktuální verzi nekoneèné herní pole.");
	printf("\n");
	system("echo Iron Man mód:");
	system("echo Mód na reim Iron Man znamená, e hráè nemá monost si hru ukládat. Hra se");
	system("echo toti napevno ukládá s kadım rozhodnutím, co udìláte. Zde není prostor na");
	system("echo chyby a je to mód jen pro ty, co si troufají na vızvu bez chyb.");
	printf("\n");
	system("echo Normal mód:");
	system("echo Hra na reim Normal umoòuje plnohodnotnı záitek se všemi vlastnostmi, co hra");
	system("echo dokáe nabídnout. Má nekoneèné monosti ukládání, ale dá se vybrat jen urèitá");
	system("echo postava s ji pøedem danımi attributy neboli vlastnostmi.");
	printf("\n");
	system("echo Custom mód:");
	system("echo Custom mód je to samé, co Normal s tím rozdílem, e zde má monost hráè si");
	system("echo pøerozdìlit body dle svıch preferencí. Nevıhodou tohoto reimu je zamezení");
	system("echo dostávat achievementy, jeliko by si následnì mohl hráè dle trofejí uzpùsobit.");
	printf("\n");
	system("echo Systém náhodilıch udáostí:");
	system("echo Nahodilé události se odehrávají na konci tahu. Není na nìj však 100% šance");
	system("echo a proto ne vdy se tato událost stane. To, co se mùe pøihodit zùstane zahaleno.");
	printf("\n");
	system("echo Benchmark:");
	system("echo Oproti jinım hrám, zde slouí benchmark pro tvùrce, ale i pro hráèe, kterı si");
	system("echo chce ovìøit své štìstí v rámci losování èísel. Pøi zapnutí tohoto reimu se do");
	system("echo souboru pojmenovaném jako STATISTIKA.txt ukládají èísla do intervalù po 5 èíslech.");
	system("echo (0-5 | 6-10 | 11- 15....), pokud hráèùv PC vygeneruje èíslo v rámci daného");
	system("echo intervalu, uloí se do souborù v tom daném intervalu. Hráè by mìl mít pøiblinì");
	system("echo rovnomìrné pokrytí všech intervalù. Pro lepší statistiku se doporuèuje nechat");
	system("echo benchmark bìet v rámci 5 minut. Dále ho pak ukonèit køíkem nebo zkratkou CTRL+C.");
	printf("\n");
	system("echo Obtínost hry:");
	system("echo Hra má stále stejnou obtínost. Je mono, e v rámci novıch buildù se pozmìní");
	system("echo procentuální šance na urèité události. Pokud se hráèi v urèitı èas nedaøí, jedná");
	system("echo se o špatné RNG (Random number generator) neboli jednoduše øeèeno. Špatné šance");
	system("echo na dobrá èísla vygenerované poèítaèem.");
	printf("\n");
	system("echo LogFile:");
	system("echo Ve sloce metadata se nachází soubor LogFile obsahující podrobné informace o tom,");
	system("echo jak si hráè zrovna vede v rámci své kampanì. Je ve snaze zaznamenat opravdu vše.");
	printf("\n");
	system("echo Vısledky kampaní:");
	system("echo Jako kadı jinı hráè máte právo vidìt, jak se Vám v kampani daøilo po jeho ukonèení");
	system("echo ve sloce 'vysledky'. Pokud si chcete vısledky uloit, je nutné, abyste na konci své");
	system("echo cesty potvrdily zápis do tohoto souboru.");
	printf("\n");
	system("echo Sloky vytvoøené hrou:");
	system("echo Dùraznì ádám, aby se nemazali ádné sloky ani soubory, které program vytvoøil.");
	system("echo Všechny soubory jsou pro správnı chod hry dùleité a jejich smazáním, by mohlo");
	system("echo dojít k nepøedvídatelnému chování programu. Pokud nìjakı soubor odstraníte, tak");
	system("echo smate všechny soubory a na samotnou hru a hru znovu spuste. Hra si obnoví");
	system("echo své dùleité soubory. Popøípadì si dìlejte zálohy svıch her (sloka saveslots,");
	system("echo harvest, inventory a achievementy).");
	printf("\n");
	system("echo Enemies backup:");
	system("echo V pøípadì, e nastává nepøedvídatelné chování v rámci soubojù, doporuèuji");
	system("echo soubory s nepøáteli (ve sloce 'enemies' a soubory s pøíponou .txt) smazat a ");
	system("echo pøepsat náhradní soubory, které se ve sloce nacházejí (soubory s pøíponou .BAK) na");
	system("echo soubory s pøíponou .txt. Popøípadì celou sloku 'enemies' odstraòte a restartujte hru.");
	printf("\n");
	system("echo default.txt:");
	system("echo Tento soubor stejnì tak jako 'STATISTIKA.txt' pøi prvním spuštìní neuvidíte, avšak");
	system("echo vytvoøí se v pøípadì udìlání urèitıch krokù. V rámci default.txt se nastavují barvy");
	system("echo pøi spuštìní hry, které si uivatel nastavil v nastavení barev. V pøípadì, e je nutné,");
	system("echo abyste barvy odstranili, je nutné buï soubor 'default.txt' smazat, nebo pøepsat jeho");
	system("echo data na:        0|F|");
	printf("\n");
	system("echo loading.txt:");
	system("echo Tento soubor slouí pro vıchozí nastavení rychlosti naèítání hry. Pro jeho restartování");
	system("echo staèí soubor smazat, nebo pøepsat jeho obsah na:           0|");
	
	printf("\n\n\t");
	system("echo Scrollujte nebo posuòte se v rámci šipek na pravé stranì obrazovky pro pohyb mezi všemi"); 
	printf("\t");
	system("echo vysvìtlivkami.");
	getch();
}
