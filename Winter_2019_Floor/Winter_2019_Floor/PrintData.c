#include "PrintData.h"
#include "Floor.h"

#include <stdio.h>

void printResult(void)
{
	int inputData;
	printf("log floor을 돌릴수: ");
	scanf("%d", &inputData);

	int floorResult;
	floorResult = doLogFloor(inputData);

	printf("\n---------------------------\n");
	printf("Floor 결과: %d\n", floorResult);
	printf("loop 횟수: %d\n", getFloorCount());

	int binaryFloorResult;
	binaryFloorResult = doBinarySearchLogFloor(inputData);

	printf("---------------------------\n");
	printf("Binary Search Floor 결과: %d\n", binaryFloorResult);
	printf("loop 횟수: %d\n", getBinaryFloorCount());
	
}