#include "knih.h"

player::player()
{
	jmeno = "";
	xp = 0;
	lvl = 0;
	hp = 0;
	utok = 0;
	obrana = 0;
	charisma = 0;
	rychlost = 0;
	pohyblivost = 0;
	slot1 = 0x30;
	slot2 = 0x30;
	trida = 1;
	typ_hry = 0;
	poz_x = 0;
	poz_y = 0;
	smer = 1;
	tah = 0;
	podtah = 0;
	seno = 0;
	mince = 0;
	jidlo = 0;
	kroky = 0;
	zabiti = 0;
	pocet_sklizni = 0;
	doplnene_zivoty = 0;
	pocet_uprchu = 0;
	obraz = '0';
	text = 'F';
	load = 0;
}

player::player(string ijmeno, int ilvl, int ixp, int ihp, int iutok, int iobrana, int icharisma, int irychlost, int ipohyblivost, int islot1, int islot2, int itrida, int ityp_hry, int ipoz_x, int ipoz_y, int ismer, int itah, int ipodtah, int iseno, int imince, int ijidlo,  int ikroky, int izabiti, int ipocet_sklizni, int idoplnene_zivoty, int ipocet_uprchu, char iobraz, char itext, int iload)
{
	jmeno = ijmeno;
	xp = ixp;
	lvl = ilvl;
	hp = ihp;
	utok = iutok;
	obrana = iobrana;
	charisma = icharisma;
	rychlost = irychlost;
	pohyblivost = ipohyblivost;
	slot1 = islot1;
	slot2 = islot2;
	trida = itrida;
	typ_hry = ityp_hry;
	poz_x = ipoz_x;
	poz_y = ipoz_y;
	smer = ismer;
	tah = itah;
	podtah = ipodtah;
	seno = iseno;
	mince = imince;
	jidlo = ijidlo;
	zabiti = izabiti;
	pocet_sklizni = ipocet_sklizni;
	doplnene_zivoty = idoplnene_zivoty;
	pocet_uprchu = ipocet_uprchu;
	obraz = iobraz;
	text = itext;
	load = iload;
}

enemy::enemy()
{
	elvl = 0;
	ehp = 0;
	eutok = 0;
	eobrana = 0;
	echarisma = 0;
	erychlost = 0;
	epohyblivost = 0;
}

enemy::enemy(int ilvl, int ihp, int iutok, int iobrana, int icharisma, int irychlost, int ipohyblivost)
{
	elvl = ilvl;
	ehp = ihp;
	eutok = iutok;
	eobrana = iobrana;
	echarisma = icharisma;
	erychlost = irychlost;
	epohyblivost = ipohyblivost;
}
