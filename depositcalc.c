#include <stdio.h>
#include "depositcalc.h"

int check(int term, int startup);
float summa(int term, int startup);

int main()
{
	int startup, term;
	
	printf("Введите сумму вклада: ");
	scanf("%d", &startup);
	
	printf("Введите срок вклада: ");
	scanf("%d", &term);
	
	if(check(term, startup) == 1)
	{
		printf("Ваш доход со вклада составит: %.2f\n", summa(term, startup));
		return 0;
	}
	else 
	return -1;
}
