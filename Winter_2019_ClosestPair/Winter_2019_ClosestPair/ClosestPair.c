#include "ClosestPair.h"
#include "math.h"

#define MIN(X, Y)	((X) < (Y) ? (X) : (Y))

node* doXSorting(node* _this)
{

}

node* doYSorting(node* _this)
{

}

int getSize(node* _this)
{

}

float getLengthBetweenTwo(node* _point1, node* _point2)
{
	float x1 = getDataX(_point1);
	float y1 = getDataY(_point2);

	float x2 = getDataX(_point2);
	float y2 = getDataY(_point2);

	return sqrt((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

float getShortestBetweenThree(node* _point1, node* _point2, node* _point3)
{
	float point1To2 = getLengthBetweenTwo(_point1, _point2);
	float point2To3 = getLengthBetweenTwo(_point2, _point3);
	float point3To1 = getLengthBetweenTwo(_point3, _point1);

	float leastSize = MIN(point1To2, point2To3);
	leastSize = MIN(point3To1, leastSize);

	if (leastSize == point1To2)
	{
		return point1To2;
	}

	if (leastSize == point2To3)
	{
		return point2To3;
	}

	return point3To1;
}