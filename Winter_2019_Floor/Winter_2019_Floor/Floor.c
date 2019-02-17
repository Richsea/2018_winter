#include "Floor.h"

int floorCount = 0;			// 플로어를 진행한 횟수
int binaryFloorCout = 0;	// 이진탐색 플로어를 진행한 횟수

int doLogFloor(int data)
{
	int e = 0;
	int k = 1;

	if (data == 0)
	{
		return -1;
	}

	k *= 2;
	floorCount++;

	while (k <= data)
	{
		e++;
		k *= 2;
		floorCount++;
	}

	return e;
}

int getFloorCount()
{
	return floorCount;
}

int doBinarySearchLogFloor(int data)
{


}

int getBinaryFloorCount(void)
{
	return binaryFloorCout;
}