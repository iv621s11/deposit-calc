#include <depositcalc.h>
#include <ctest.h>

CTEST(term_check_test, test1-valid-0_term)
{	
	int term = 0;
	int startup = 150000;
	
	int result = check(term, startup);
	
	ASSERT_TRUE(result);
}

CTEST(term_check_test, test2_invalid-negative_term)
{	
	int term = -50;
	int startup = 150000;
	
	int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(term_check_test, test3-valid-365_term)
{	
	int term = 365;
	int startup = 150000;
	
	int result = check(term, startup);

	ASSERT_TRUE(result);
}

CTEST(check_test, test4-invalid-more_365_term)
{	
	int term = 367;
	int startup = 150000;
	
	int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test1-invalid-negative_startup)
{	
	int term = 0;
	int startup = -15;
	
	int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test2-invalid-0_startup)
{	
	int term = 0;
	int startup = 0;
	
	int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test3-invalid-less_10000_startup)
{	
	int term = 0;
	int startup = 1000;
	
	int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test4-valid-10000_startup)
{	
	int term = 0;
	int startup = 10000;
	
	int result = check(term, startup);

	ASSERT_TRUE(result);
}

CTEST(startup_check_test, test5-valid-more_10000_startup)
{	
	int term = 0;
	int startup = 1000000;
	
	int result = check(term, startup);
	
	ASSERT_TRUE(result);
}
