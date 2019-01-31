#include <stdio.h>
#include "MergeSort.h"

int main()
{
	int* data;
	data = doMergeSort(0, getSize()-1);
	
	int i = 0;
	while (i != getSize())
	{
		printf("%d\n", data[i]);
		i++;
	}
}