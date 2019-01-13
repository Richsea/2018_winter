#include <stdio.h>
#include "InsertionSort.h"

int main()
{
	int *printData;
	int i = 0;
	printData = doInsertionSort();
	
	while (printData != '/0') {
		printf("%d", *printData);
		printData + 1;
	}

	return 0;
}
