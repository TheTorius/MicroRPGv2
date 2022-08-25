#include "knih.h"

int main()
{
	int vyber, result;
	player player;
	player.ini();
	SetConsoleTitle("MicroRPGv2");
	system("cls");
	
	if(player.setup_load() == 0)
	{
		printf("\n\n\n\t/////////////////////////////////////");
		printf("\n\t/////         loading...        /////");
		printf("\n\t/////////////////////////////////////");
		sleep(5);
	}
	
	if(player.setup_load() == 0 || player.setup_load() == 1)
	{
		system("cls");
		printf("\n");
		printf("\n\t/////     /////  //                           ///////   ///////   ///////");
		printf("\n\t// //    //  //                               //    //  //    //  //   //");
		printf("\n\t//  //  //   //  //  //////  // ///  ///////  //    //  //    //  //     ");
		printf("\n\t//   ////    //  //  //      ///     //   //  ///////   ///////   //  ///");
		printf("\n\t//           //  //  //      //      //   //  //  ///   //        //   //");
		printf("\n\t//           //  //  //////  //      ///////  //   ///  //        ///////\n\n\t");
		system("echo                             by Lukáš Horák");
		if(player.setup_load() == 1)
		{
			sleep(2);
		}
		else
		{
			sleep(3);
		}
	}
	
//	printf("\n\n\t                             by Lukas Horak");
/*	SMALL_RECT windowSize = { 0, 0, 50, 20 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);*/
	setjmp(player.jumpBuf);
	setjmp(player.jumpBuf2);
	setjmp(player.jumpBuf3);
	setjmp(player.jumpBuf4);

	while(1)
	{	
		chdir("harvest");
		system("del temporary.txt");
		chdir("..");
		reset:
		system("cls");
		printf("\n\t\tHlavni menu");
		printf("\n\t1 - Nova hra");
		printf("\n\t2 - Nacist hru");
		printf("\n\t3 - Informace");
		printf("\n\t4 - Nastaveni");
		printf("\n\t5 - Titulky");
		printf("\n\t6 - Benchmark generatoru cisel");
		printf("\n\t7 - Vysvetleni hry [READ.ME]");
		printf("\n\t8 - Konec");
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
				player.nova_hra();
				break;
				
			case 2:
				system("cls");
				player.nacist_hru();
				break;
					
			case 3:
				system("cls");
				player.informace();
				break;	
					
			case 4:
				system("cls");
				player.setup();
				break;
						
			case 5:
				system("cls");
				player.titulky();
				break;
			
			case 6:
				system("cls");
				player.statistika_gen();
				break;
				
			case 7:
				system("cls");
				player.vysvetleni();
				break;
				
			case 8:
				exit(1);
		}
	}
}

