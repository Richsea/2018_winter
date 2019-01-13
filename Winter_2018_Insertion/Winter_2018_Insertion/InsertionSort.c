
#ifndef INSERTIONSORT_C_
#define INSERTIONSORT_C_

#include "InsertionSort.h"

int temp = 10;
int data[] =
{ 1381,20144,2937,8401 };/* , 31904, 22750, 27539, 6615, 1492, 8110,
	12833,11891,25449,14327,19563,21346,16756,16012,16590,7966,
	8155,10696,2560,18444,10171,22890,14236,21239,28678,22691,30682,
	1469,30065,1646,28317,29256,18829,6176,32180,11712,15667,10816,25177,
	2047,2598,21400,19454,22342,16372,28300 };
*/

int* doInsertionSort()
{
	int i = 1;
	int j = 0;
	int checkSorting = 0;
	int temp = 0;
	int dataLength = sizeof(data)/4;	//sizeof("DATA")는 data의 크기를 byte단위로 나타내기 때문에 block단위로 표시하기 위해 /4를 해준다

	while(data[i] != '/0')
	{
		temp = data[i];
		for (j = 0; j <= i; j++)
		{
			if (temp < data[j])
			{
				swap(&data[i], &data[j]);
			}
		}
		i++;
	}
	return *data;
}

void swap(int* arr1, int* arr2) {
	int temp;
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

#endif /* INSERTIONSORT_C_ */
