#include "MergeSort.h"
#include <stdlib.h>
#include <stdio.h>

int data[] =
{ 1381,20144,2937,8401, 31904, 22750, 27539, 6615, 1492, 8110,
	12833,11891,25449,14327,19563,21346,16756,16012,16590,7966,
	8155,10696,2560,18444,10171,22890,14236,21239,28678,22691,30682,
	1469,30065,1646,28317,29256,18829,6176,32180,11712,15667,10816,25177,
	2047,2598,21400,19454,22342,16372,28300 };
int size = sizeof(data) / sizeof(int);

int* doMergeSort(int start, int end)
{
	if (end == start) {
		return &data[start];
	}
	int mid = (start+end) / 2;

	int *front = (int*)malloc(sizeof(int)*(mid - start + 1));
	int *back = (int*)malloc(sizeof(int)*(end-mid));

	memset(front, NULL, sizeof(int)*(mid - start + 1));
	memset(back, NULL, sizeof(int)*(end - mid));

	front = doMergeSort(start, mid);
	back = doMergeSort(mid+1, end);
	
	int mergeSize = (sizeof(front) + sizeof(back)) / sizeof(int);
	
	// mergeArray를 위한 선언 및 초기화
	int* mergeArray = (int*)malloc(sizeof(int)*mergeSize + 1);
	memset(mergeArray, NULL, sizeof(int)*mergeSize);
	int loc1 = 0;
	int loc2 = 0;
	int location = 0;
	while (loc1+start <= mid && loc2+mid+1 <= end) 
	{
		int temp;
		if (front[loc1] > back[loc2])
		{
			temp = back[loc2];
			loc2++;
		}
		else
		{
			temp = front[loc1];
			loc1++;
		}
		mergeArray[location] = temp;
		location++;
	}

	if (loc1+start <= mid) 
	{
		while (loc1+start <= mid) 
		{
			mergeArray[location] = front[loc1];
			loc1++;
			location++;
		}
	}

	if (loc2+mid+1 <= end)
	{
		while (loc2+mid+1 <= end)
		{
			mergeArray[location] = back[loc2];
			loc2++;
			location++;
		}
	}

	int i = 0;
	while (i < location)
	{
		printf("%d\n", mergeArray[i]);
		i++;
	}

	printf("---------------\n");
	free(front);
	free(back);
	
	return mergeArray;
}

void swap(int* arr1, int*arr2) 
{
	int temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

int getSize() 
{
	return size;
}