#include <stdio.h>
#include "InsertionSort.h"
#include "FileIO.h"

int main()
{
	int* printData;
	int i = 0;
	printData = doInsertionSort();

	/*
	while (*printData != '\0') {
		int temp = printData;
		printf("%d\n", *printData);

		printData++;
	}*/

	writeFile(printData);

	return 0;
}
