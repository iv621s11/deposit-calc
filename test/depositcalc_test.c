#include <depositcalc.h>
#include <ctest.h>

CTEST(term_check_test, test1)
{	
	int term = 0;
	int startup = 150000;
	
	int result = check(term, startup);
	
	int expected = 	1;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(term_check_test, test2)
{	
	int term = -50;
	int startup = 150000;
	
	int result = check(term, startup);
	
	int expected = 	0;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(term_check_test, test3)
{	
	int term = 365;
	int startup = 150000;
	
	int result = check(term, startup);
	
	int expected = 	1;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(check_test, test4)
{	
	int term = 367;
	int startup = 150000;
	
	int result = check(term, startup);
	
	int expected = 	1;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(startup_check_test, test1)
{	
	int term = 0;
	int startup = -15;
	
	int result = check(term, startup);
	
	int expected = 	0;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(startup_check_test, test2)
{	
	int term = 0;
	int startup = 0;
	
	int result = check(term, startup);
	
	int expected = 	0;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(startup_check_test, test3)
{	
	int term = 0;
	int startup = 1000;
	
	int result = check(term, startup);
	
	int expected = 	0;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(startup_check_test, test4)
{	
	int term = 0;
	int startup = 10000;
	
	int result = check(term, startup);
	
	int expected = 	1;
	
	ASSERT_EQUAL(expected, result);
}

CTEST(startup_check_test, test5)
{	
	int term = 0;
	int startup = 1000000;
	
	int result = check(term, startup);
	
	int expected = 	1;
	
	ASSERT_EQUAL(expected, result);
}

