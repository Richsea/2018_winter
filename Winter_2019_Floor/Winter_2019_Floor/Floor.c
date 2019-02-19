#include "Floor.h"

int floorCount = 0;			// 플로어를 진행한 횟수
int binaryFloorCount = 0;	// 이진탐색 플로어를 진행한 횟수

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
	int e = 1;
	int k = 2;
	int last = 1;		// k^2 되기 전의 k
	int current = 2;	// 현재 k의 위치
	int lastE = 1;

	if (data == 0)
	{
		return -1;
	}


	binaryFloorCount++;
	if (data == 1)
	{
		return 0;
	}

	binaryFloorCount++;
	if (data < 4)
	{
		return e;
	}
	
	
	
	while (k <= data)
	{
		lastE = e;
		e *= 2;
		k *= k;
		last = current;
		current = k;
		binaryFloorCount++;
	}

	e = doBinarySearch(lastE, e, last, current, data);

	return e;
}

int getBinaryFloorCount(void)
{
	return binaryFloorCount;
}

int doBinarySearch(int startE, int lastE, int startData, int endData, int data)
{
	if (lastE <= startE+1)
	{
		return startE;
	}

	int mid = (startE + lastE) / 2;

	int midData = startData;
	for (int i = startE; i < mid; i++)
	{
		midData *= 2;
	}

	int result;
	if (data < midData)
	{
		result = doBinarySearch(startE, mid, startData, midData, data);
	}
	else
	{
		result = doBinarySearch(mid, lastE, midData, endData, data);
	}

	binaryFloorCount++;
	return result;

}