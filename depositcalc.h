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
}


