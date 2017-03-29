#include <stdio.h>
#include "depositcalc.h"

int main()
{
	int startup, int term;
	
	printf("Введите сумму вклада: ");
	scanf("%d", &startup)
	
	printf("Введите срок вклада: ");
	scanf("%d", &term);
	
	Check(term, startup);
	
	printf("%d", summa(startup, term);
	
	return 0;
}
