#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

enum Mode {
	TEST_RECURSIVE_FIBONACCI = 0,
	TEST_ITERATIVE_FIBONACCI,
	TEST_SUMMATION,
	TEST_ALL
};

/* global variables which we will use to control what gets tested, and how much */
enum Mode programMode = TEST_RECURSIVE_FIBONACCI;
int globalMaxFibonacciNumToCompute = 10;

/* forward declarations */
int fibonacciRecursive(int n);
int fibonacciIterative(int n);

void testRecursiveFibonacci(char* filename, int maxFibonacciNumToCompute);
void testIterativeFibonacci(char* filename, int maxFibonacciNumToCompute);
void testSummation(char* filename);

/* This function will process the command line arguments and bind the global variables
 * appropriately.  If something is amiss, it will print the usage of the program
 */
void parseArgs(int argc, char** argv)
{
	int i;
	
	if(argc < 2)
		return;
	for(i = 1; i < argc; ++i)
	{
		if(strcmp(argv[i],"-r") == 0)
			programMode = TEST_RECURSIVE_FIBONACCI;
		else if(strcmp(argv[i], "-i") == 0)
			programMode = TEST_ITERATIVE_FIBONACCI;
	
		else if(strcmp(argv[i], "-s") == 0)
			programMode = TEST_SUMMATION;
			
		else if(strcmp(argv[i], "-a") == 0)
			programMode = TEST_ALL;
			
		else if(strcmp(argv[i], "-n") == 0 && argc > i)
			globalMaxFibonacciNumToCompute = atoi(argv[++i]);
		else
		{
			printf("\tUsage: ./prog [-r] [-i] [-n INTEGER] [-s] [-a]\n");
			printf("\t-r => set the program to test recursive fibonacci\n");
			printf("\t-i => set the program to test iterative fibonacci\n");
			
			printf("\t-n => set the number of fibonacci numbers to compute, i.e. -n 40\n");
			printf("\t-s => set the program to test summation and file reading\n");
			printf("\t-a => set the program to test everything\n");
		}
	}
}

int main (int argc, char** argv) 
{
	clock_t before, after;
	
	parseArgs(argc, argv);

	/* test recursive fibonacci */
	if(programMode == TEST_RECURSIVE_FIBONACCI || programMode == TEST_ALL)
	{
		/* this call will get the number of clock ticks since the program launched */
		before = clock();
		testRecursiveFibonacci("recursive.txt", globalMaxFibonacciNumToCompute);
		after = clock();
		/* the difference of after and before gives us the time of the stuff in between */ 
		printf("recursive version done in %f seconds\n", (float)(after-before)/(float)CLOCKS_PER_SEC);
	}
	
	/* test the iterative version */
	if(programMode == TEST_ITERATIVE_FIBONACCI || programMode == TEST_ALL)
	{
		before = clock();
		testIterativeFibonacci("iterative.txt", globalMaxFibonacciNumToCompute);
		after = clock();
		printf("iterative version done in %f seconds\n", (float)(after-before)/(float)CLOCKS_PER_SEC);
	}
	
	/* test file reading and summation */
	if(programMode == TEST_SUMMATION || programMode == TEST_ALL)
		testSummation("numbers.txt");
		
	return 0;
}

/* This function computes fibonacci numbers
 * param	n		index of the number to be computed
 * pre		n>0
 * ret		the nth fibonacci number
 */
int fibonacciRecursive(int n)
{
	/* FIXME you will write this function */
	if (n > 2)
	{
		return fibonacciRecursive( n -1 ) + fibonacciRecursive( n -2 );
	}
	else
	{
		return 1;
	}
}

/* This function computes fibonacci numbers
 * param	n		index of the number to be computed
 * pre		n>0
 * ret		the nth fibonacci number
 */
int fibonacciIterative(int n)
{
	int result;
	int i;
	/* this will allocate an array of size n which you can fill in (position i - 1 should store the ith fibonacci number) */
	int* fibArray = (int*) malloc(n*sizeof(int));
	if(!fibArray)	
	{
		fprintf(stderr, "*****malloc failed in iterative");
		return -1;
	}

	/* FIXME you will finish this function */
	if (n > 2)
	{
		fibArray[0] = 1;
		fibArray[1] = 1;
		for ( i = 2; i < n ; i ++)
		{
			fibArray[i] = fibArray[i-1] + fibArray[i-2];
		}
		result = fibArray[n-1];
	}
	else if( n == 2 || n == 1 )
	{
		result = 1;
	}
	
	/* clean up the memory we allocated */
	free(fibArray);
	return result;
}

/* This function should call the fibonacci function a number of times, and write the
 * results to the file.
 * param	filename						name of the file to be opened
 * param	maxFibonacciNumToCompute		index of the max number to be computed
 * pre		maxFibonacciNumToCompute>0
 * post		a file exists, with fibonacci numbers 1-Max written in it.
 */
void testRecursiveFibonacci(char* filename, int maxFibonacciNumToCompute)
{
	/* FIXME you will write this function */
	int result;
	FILE * pFile;
	int n;

	pFile = fopen (filename,"w");
	if(NULL == pFile)
	{
		return;
	}
	for (n = 1 ; n < maxFibonacciNumToCompute ; n++)
	{
		result = fibonacciRecursive(n);
		fprintf (pFile, "%d\n", result);
	}
	fclose (pFile);
}

/* This function should call the fibonacci function a number of times, and write the
 * results to the file.
 * param	filename						name of the file to be opened
 * param	maxFibonacciNumToCompute		index of the max number to be computed
 * pre		maxFibonacciNumToCompute>0
 * post		a file exists, with fibonacci numbers 1-Max written in it.
 */
void testIterativeFibonacci(char* filename, int maxFibonacciNumToCompute)
{
	/* FIXME you will write this function */
	int result;
	FILE * pFile;
	int n;

	pFile = fopen (filename,"w");
	if(NULL == pFile)
	{
		return;
	}
	for (n = 1 ; n < maxFibonacciNumToCompute ; n++)
	{
		result = fibonacciIterative(n);
		fprintf (pFile, "%d\n", result);
	}
	fclose (pFile);
}

/* This function should open a file, and read newline separated numbers from it.
 * As it does this, it should compute their running sum, then print it.
 * param	filename						name of the file to be opened
 * pre		a file by the nme of filename is on the disk, containing newline separted #s
 */
void testSummation(char* filename)
{
	/* FIXME you will write this function */
	int result = 0;
	int sum = 0;
	FILE * pFile;

	pFile = fopen (filename,"r");
	if(NULL == pFile)
	{
		return;
	}
	while (!feof(pFile))
	{
		fscanf (pFile, "%d\n", &result);
		printf("%d\n" , result);
		sum += result; 
	}
	printf("%d\n" , sum);
	fclose (pFile);
}