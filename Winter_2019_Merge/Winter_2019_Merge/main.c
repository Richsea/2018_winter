#include <stdio.h>
#include "MergeSort.h"

int main()
{
	int* data;
	data = doMergeSort(0, getSize()-1);

	while (*data != '\0')
	{
		printf("%d\n", *data);
		data++;
	}
}