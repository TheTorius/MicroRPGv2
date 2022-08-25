#include "knih.h"

void player::endturnevent()
{
	system("cls");
	int event_type=0;
	
	event_type = numgen(5);
	
	switch(event_type)
	{
		case 1:
			babicka();
			break;
		
		case 2:
			scream();
			break;
		
		case 3:
			obchodnik();
			break;
			
		case 4:
			pocestny();
			break;
		
		case 5:
			zoldak();
			break;
	}
}

void player::babicka()
{
	int gcislo, vyber;
	char vyb[2];
	
	gcislo = numgen(100);
	reset:
	system("cls");
	
	printf("\n\n\tPotkal(a) jsi babicku, ktera te zada o pomoc.");
	printf("\n\tMas dve moznosti co udelat:");
	printf("\n\t1 - Pomoci babicce");
	printf("\n\t2 - Vyhnout se babicce");
	printf("\n\n\tTve rozhodnuti: ");
	sleep(1);
	cin >> vyber;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
	
	if(vyber == 1)
	{
		if(gcislo < 20 || ((gcislo > 40 && gcislo <= 50) || gcislo > 85))
		{
			gcislo = numgen(3);
			
			switch(gcislo)
			{
				case 1:
					hp = hp - 5;
					printf("\n\n\tBabicka byla vyzbrojena nozem a zranila te!");
					eventlog(1,5,1,1);
					break;
				
				case 2:
					mince -= 2;
					printf("\n\n\tPri tve pomoci sis nevsiml, ze te babicka okradla!");
					eventlog(1,2,2,1);
					break;
				
				case 3:
					printf("\n\n\tByla to lest! Musis bojovat s bandity!");	
					eventlog(1,0,3,1);
					bandit();
					break;
					
				default:
					break;
					
			}
		}
		else
		{
			gcislo = numgen(3);
			
			switch(gcislo)
			{
				case 1:
					mince += 2;
					printf("\n\n\tBabicka se ti dekuje a darovala ti mince!");
					eventlog(1,2,4,1);
					break;
				
				case 2:
					jidlo += 3;
					printf("\n\n\tBabicka se ti odvdecila darovanim 3ks jidla!");
					eventlog(1,3,5,1);
					break;
				
				case 3:
					printf("\n\n\tPomohl(a) jsi babicce na sve ceste zivotem.");
					eventlog(1,0,6,1);
					break;
					
				default:
					break;
			}
		}
	}
	else
	{
		printf("\n\n\tBabicce si ses vyhl(a). Snad to nebylo spatne rozhodnuti.");
		eventlog(1,0,0,2);
	}
	sleep(2);
	getch();
}

void player::scream()
{
	int gcislo, vyber, vyb;
	
	gcislo = numgen(100);
	
	reset:
	system("cls");
	
	printf("\n\n\tPri tve prochazce jsi nahle uslysel vykrik. Nevis, co se stalo.");
	printf("\n\tCo se rozhodnes udelat?");
	printf("\n\tMas dve moznosti co udelat:");
	printf("\n\t1 - Jit za zdrojem tohoto vykriku");
	printf("\n\t2 - Ignorovat, zes ten vykrik vubec slysel");
	printf("\n\n\tTve rozhodnuti: ");
	sleep(1);
	cin >> vyber;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		goto reset;
	}
	
	system("cls");
	
	switch(vyber)
	{
		case 1:
			
			if(gcislo < 15 || ((gcislo > 40 && gcislo < 55) || gcislo > 90)) // Šance 40%
			{
				printf("\n\tSkrek utichl, avsak nasel jsi bednu s vecma. Dostavas: ");
				printf("\n\t2 seminka,  5 minci,  3 kusy jidla");
				jidlo += 3;
				seminka += 2;
				mince += 5;
				sleep(2);
				getch();
			}
			else
			{
				res:
				system("cls");
				printf("\n\tPri dosahnuti zdroje vidis jak zenu provokuje bandita!");
				printf("\n\tCo se rozhodnes udelat?");
				printf("\n\t1 - Bojovat s banditou");
				printf("\n\t2 - Nechat banditu na pokoji");
				printf("\n\n\tVyber: ");
				cin >> vyb;
				
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					goto res;
				}
				
				switch(vyb)
				{
					case 1:
						
						system("cls");
						
						bandit();
						
						break;
						
					case 2:
						
						system("cls");
						printf("\n\tNechal jsi banditu na pokoji. Snad ses nerozhodl(a) spatne.");
						sleep(1);
						getch();
				}
			}
			
			break;
			
		case 2:
			
			system("cls");
			printf("\n\tRozhodl si se udalosti vyhnout, snad ses nerozhodl(a) spatne.");
			sleep(1);
			getch();
	}
}

void player::obchodnik()
{
	int gcislo, vyber, vyb;
	int j,m,s;
	
	gcislo = numgen(100);
	
	reset:
	system("cls");
	
	printf("\n\n\tNarazil jsi na obchodníka. Mozna by mel neco na vymenu.");
	printf("\n\tMas dve moznosti co udelat:");
	printf("\n\t1 - Pohovorit s obchodnikem");
	printf("\n\t2 - Obejit ho a jit si svou cestou");
	printf("\n\n\tTve rozhodnuti: ");
	sleep(1);
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
			
			if(gcislo < 30 || ((gcislo > 40 && gcislo < 70) || gcislo > 80)) // Sance 80%
			{
				j = numgen(5);
				m = numgen(5);
				s = numgen(5);
				res:
				system("cls");
				printf("\n\tObchodnik vypada v pohode. Nabizi ti nasledujici vybaveni:");
				printf("\n\tTve mince: %d         Tve jidlo: %d", mince,jidlo);
				printf("\n\t1 - Jidlo: %d   2mince/ks",j);
				printf("\n\t2 - Mince: %d   1mince/jidlo",m);
				printf("\n\t3 - Seminka:  %d   1mince/ks",s);
				printf("\n\t4 - Konec obchodu");
				printf("\n\n\tVyber: ");
				cin >> vyb;
				
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					goto res;
				}
				
				switch(vyb)
				{
					case 1:
						
						if(mince > 1)
						{
							mince -= 2;
							jidlo++;
							j--;
						}
						else
						{
							printf("\n\tNemas dost minci!");
							getch();
						}
						goto res;
						break;
					
					case 2:
						
						if(jidlo > 0)
						{
							mince++;
							jidlo--;
							m--;
						}
						else
						{
							printf("\n\tNemas dost jidla!");
							getch();
						}
						goto res;
						break;
					
					case 3:
						
						if(mince > 0)
						{
							seminka++;
							mince--;
							s--;
						}
						else
						{
							printf("\n\tNemas dost minci!");
							getch();
						}
						goto res;
						break;
						
					case 4:
						
						system("cls");
						
						printf("\n\tRozhodl ses od obchodnika odejit. Snad mas vse.");
						getch();
						
						break;
				}
			}
			else
			{
				re:
				system("cls");
				
				printf("\n\tObchodnik ti nabizi balicek za 3 mince.");
				printf("\n\tChces mu na nabidku kyvnout?");
				printf("\n\t(1 - Ano | 2 - Ne)");
				printf("\n\n\tVyber: ");
				
				cin >> vyb;
				
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					goto re;
				}
				
				switch(vyb)
				{
					case 1:
						usleep(100);
						gcislo = numgen(100);
						
						if(gcislo < 20 || ((gcislo > 40 && gcislo < 55) || gcislo > 85))
						{
							system("cls");
							
							printf("\n\tDal ti balicek, ten byl ale naplneny cihlama.");
							mince = mince - 5;
							getch();
						}
						else
						{
							system("cls");
							
							printf("\n\tBalicek obsahoval jidlo.");
							mince = mince - 5;
							jidlo = jidlo + 3;
						}
						break;
					
					case 2:
						
						system("cls");
						
						printf("\n\tRozhodl ses od obchodnika odejit.");
						
						usleep(100);
						getch();
						break;
				}
			}
			break;
		
		case 2:
			
			system("cls");
			
			printf("\n\tRozhodl ses obchodnika obejit. Snad jsi o nic neprisel.");
			
			getch();
			
			break;
	}
}

void player::pocestny()
{
	int gcislo, vyber;
	
	gcislo = numgen(100);
	
	reset:
	system("cls");
	
	printf("\n\n\tStretl si se s pocestnym. Pta se te, jestli bys mu pomohl.");
	printf("\n\tMas dve moznosti co udelat:");
	printf("\n\t1 - Pomoci pocestnemu");
	printf("\n\t2 - Vyhnout se mu jako cert krizi");
	printf("\n\n\tTve rozhodnuti: ");
	sleep(1);
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
			
			if(gcislo < 20 || ((gcislo > 40 && gcislo < 55) || gcislo > 85))
			{
				system("cls");
				
				printf("\n\tZ pocestneho se vyklubal bandita! Zranil te a musis bojovat!");
				
				hp = hp - 5;
				
				getch();
				bandit();
			}
			else
			{
				system("cls");
				
				printf("\n\tPocestny te pozadal o cestu. Tus mu ukazal a tak te odmenil mincemi.");
				
				mince = mince + 2;
				
				getch();
			}
			break;
		
		case 2:
			
			system("cls");
			
			printf("\n\tPocestnemu ses vyhnul. Snad jsi neudelal spatny skutek.");
			
			usleep(100);
			getch();
			
			break;
	}
}

void player::zoldak()
{
	int gcislo, vyber, vyb;
	
	gcislo = numgen(100);
	
	reset:
	system("cls");
	
	printf("\n\n\tPri ceste te zastavil zoldak. Co budes delat?");
	printf("\n\tMas dve moznosti co udelat:");
	printf("\n\t1 - Utikat");
	printf("\n\t2 - Zeptat se, co chce");
	printf("\n\t3 - Tasit meè");
	printf("\n\n\tTve rozhodnuti: ");
	sleep(1);
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
			
			if(gcislo < 20 || ((gcislo > 40 && gcislo < 55) || gcislo > 85))
			{
				system("cls");
				
				printf("\n\tPovedlo se ti plachnout!");
				
				getch();
			}
			else
			{
				system("cls");
				
				printf("\n\tZoldak te chytil. Nedava ti na vyber nez s tebou bojovat!");
				
				getch();
				
				straz();
			}
			break;
		
		case 2:
			
			if(gcislo < 15 || ((gcislo > 45 && gcislo < 55) || gcislo > 80))
			{
				res:
					
				system("cls");
				
				printf("\n\tVyhrozuje ti. Chce po tobe 2 mince!");
				printf("\n\tDas mu mince?");
				printf("\n\t(1 - ANO | 2 - NE)");
				printf("\n\n\tVyber: ");
				
				cin >> vyb;
				
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					goto res;
				}
				
				switch(vyb)
				{
					case 1:
						
						system("cls");
						
						printf("\n\tZoldaka jsi podplatil a nechava te jit.");
						
						mince = mince - 2;
						
						getch();
						
						break;
					
					case 2:
						
						system("cls");
						
						printf("\n\tRozhodl jsi zoldaku nic nedat. Ted to z tebe chce vytriskat!");
						
						getch();
						
						straz();
						
						break;
				}
			}
			break;
			
		case 3:
			
			system("cls");
			
			printf("\n\tRozhodl ses bojovat!");
			
			getch();
			
			straz();
			
			break;
	}
}
