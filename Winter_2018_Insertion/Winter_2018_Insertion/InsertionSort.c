
#ifndef INSERTIONSORT_C_
#define INSERTIONSORT_C_

#include "InsertionSort.h"

int* doInsertionSort(int* data)
{
	int i = 1;
	int j = 0;
	int temp = 0;

	while(data[i] != '\0')
	{
		temp = data[i];
		for (j = 0; j < i; j++)
		{
			if (temp < data[j])
			{
				swap(&data[i], &data[j]);
			}
		}
		i++;
	}
	return data;
}

void swap(int* arr1, int* arr2) {
	int temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

#endif /* INSERTIONSORT_C_ */
