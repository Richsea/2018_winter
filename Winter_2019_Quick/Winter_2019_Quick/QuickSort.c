#include <stdlib.h>
#include "QuickSort.h"

node* doQuickSort(node* _this, int start, int end)
{
	if (start == end)
	{
		return _this;
	}

	node* head = _this;
	node* prev_current = _this;	// 현재 위치을 저장하기 위한 node 변수. next가 start 위치
	node* prev_end = _this;		// 마지막을 저장하기 위한 node 변수. next가 end 위치
	node* pivot = _this;	// pivot의 위치를 저장하기 위한 node 변수
	int pivotNum = start;
	int currentLoc = start;

	for (int i = start; i < end; i++)
	{
		prev_end = prev_end->next;
	}

	node* prev_left = _this;	// divide & conquer 진행할 때 좌측 부분
	node* prev_right = _this;	// divide & conquer 진행할 때 우측 부분

	while (currentLoc < end)
	{
		if (getData(prev_end->next) > getData(prev_current->next)) {	// end의 data와 start의 data 크기 비교
			if (getNext(pivot) == prev_current)
			{
				node* nextCurrent = getNext(prev_current->next);

				setNext(pivot, getNext(prev_current));
				setNext(getNext(pivot), prev_current);
				setNext(prev_current, nextCurrent);
			}
			else
			{
				node* current = getNext(prev_current);	// 현재 위치의 노드 다음
				node* nextPivot = getNext(pivot->next);	// pivot 다음 노드의 위치

				setNext(prev_current, getNext(prev_current->next));
				setNext(pivot, current);
				setNext(current, nextPivot);
			}
					
			pivot = pivot->next;	// data 정렬을 했기에 pivot을 넘겨준다
			pivotNum++;				// pivot의 위치를 위한 변수
		}

		prev_current = prev_current->next;	// current의 경우 정렬을 했든 안했든 넘겨준다
		currentLoc++;
	}
	
	// pivot과 end의 위치를 바꾸는 작업
	if (prev_end == pivot)
	{
		//제대로 작동하는지 확인하기 위해
		pivotNum++;
	}
	else
	{
		node* last = getNext(prev_end->next);	// 현 List의 마지막 노드의 다음을 저장
		node* nextPivot = getNext(pivot);

		setNext(pivot, getNext(prev_end));
		setNext(getNext(pivot->next), nextPivot);
		setNext(prev_end, last);

		pivotNum++;
	}
	pivot = pivot->next;
	
	

	// 한바퀴 정렬을 끝낸 후 divide & conquer 실행
	prev_left = doQuickSort(head, start, pivotNum - 1);
	prev_right = doQuickSort(pivot, pivotNum + 1, end);

	return head;
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