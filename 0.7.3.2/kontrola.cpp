#include "knih.h"

void player::kontrola_gen()
{
	
}

void player::kontrola_klavesnice()
{
	char znak[2];
	int znacka;
	znak[0] = getch();
	printf("\n\t%x     ",znak);
}

void player::statistika_gen()
{
	int pole[50], i, hodnoty[25];
	char radek[200], *p;
	FILE *f;
	
	f = fopen("STATISTIKA.txt","w");
	fprintf(f,"0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|");
	fclose(f);
	
	while(1)
	{
		for(i=0;i<5;i++)
		{
			pole[i] = numgen(100); 
			sleep(1);
		}
		
		for(i=0;i<5;i++)
		{
			printf("%d     ", pole[i]);
		}
		
		f = fopen("STATISTIKA.txt","r");
		
		
		while(fgets(radek,200,f)!=NULL)
		{
			p = strtok(radek,"|");
			hodnoty[0] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[1] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[2] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[3] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[4] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[5] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[6] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[7] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[8] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[9] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[10] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[11] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[12] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[13] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[14] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[15] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[16] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[17] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[18] = atoi(p);
			p = strtok(NULL,"|");
			hodnoty[19] = atoi(p);
		}
		
		fclose(f);
		
		for(i=0;i<5;i++)
		{
			if(pole[i] < 5) hodnoty[0] += 1;
			else
			{
				if(pole[i] < 10) hodnoty[1] += 1;
				else
				{
					if(pole[i] < 15) hodnoty[2] += 1;
					else
					{
						if(pole[i] < 20) hodnoty[3] += 1;
						else
						{
							if(pole[i] < 25) hodnoty[4] += 1;
							else
							{
								if(pole[i] < 30) hodnoty[5] += 1;
								else
								{
									if(pole[i] < 35) hodnoty[6] += 1;
									else
									{
										if(pole[i] < 40) hodnoty[7] += 1;
										else
										{
											if(pole[i] < 45) hodnoty[8] += 1;
											else
											{
												if(pole[i] < 50) hodnoty[9] += 1;
												else
												{
													if(pole[i] < 55) hodnoty[10] += 1;
													else
													{
														if(pole[i] < 60) hodnoty[11] += 1;
														else
														{
															if(pole[i] < 65) hodnoty[12] += 1;
															else
															{
																if(pole[i] < 70) hodnoty[13] += 1;
																else
																{
																	if(pole[i] < 75) hodnoty[14] += 1;
																	else
																	{
																		if(pole[i] < 80) hodnoty[15] += 1;
																		else
																		{
																			if(pole[i] < 85) hodnoty[16] += 1;
																			else
																			{
																				if(pole[i] < 90) hodnoty[17] += 1;
																				else
																				{
																					if(pole[i] < 95) hodnoty[18] += 1;
																					else
																					{
																						hodnoty[19] += 1;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		f = fopen("STATISTIKA.txt","w");
		
		fprintf(f,"%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|", hodnoty[0], hodnoty[1], hodnoty[2], hodnoty[3], hodnoty[4], hodnoty[5], hodnoty[6], hodnoty[7], hodnoty[8], hodnoty[9], hodnoty[10], hodnoty[11], hodnoty[12], hodnoty[13], hodnoty[14], hodnoty[15], hodnoty[16], hodnoty[17], hodnoty[18], hodnoty[19]);
		
		fclose(f);
	}
	
}

void player::barvy()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " I want to be nice today!" << endl;
  }
}
