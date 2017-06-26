#include "depositcalc.h"
#include "ctest.h"

//Описание:
//Тест на правильность подсчета различных выражений функцией summa.
//В тесте берутся конкретные значения term и startup.
//Затем, выражение полученное с помощью функции summa сравнивается с ожидаемым.

//Eng description:
//Test the correctness of the calculation of the various expressions function summa.
//In the test come from a specific value of term and startup.
//Then, the expression obtained using summa is compared with the expected.

CTEST(summa, calc_less_30_days_less_100k)
{	
	const int term = 1;
	const int startup = 10001;
	
	const float result = summa(term, startup);
	
	const float expect = -1000.10;
	
	ASSERT_EQUAL(expect, result);
}
	
CTEST(summa, calc_less_120_days_less_100k)
{	
	const int term = 31;
	const int startup = 10001;
	
	const float result = summa(term, startup);
	
	const float expect = 16.99;
	
	ASSERT_EQUAL(expect, result);
}
	
CTEST(summa, calc_less_240_days_less_100k)
{	
	const int term = 141;
	const int startup = 10001;
	
	const float result = summa(term, startup);
	
	const float expect = 231.80;
	
	ASSERT_EQUAL(expect, result);
}

CTEST(summa, calc_less_365_days_less_100k)
{	
	const int term = 241;
	const int startup = 10001;
	
	const float result = summa(term, startup);
	
	const float expect = 792.41;
	
	ASSERT_EQUAL(expect, result);
}

CTEST(summa, calc_less_30_days_more_100k)
{	
	const int term = 1;
	const int startup = 100001;
	
	const float result = summa(term, startup);
	
	const float expect = -10000.10;
	
	ASSERT_EQUAL(expect, result);
}

CTEST(summa, calc_less_120_days_more_100k)
{	
	const int term = 31;
	const int startup = 100001;
	
	const float result = summa(term, startup);
	
	const float expect = 254.80;
	
	ASSERT_EQUAL(expect, result);
}

CTEST(summa, calc_less_240_days_more_100k)
{	
	const int term = 121;
	const int startup = 100001;
	
	const float result = summa(term, startup);
	
	const float expect = 2652.08;
	
	ASSERT_EQUAL(expect, result);
}

CTEST(summa, calc_less_365_days_more_100k)
{	
	const int term = 241;
	const int startup = 100001;
	
	const float result = summa(term, startup);
	
	const float expect = 9904.21;
	
	ASSERT_EQUAL(expect, result);
}


