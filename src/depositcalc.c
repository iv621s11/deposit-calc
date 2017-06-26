#include <stdio.h>
#include "depositcalc.h"

int check(int term, int startup)
{
	int f;
	if(startup < 10000)
	{	
		printf("ERROR: Неправильная сумма вклада\n");
		f = 1;
	}
	
	if(term < 0 || term > 365)
	{
		printf("ERROR: Неправильно введен срок вклада\n");
		f = 1;
	}
	
	if(f == 1)
	{
		return 0;
	}
	return 1;
}


float summa(int term, int startup)
{
	float summa;
	
	if(term < 31)
	{
		summa = startup * -0.1;
		return summa;
	}
	
	if(startup < 100000)
	{
		if(term < 121)
		{
			summa = startup * 0.02 / 365 * term;
		}
		
		else if(term < 241)
		{
			summa = startup * 0.06 / 365 * term;
		}
		
		else if(term < 366)
		{
			summa = startup * 0.12 / 365 * term;
		}
	} 
	else if(startup >= 100000)
	{
		  if(term < 121)
		{
			summa = startup * 0.03 / 365 * term;
		}
		
		else if(term < 241)
		{
			summa = startup * 0.08 / 365 * term;
		}
		
		else if(term < 366)
		{
			summa = startup * 0.15 / 365 * term;
		}
		
	}
	return summa;
}
