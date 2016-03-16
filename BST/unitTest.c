/* unitTests.c : dynamic array unit tests */
#include <stdio.h>
#include "type.h"
#include "BST.h"
#include "c_unit.h"

int testNum = 1;

void initTestResult(UnitTestResult* result, int testNumber, char* unitTestName)
{
	result->success = 0;
	result->testNum = testNumber;
	result->testName = unitTestName;
	result->errMsg = "Test Not Written";
}

void printResults(UnitTestResult* testResults)
{
	if(testResults->success)
		printf("[ Passed ]");
	else
		printf("[*FAILED*]");

	printf("\tTest %i\t\t%s\n", testResults->testNum, testResults->testName);

	if(testResults->success == 0)
		printf("\t--> ERROR:\t%s\n", testResults->errMsg);
}

void testHeight(UnitTestResult* result)
{
	/* declare (and maybe initialize) variables */
	BST* t = newBST();

	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	/* perform the test */
	addBST(t, thirdTask);
	addBST(t, secondTask);
	addBST(t, firstTask);
	addBST(t, fourthTask);
	/* check return values and postconditions */
	if(t->size != 4)
		result->errMsg = "size is wrong";
	else if(heightBST(t)!= 2)
		result->errMsg = "height is wrong";
	else
		result->success = 1;
}

void testAdd(UnitTestResult* result)
{

	BST* t = newBST();
	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	addBST(t, thirdTask);
	addBST(t, secondTask);
	addBST(t, firstTask);
	addBST(t, fourthTask);

	if(t->size != 4)
		result->errMsg = "size is wrong";
	else if(t->root->right->val.name != "foo" )
		result->errMsg = "add wrong";
	else if(t->root->left->val.name != "blarg" )
		result->errMsg = "add wrong";
	else if(t->root->left->left != NULL)
		result->errMsg = "add wrong";
	else
		result->success = 1;
}

void testRemove(UnitTestResult* result)
{

	BST* t = newBST();
	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	addBST(t, thirdTask);
	addBST(t, secondTask);
	addBST(t, firstTask);
	addBST(t, fourthTask);
	removeBST(t, thirdTask); 
	removeBST(t, secondTask);

	if(t->size != 2)
		result->errMsg = "size is wrong";
	else if(t->root->left->val.name != "blarg")
		result->errMsg = "remove wrong";
	else if(t->root->right != NULL)
		result->errMsg = "remove wrong";
	else
		result->success = 1;
}

void testContains(UnitTestResult* result)
{
	BST* t = newBST();
	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	if(t->size != 4)
		result->errMsg = "size is wrong";
	else if(!containsBST(t, firstTask) )
		result->errMsg = "contains test firstTask wrong";
	else if(!containsBST(t, secondTask) )
		result->errMsg = "contains test secondTask wrong";
	else if(!containsBST(t, thirdTask) )
		result->errMsg = "contains test thirdTask wrong";
	else if(!containsBST(t, fourthTask) )
		result->errMsg = "contains test fourthTask wrong";
	else
		result->success = 1;
}

void testInit(UnitTestResult* result)
{
	BST* t = newBST();

	if(t->size != 0)
		result->errMsg = "size is wrong";
	else if(t->root != NULL)
		result->errMsg = "init BST wrong";
	else
		result->success = 1;
}

void testDel(UnitTestResult* result)
{
	BST* t = newBST();

	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	deleteBST(t);

	if(t->size == 0)
		result->errMsg = "delete BST wrong";
	else
		result->success = 1;
}

void testFree(UnitTestResult* result)
{
	BST* t = newBST();

	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	freeBST(t);

	if(t->size != 0)
		result->errMsg = "size is wrong";
	else if(t->root != NULL)
		result->errMsg = "free BST wrong";
	else
		result->success = 1;
}

void testSome(UnitTestResult* result) 
{
	/* declare (and maybe initialize) variables */
	BST* t = newBST();
	int passed = 0;

	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;

	secondTask.name = "foo";
	secondTask.priority = 34;

	thirdTask.name = "bar";
	thirdTask.priority = 23;

	fourthTask.name = "scraz";
	fourthTask.priority = 37;

	/* perform the test */
	addBST(t, thirdTask);
	addBST(t, secondTask);
	addBST(t, firstTask);
	addBST(t, fourthTask);

	if(t->size != 4)
		result->errMsg = "size is wrong";
	else if(heightBST(t)!= 2)
		result->errMsg = "height is wrong";
	else
	{
		removeBST(t, thirdTask); 
		removeBST(t, secondTask);
		removeBST(t, fourthTask);
		removeBST(t, firstTask); 

		if(t->size != 0)
			result->errMsg = "size is wrong";
		else if(heightBST(t)!= -1)
			result->errMsg = "height is wrong";
		else if(t->root != NULL)
			result->errMsg = "remove wrong";
		else
			result->success = 1;
	}
}

/*******************************************************************
		Test Bundling Functions
*******************************************************************/
void heightTests()
{
	UnitTestResult testResults;
	
	printf("\nTesting heightTests Functions\n****************************************\n");
	
	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "testheight");
	/* perform the test */
	testHeight(&testResults);
	/* show us the results from the test */
	printResults(&testResults);
}

void addTests()
{
	UnitTestResult testResults;

	printf("\nTesting testadd Functions\n****************************************\n");

	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "testadd");
	/* perform the test */
	testAdd(&testResults);
	/* show us the results from the test */
	printResults(&testResults);
}

void removeTests()
{
	UnitTestResult testResults;

	printf("\nTesting removeTests Functions\n****************************************\n");

	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "removeTests");
	/* perform the test */
	testRemove(&testResults);
	/* show us the results from the test */
	printResults(&testResults);
}

void containsTests()
{
	UnitTestResult testResults;

	printf("\nTesting containsTests Functions\n****************************************\n");

	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "containsTests");
	/* perform the test */
	testRemove(&testResults);
	/* show us the results from the test */
	printResults(&testResults);
}

void basicTests()
{
	UnitTestResult testResults;

	printf("\nTesting basicTests Functions\n****************************************\n");


	initTestResult(&testResults, testNum++, "test init");
	testInit(&testResults);
	printResults(&testResults);

	initTestResult(&testResults, testNum++, "test delete");
	testDel(&testResults);
	printResults(&testResults);

	initTestResult(&testResults, testNum++, "test free");
	testFree(&testResults);
	printResults(&testResults);

	/* set up the unit test results container for the next test */
	initTestResult(&testResults, testNum++, "add&remove&height");
	/* perform the test */
	testSome(&testResults);
	/* show us the results from the test */
	printResults(&testResults);
}


/*******************************************************************
		Main Function Definition
********************************************************************/
int Unit_main()
{	
	heightTests();
	addTests();
	removeTests();
	containsTests();
	basicTests();
	
	return 0;
}