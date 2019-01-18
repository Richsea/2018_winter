#include <stdio.h>
#include "InsertionSort.h"

int main()
{
	int *printData;
	int i = 0;
	printData = doInsertionSort();

	while (*printData != '\0') {
		int temp = printData;
		printf("%d", *printData);

		printData++;
	}

	return 0;
}
