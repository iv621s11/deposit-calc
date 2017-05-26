#include <depositcalc.h>
#include <ctest.h>

CTEST(summa, calc-less_30_days-less_100k)
{	
	int term = 1;
	int startup = 10001;
	
	int result = summa(term, startup);
	
	int expected = -1000.10
	
	ASSERT_EQUAL(expected, result);
}
	
CTEST(summa, calc-less_120_days-less_100k)
{	
	int term = 31;
	int startup = 10001;
	
	int result = summa(term, startup);
	
	int expected = 16.99
	
	ASSERT_EQUAL(expected, result);
}
	
CTEST(summa, calc-less_240_days-less_100k)
{	
	int term = 141;
	int startup = 10001;
	
	int result = summa(term, startup);
	
	int expected = 231.80
	
	ASSERT_EQUAL(expected, result);
}

CTEST(summa, calc-less_365_days-less_100k)
{	
	int term = 241;
	int startup = 10001;
	
	int result = summa(term, startup);
	
	int expected = 792.41
	
	ASSERT_EQUAL(expected, result);
}

CTEST(summa, calc-less_30_days-more_100k)
{	
	int term = 1;
	int startup = 100001;
	
	int result = summa(term, startup);
	
	int expected = -10000.10
	
	ASSERT_EQUAL(expected, result);
}

CTEST(summa, calc-less_120_days-more_100k)
{	
	int term = 31;
	int startup = 100001;
	
	int result = summa(term, startup);
	
	int expected = 254.80
	
	ASSERT_EQUAL(expected, result);
}

CTEST(summa, calc-less_240_days-less_100k)
{	
	int term = 121;
	int startup = 100001;
	
	int result = summa(term, startup);
	
	int expected = 2652.08
	
	ASSERT_EQUAL(expected, result);
}

CTEST(summa, calc-less_365_days-more_100k)
{	
	int term = 241;
	int startup = 100001;
	
	int result = summa(term, startup);
	
	int expected = 9904.21
	
	ASSERT_EQUAL(expected, result);
}


