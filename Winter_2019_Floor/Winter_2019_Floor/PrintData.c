#include "PrintData.h"
#include "Floor.h"

#include <stdio.h>

void printResult(void)
{
	int inputData;
	printf("log floor�� ������: ");
	scanf("%d", &inputData);

	int floorResult;
	floorResult = doLogFloor(inputData);

	printf("\n---------------------------\n");
	printf("Floor ���: %d\n", floorResult);
	printf("loop Ƚ��: %d\n", getFloorCount());

	int binaryFloorResult;
	binaryFloorResult = doBinarySearchLogFloor(inputData);

	printf("---------------------------\n");
	printf("Binary Search Floor ���: %d\n", binaryFloorResult);
	printf("loop Ƚ��: %d\n", getBinaryFloorCount());
	
}