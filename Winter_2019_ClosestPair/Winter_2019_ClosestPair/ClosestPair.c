#include "ClosestPair.h"
#include "math.h"
#include "QuickSort.h"

#define MIN(X, Y)	((X) < (Y) ? (X) : (Y))

node* doXSorting(node* _this)
{
	return doXQuickSort(_this, 1, getQuickSize(_this));
}

node* doYSorting(node* _this)
{

}

int getSize(node* _this)
{
	int size = 0;
	while (_this->next != NULL)
	{
		_this = _this->next;
		size++;
	}

	return size;
}

shortestPair* getShortestBetweenThree(node* _point1, node* _point2, node* _point3)
{
	shortestPair* leastPair = new_nodePair();
	float point1To2 = getLengthBetweenTwo(_point1, _point2);
	float point2To3 = getLengthBetweenTwo(_point2, _point3);
	float point3To1 = getLengthBetweenTwo(_point3, _point1);

	float leastSize = MIN(point1To2, point2To3);
	leastSize = MIN(point3To1, leastSize);

	if (leastSize == point1To2)
	{
		setShortestPair(leastPair, _point1, _point2);
		setLength(leastPair, point1To2);

		return leastPair;
	}

	if (leastSize == point2To3)
	{
		setShortestPair(leastPair, _point2, _point3);
		setLength(leastPair, point2To3);

		return leastPair;
	}

	setShortestPair(leastPair, _point3, _point1);
	setLength(leastPair, point3To1);

	return leastPair;
}

float getLengthBetweenTwo(node* _point1, node* _point2)
{
	float x1 = getDataX(_point1);
	float y1 = getDataY(_point2);

	float x2 = getDataX(_point2);
	float y2 = getDataY(_point2);

	return sqrt((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

shortestPair* doClosestPair(node* _this)
{
	node* _head = doXSorting(_this);
	findClosestPair(_head);
	// 추가로 작성 필요
}
shortestPair* findClosestPair(node* _this)
{
	node* _head = _this;
	node* _start = getNext(_head);	// start는 현재 위치를 나타냄
	node* _end = _head;

	node* _newLeft = new_node();	// 기준점의 x크기보다 작은 데이터
	node* _newRight = new_node();	// 기준점의 x크기보다 큰 데이터

	shortestPair* _leftPair = new_node();
	shortestPair* _rightPair = new_node();

	float mid;
	int size = 0;

	//start 지점과 end 지점의 시작과 끝 점 찾기
	while (_end->next != NULL)
	{
		_end = _end->next;
		size++;
	}

	if (size <= 3)
	{
		if (size == 3)
		{
			_leftPair = getShortestBetweenThree(_start, _start->next, _end);
		}
		else
		{
			float length = getLengthBetweenTwo(_start, _end);
			setShortestPair(_leftPair, _start, _end);
			setLength(_leftPair, length);
		}

		return _leftPair;
	}

	// 점이 2개 이상일 경우 -> start와 end의 두 점의 크기가
	mid = size - (size / 2);

	//_newLeft부분과 _newRight부분으로 dvide 하기위한 부분
	node* _temp = _newLeft;
	int divideSize = 0;

	while (divideSize != mid)
	{
		setNext(_temp, _start);
		_start = _start->next;
		divideSize++;
	}

	node* _temp = _newRight;
	while (divideSize != size)
	{
		setNext(_temp, _start);
		_start = _start->next;
		divideSize++;
	}

	_leftPair = findClosestPair(_newLeft);
	_rightPair = findClosestPair(_newRight);


	shortestPair* leastPair;
	if (getLength(_leftPair) < getLength(_rightPair))
	{
		leastPair = _leftPair;
	}
	else
	{
		leastPair = _rightPair;
	}

	// 세로로 최소범위 확인하는 작업 필요
	node* _newNode = new_node();
	node* _temp = _newNode;
	
	// 중앙 잡기
	

	return leastPair;
}