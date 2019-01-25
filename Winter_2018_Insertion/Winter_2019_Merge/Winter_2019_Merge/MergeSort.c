#include "MergeSort.h"
#include <stdlib.h>

int data[] =
{ 1381,20144,2937,8401 };/*, 31904, 22750, 27539, 6615, 1492, 8110,
	12833,11891,25449,14327,19563,21346,16756,16012,16590,7966,
	8155,10696,2560,18444,10171,22890,14236,21239,28678,22691,30682,
	1469,30065,1646,28317,29256,18829,6176,32180,11712,15667,10816,25177,
	2047,2598,21400,19454,22342,16372,28300 };*/
int size = sizeof(data) / sizeof(int);

int* doMergeSort(int start, int end)
{
	if (end == start) {
		return &data[start];
	}
	int mid = (start+end) / 2;

	int *front = doMergeSort(start, mid);
	int *back = doMergeSort(mid+1, end);
	int mergeSize = (sizeof(front) + sizeof(back)) / sizeof(int);
	
	// mergeArray를 위한 선언 및 초기화
	int *mergeArray = (int*)malloc(sizeof(int)*mergeSize);
	memset(mergeArray, NULL, sizeof(int)*mergeSize);
	int location = 0;
	
	//문제점 : front가 부분만 가져오는 것이 아니라 data를 통채로 가져와버린다
	while (*front != '\0' || *back != '\0') 
	{
		int temp;
		if (*front > *back) 
		{
			temp = *back;
			back++;
		}
		else
		{
			temp = *front;
			front++;
		}
		mergeArray[location] = temp;
		location++;
	}
	
	if (*front != '\0') 
	{
		while (*front != '\0') 
		{
			mergeArray[location] = *front;
			location++;
			front++;
		}
	}

	if (*back != '\0')
	{
		while (*back != '\0')
		{
			mergeArray[location] = *back;
			location++;
			front++;
		}
	}
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