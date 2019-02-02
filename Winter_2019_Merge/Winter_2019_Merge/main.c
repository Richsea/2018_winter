#include <stdio.h>
#include "MergeSort.h"
#include "FileIO.h"

int main()
{
	int* data;

	readFile();

	data = doMergeSort(0, getSize()-1);
	
	int i = 0;
	while (i != getSize())
	{
		printf("%d\n", data[i]);
		i++;
	}
}