/*
 * UnitTest.h
 *
 * Created: 2/8/2020 5:09:05 AM
 *  Author: MahmoudMorsy
 */ 


#ifndef UNITTEST_H_
#define UNITTEST_H_
#include "Common.h"
#if UNIT_TESTING == STD_ON
#include <stdio.h>

#define printf_dec_format(x) _Generic((x), \
char: "%c", \
signed char: "%hhd", \
unsigned char: "%hhu", \
signed short: "%hd", \
unsigned short: "%hu", \
signed int: "%d", \
unsigned int: "%u", \
long int: "%ld", \
unsigned long int: "%lu", \
long long int: "%lld", \
unsigned long long int: "%llu", \
float: "%f", \
double: "%f", \
long double: "%Lf", \
char *: "%s", \
void *: "%p")

#define print(x) printf(printf_dec_format(x), x)

#define UT_PASS_MSG(ModuleName, TestName, PassedMsg) printf("PASSED @%s (%s): %s.\n", ModuleName, TestName, PassedMsg)
#define UT_FAIL_MSG(ModuleName, TestName, FailureMsg) printf("FAILED @%s (%s): %s.\n", ModuleName, TestName, FailureMsg)
	
#define UT_CONDITION_EVAL(Condition, CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg)\
if (Condition)\
{\
	UT_PASS_MSG(ModuleName, TestName, PassedMsg);\
}\
else\
{\
	UT_FAIL_MSG(ModuleName, TestName, FailureMsg);\
	printf("   Expected Value = ");\
	print(ExpectedValue);\
	printf(" ,but Actual Value = ");\
	print(CompareVariable);\
	printf(".\n");\
}

/* ASSERT_EQ : Compares CompareVariable and ExpectedValue variables and checks if they are equal
 * ModuleName: Module Name
 * TestName: Name of your test case
 * CompareVariable: Variable to be compared
 * ExpectedValue: Value to compare the variable
 * (CompareVariable and ExpectedValue) have to be with the same data type
 * PassedMsg: Custom Message to be printed if test succeeded
 * FailureMsg: Custom Message to be printed if test fails
 */
#define UT_ASSERT_EQ(TestName, ModuleName, CompareVariable,  ExpectedValue,  PassedMsg, FailureMsg)\
	UT_CONDITION_EVAL(CompareVariable == ExpectedValue,  CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg);

/* ASSERT_EQ : Compares CompareVariable and ExpectedValue variables and checks if they are equal
 * ModuleName: Module Name
 * TestName: Name of your test case
 * CompareVariable: Variable to be compared
 * ExpectedValue: Value to compare the variable
 * (CompareVariable and ExpectedValue) have to be with the same data type
 * PassedMsg: Custom Message to be printed if test succeeded
 * FailureMsg: Custom Message to be printed if test fails
 */
#define UT_ASSERT_NOTEQ(TestName, ModuleName, CompareVariable,  ExpectedValue,  PassedMsg, FailureMsg)\
	UT_CONDITION_EVAL(CompareVariable != ExpectedValue,  CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg);
	
/* ASSERT_LESSTHAN : Compares CompareVariable and ExpectedValue variables and checks if CompareVariable is less than ExpectedValue
 * ModuleName: Module Name
 * TestName: Name of your test case
 * CompareVariable: Variable to be compared
 * ExpectedValue: Value to compare the variable
 * (CompareVariable and ExpectedValue) have to be with the same data type
 * PassedMsg: Custom Message to be printed if test succeeded
 * FailureMsg: Custom Message to be printed if test fails
 */
#define UT_ASSERT_LESSTHAN(TestName, ModuleName, CompareVariable,  ExpectedValue,  PassedMsg, FailureMsg)\
	UT_CONDITION_EVAL(CompareVariable < ExpectedValue,  CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg);

/* ASSERT_GREATERTHAN : Compares CompareVariable and ExpectedValue variables and checks if CompareVariable is greater than ExpectedValue
 * ModuleName: Module Name
 * TestName: Name of your test case
 * CompareVariable: Variable to be compared
 * ExpectedValue: Value to compare the variable
 * (CompareVariable and ExpectedValue) have to be with the same data type
 * PassedMsg: Custom Message to be printed if test succeeded
 * FailureMsg: Custom Message to be printed if test fails
 */
#define UT_ASSERT_GREATERTHAN(TestName, ModuleName, CompareVariable,  ExpectedValue,  PassedMsg, FailureMsg)\
	UT_CONDITION_EVAL(CompareVariable > ExpectedValue,  CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg);

/* ASSERT_LESSTHAN_OR_EQ : Compares CompareVariable and ExpectedValue variables and checks if CompareVariable is less or equal than ExpectedValue
 * ModuleName: Module Name
 * TestName: Name of your test case
 * CompareVariable: Variable to be compared
 * ExpectedValue: Value to compare the variable
 * (CompareVariable and ExpectedValue) have to be with the same data type
 * PassedMsg: Custom Message to be printed if test succeeded
 * FailureMsg: Custom Message to be printed if test fails
 */
#define UT_ASSERT_LESSTHAN_OR_EQ(TestName, ModuleName, CompareVariable,  ExpectedValue,  PassedMsg, FailureMsg)\
	UT_CONDITION_EVAL(CompareVariable <= ExpectedValue,  CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg);

/* ASSERT_GREATERTHAN : Compares CompareVariable and ExpectedValue variables and checks if CompareVariable is greater than ExpectedValue
 * ModuleName: Module Name
 * TestName: Name of your test case
 * CompareVariable: Variable to be compared
 * ExpectedValue: Value to compare the variable
 * (CompareVariable and ExpectedValue) have to be with the same data type
 * PassedMsg: Custom Message to be printed if test succeeded
 * FailureMsg: Custom Message to be printed if test fails
 */
#define UT_ASSERT_GREATERTHAN_OR_EQ(TestName, ModuleName, CompareVariable,  ExpectedValue,  PassedMsg, FailureMsg)\
	UT_CONDITION_EVAL(CompareVariable >= ExpectedValue,  CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg);

void UT_RunAllTests();

#endif
#endif /* UNITTEST_H_ */