/* unitTests.c : dynamic array unit tests */
#include <stdio.h>
#include "type.h"
#include "ListDeque.h"
#include "c_unit.h"

void testReverse()
{
	int testNum = 1;
	/*	create a container to manage test results */
	/*	note that this is a stack variable, so despite the fact that 
		we will use & to pass a pointer to it into functions, we 
		DO NOT need to free() it.
	*/
	UnitTestResult testResults;
	ListDeque testDeque;
	TYPE val1 = 'A';
	TYPE val2 = 'B';
	TYPE val3 = 'C';
	int i;
	initListDeque(&testDeque);
		
	printf("\nTesting Reverse Functions\n****************************************\n");
	
	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "testReverse");
	for(i = 0; i < 2; ++i)
	{
		addFrontListDeque(&testDeque, val3); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val2); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val1); printListDeque(&testDeque);
	}

	reverseListDeque(&testDeque);
	/* perform the test */
	/* check return values and postconditions */
	if(testDeque.size != 6)
		testResults.errMsg = "Size error";
	else if(testDeque.head->value != 'C')
		testResults.errMsg = "1st value wrong";
	else if(testDeque.head->next->value != 'B')
		testResults.errMsg = "2nd value wrong";
	else if(testDeque.head->next->next->value != 'A')
		testResults.errMsg = "3rd value wrong";
	else
		testResults.success = 1;
	/* show us the results from the test */
	printResults(&testResults);
}

void testaddLinkAfter()
{
		int testNum = 1;
	/*	create a container to manage test results */
	/*	note that this is a stack variable, so despite the fact that 
		we will use & to pass a pointer to it into functions, we 
		DO NOT need to free() it.
	*/
	UnitTestResult testResults;
	ListDeque testDeque;
	DLink* lnk;
	TYPE val1 = 'A';
	TYPE val2 = 'B';
	TYPE val3 = 'C';
	int i;
	initListDeque(&testDeque);
		
	printf("\nTesting addLinkAfter Functions\n****************************************\n");
	
	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "testaddLinkAfter");
	for(i = 0; i < 2; ++i)
	{
		addFrontListDeque(&testDeque, val3); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val2); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val1); printListDeque(&testDeque);
	}
	lnk = (DLink*) malloc(sizeof(DLink));
	lnk->value = 'S';
	lnk->next = NULL;
	lnk->prev = NULL;

	addLinkAfterListDeque(&testDeque, testDeque.head->next, lnk);
	/* perform the test */
	/* check return values and postconditions */
	if(testDeque.size != 7)
		testResults.errMsg = "Size error";
	else if(testDeque.head->next->next->value != 'S')
		testResults.errMsg = "insert value wrong";

	else
		testResults.success = 1;
	/* show us the results from the test */
	printResults(&testResults);
}

void testaddLinkBefore()
{
			int testNum = 1;
	/*	create a container to manage test results */
	/*	note that this is a stack variable, so despite the fact that 
		we will use & to pass a pointer to it into functions, we 
		DO NOT need to free() it.
	*/
	UnitTestResult testResults;
	ListDeque testDeque;
	DLink* lnk;
	TYPE val1 = 'A';
	TYPE val2 = 'B';
	TYPE val3 = 'C';
	int i;
	initListDeque(&testDeque);
		
	printf("\nTesting addLinkAfter Functions\n****************************************\n");
	
	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "testaddLinkBefore");
	for(i = 0; i < 2; ++i)
	{
		addFrontListDeque(&testDeque, val3); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val2); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val1); printListDeque(&testDeque);
	}
	lnk = (DLink*) malloc(sizeof(DLink));
	lnk->value = 'S';
	lnk->next = NULL;
	lnk->prev = NULL;

	addLinkBeforeListDeque(&testDeque, testDeque.head->next, lnk);
	/* perform the test */
	/* check return values and postconditions */
	if(testDeque.size != 7)
		testResults.errMsg = "Size error";
	else if(testDeque.head->next->value != 'S')
		testResults.errMsg = "insert value wrong";

	else
		testResults.success = 1;
	/* show us the results from the test */
	printResults(&testResults);
}

void testremoveLink()
{
				int testNum = 1;
	/*	create a container to manage test results */
	/*	note that this is a stack variable, so despite the fact that 
		we will use & to pass a pointer to it into functions, we 
		DO NOT need to free() it.
	*/
	UnitTestResult testResults;
	ListDeque testDeque;
	TYPE val1 = 'A';
	TYPE val2 = 'B';
	TYPE val3 = 'C';
	int i;
	initListDeque(&testDeque);
		
	printf("\nTesting testremoveLink Functions\n****************************************\n");
	
	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "testremoveLink");
	for(i = 0; i < 2; ++i)
	{
		addFrontListDeque(&testDeque, val3); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val2); printListDeque(&testDeque);
		addFrontListDeque(&testDeque, val1); printListDeque(&testDeque);
	}

	removeListDeque(&testDeque, 'A');
	/* perform the test */
	/* check return values and postconditions */
	if(testDeque.size != 5)
		testResults.errMsg = "Size error";
	else if(testDeque.head->value != 'B')
		testResults.errMsg = "remove value wrong";

	else
		testResults.success = 1;
	/* show us the results from the test */
	printResults(&testResults);
}

/*******************************************************************
		Main Function Definition
********************************************************************/
int unitTestsmain()
{	
	testReverse();

	testaddLinkAfter();
	
	testaddLinkBefore();
	
	testremoveLink();
	
	return 0;
}
