#ifndef KNIH
#define KNIH

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>
#include<unistd.h>
#include<conio.h>
#include<setjmp.h>
#include "MMSystem.h"

using namespace std;


class player{

	private:
		//Z�kladn� informace
		string jmeno;
		int lvl;
		int xp;
		int hp;
		
		//Attributy
		int utok;
		int obrana;
		int charisma;
		int rychlost;
		int pohyblivost;
		
		//Pozice hry
		int slot1;
		int slot2;
		int trida;
		int typ_hry;
		int poz_x;
		int poz_y;
		int smer;
		int tah;
		int podtah;
		
		//Invent��
		int seno;
		int jidlo;
		int mince;
		int seminka;
		
		//Trofeje
		int kroky;
		int zabiti;
		int pocet_sklizni;
		int doplnene_zivoty;
		int pocet_uprchu;
		
		//Nastaven�
		char obraz;
		char text;
		int load;
		int hudba;
	
	public:
		jmp_buf jumpBuf, jumpBuf2, jumpBuf3, jumpBuf4;
		player();
		player(string ijmeno, int ilvl, int ixp, int ihp, int iutok, int iobrana, int icharisma, int irychlost, int ipohyblivost, int islot1, int islot2, int itrida, int ityp_hry, int ipoz_x, int ipoz_y, int ismer, int itah, int ipodtah, int iseno, int imince, int ijidlo, int ikroky, int izabiti, int ipocet_sklizni, int idoplnene_zivoty, int ipocet_uprchu, char iobraz, char itext, int iload);
		
/*		string player_name() { return this->jmeno; };
		int player_lvl() { return this->lvl; };
		int player_xp() { return this->xp; };
		int player_utok() { return this->utok; };
		int player_obrana() { return this->obrana; };
		int player_charisma() { return this->charisma; };
		int player_rychlost() { return this->rychlost; };
		int player_pohyblivost() { return this->pohyblivost; };		*/
		int setup_load() { return this->load; };
		int setup_music_load() { return this->hudba; };
		
		//	Hlavn� menu
		void nova_hra();
		void custom_player();
		void hra_ironman();

		//	Hra samotn�
		void hra_standard();
		void hra_custom();
		void vlastnosti();
		void inventar();
		void craft_meal();
		void eat_meal();
		void farm_menu();
		void zobraz_farm();
		void sklid();
		void zasad();
		void achievement_menu();

		//	Ulo�en� hry
		void ulozit_hru();
		void nacist_hru();
		void nacti1();
		void nacti2();
		void nacti3();
		void slots_save();
		void slots_load();
		void autosave();
		void autoreload();
		void smazat_pozici();

		//	Pr�ce s metadatama
		void konec_tahu();
		void nova_postava();
		void login();
		void endgame();
		void logout();
		void afterfight(string druh);
		void craftlog(int pocet);
		void eatlog();
		void eventlog(int typ, int ztrata, int akce, int rozhodnuti);
		void battlelog(int typ, int ztrata);
		void lvlup_log();

		//	Pr�ce v souboj�ch
		void battle();
		int numgen(int cislo);
		void bandit();
		void lesnizver();
		void straz();

		//	Pr�ce v nahodil�mi ud�lostmi
		void stepevent();
		void turnevent();
		void endturnevent();
		void babicka();
		void scream();
		void obchodnik();
		void pocestny();
		void zoldak();

		//	Kontroln� funkce
		void kontrola_gen();
		void statistika_gen();
		void kontrola_klavesnice();
		void barvy();
		
		//	Inicializace
		void ini();
		
		//	Informace
		void informace();
		void endtitle();
		void titulky();
		void vysvetleni();
		
		//	Nastaven�
		void setup();
		void setup_colors();
		void setup_colors_custom();
		void set_options();
		void setup_loading();
		void setup_loading_write(int cislo);
		void setup_music_menu();
		void setup_music_set();
		
		//	Leveling
		void lvl_check();
		void lvlup();
		void lvl_zobraz();
};

class enemy{
	private:
		//	Z�kladn� informace
		int elvl;
		int ehp;
		
		//	Attributy
		int eutok;
		int eobrana;
		int echarisma;
		int erychlost;
		int epohyblivost;
	
	public:
		enemy();
		enemy(int ilvl, int ihp, int iutok, int iobrana, int icharisma, int irychlost, int ipohyblivost);	
		
		//	Nastavit z�kladn� informace
		void nastavLEVEL(int sila) { this->elvl = sila; };
		void nastavHP(int sila) { this->ehp = sila; };
		
		//	Nastavit Attributy
		void nastavUTOK(int sila) { this->eutok = sila; };
		void nastavOBRANA(int sila) { this->eobrana = sila; };
		void nastavCHARISMA(int sila) { this->echarisma = sila; };
		void nastavRYCHLOST(int sila) { this->erychlost = sila; };
		void nastavPOHYBLIVOST(int sila) { this->epohyblivost = sila; };
		
		//	Zobraz z�kladn� informace
		int ukazHP() { return this->ehp; };
		int ukazLEVEL() { return this->elvl; };
		
		//	Zobraz Attributy
		int ukazUTOK() { return this->eutok; };
		int ukazOBRANA() { return this->eobrana; };
		int ukazCHARISMA() { return this->echarisma; };
		int ukazRYCHLOST() { return this->erychlost; };
		int ukazPOHYBLIVOST() { return this->epohyblivost; };
};

#endif
