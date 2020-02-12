/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              UnitTest.h
* MODULE:            Unit Test
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Header file for Unit test internal environment and macro functions.
* CREATION DATE:     8/2/2020
* MODIFICATION DATE: 9/2/2020
**************************************************************************************************/
#ifndef UNITTEST_H_
#define UNITTEST_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Common.h"
#if UNIT_TESTING == STD_ON
#include <stdio.h>

/**************************************************************************************************
*                                         MACRO FUNCTIONS                                         *
**************************************************************************************************/
/* Generic printing macro function */
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
/* Macro function to print test cases header once */
#define UT_PRINT_HEADER() printf(" STATUS | MODULE | TESTCASE |   CUSTOM MESSAGE   |\n");\
						  printf("--------------------------------------------------\n")

/* Macro function to print a separator line between test cases */
#define UT_SEPARATE_TESTCASES() printf("\n")

/* Macro function to print a separator line between test modules */
#define UT_SEPARATE_TESTMODULES() printf(".                   ----------                   .\n")

/* Generic printing macro function wrapping */
#define print(x) printf(printf_dec_format(x), x)

/* Macro function for printing test passed message */
#define UT_PASS_MSG(ModuleName, TestName, PassedMsg) printf(" PASSED | @%s [%s]: %s.\n", ModuleName, TestName, PassedMsg)

/* Macro function for printing test failed message */
#define UT_FAIL_MSG(ModuleName, TestName, FailureMsg) printf(" FAILED | @%s [%s]: %s.\n", ModuleName, TestName, FailureMsg)

/* Generic macro function to evaluate a passed condition */
#define UT_CONDITION_EVAL(Condition, CompareVariable,  ExpectedValue,  TestName, ModuleName, PassedMsg, FailureMsg)\
if (Condition)\
{\
	UT_PASS_MSG(ModuleName, TestName, PassedMsg);\
}\
else\
{\
	UT_FAIL_MSG(ModuleName, TestName, FailureMsg);\
	printf("    Expected Value = ");\
	print(ExpectedValue);\
	printf(", but Actual Value = ");\
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


/**************************************************************************************************
*                                       FUNCTION PROTOTYPES                                       *
**************************************************************************************************/
void UT_RunAllTests();

#endif
#endif /* UNITTEST_H_ */