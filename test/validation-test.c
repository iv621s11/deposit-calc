#include "depositcalc.h"
#include "ctest.h"

//Описание
//Тест на правильность определения истина/ложь функции check.
//В тесте берутся конкретные значения выражений term и startup.
//Выражение полученное с помощью функции check сравнивается с ожидаемым(true/false).

//Eng description:
//Test the correctness of true/false function check.
//In the test come from a specific value of term and startup.
//The expression obtained using the function check is compared with the expected(true/false)

CTEST(term_check_test, test1_valid_0_term)
{	
	const int term = 0;
	const int startup = 150000;
	
	const int result = check(term, startup);
	
	ASSERT_TRUE(result);
}

CTEST(term_check_test, test2_invalid_negative_term)
{	
	const int term = -50;
	const int startup = 150000;
	
	const int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(term_check_test, test3_valid_365_term)
{	
	const int term = 365;
	const int startup = 150000;
	
	const int result = check(term, startup);

	ASSERT_TRUE(result);
}

CTEST(term_check_test, test4_invalid_more_365_term)
{	
	const int term = 367;
	const int startup = 150000;
	
	const int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test1_invalid_negative_startup)
{	
	const int term = 0;
	const int startup = -15;
	
	const int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test2_invalid_0_startup)
{	
	const int term = 0;
	const int startup = 0;
	
	const int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test3_invalid_less_10000_startup)
{	
	const int term = 0;
	const int startup = 1000;
	
	const int result = check(term, startup);

	ASSERT_FALSE(result);
}

CTEST(startup_check_test, test4_valid_10000_startup)
{	
	const int term = 0;
	const int startup = 10000;
	
	const int result = check(term, startup);

	ASSERT_TRUE(result);
}

CTEST(startup_check_test, test5_valid_more_10000_startup)
{	
	const int term = 0;
	const int startup = 1000000;
	
	const int result = check(term, startup);
	
	ASSERT_TRUE(result);
}
