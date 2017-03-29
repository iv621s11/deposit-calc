#include <stdio.h>
#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

int check(int term, int startup)
{
	if(startup <= 10000)
	{	
		printf("Неправильная сумма вклада");
		return 0;
	}
	
	if(term < 0 || term > 365)
	{
		printf("Неправильно введен срок вклада");
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
#endif
