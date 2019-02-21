#include "QuickSort.h"
#include <stdlib.h>

node* doXQuickSort(node* _this, int start, int end)
{
	if (start >= end)
	{
		return _this;
	}

	node* head = _this;
	node* prev_current = _this;	// 현재 위치을 저장하기 위한 node 변수. next가 start 위치
	node* prev_end = _this;		// 마지막을 저장하기 위한 node 변수. next가 end 위치
	node* pivot = _this;	// pivot의 위치를 저장하기 위한 node 변수
	node* _end;
	int pivotNum = start;
	int currentLoc = start;

	for (int i = start; i < end; i++)
	{
		prev_end = prev_end->next;
	}
	_end = prev_end->next;

	node* prev_left = _this;	
	node* prev_right = _this;	
	boolean changeLoc = FALSE;

	while (currentLoc < end)
	{
		if (getDataX(_end) > getDataX(prev_current->next)) {
			if (!changeLoc && (pivot == prev_current))
			{
				pivot = getNext(pivot);
				pivotNum++;

				prev_current = getNext(prev_current);
				currentLoc++;
				continue;
			}

			if (getNext(pivot) == prev_current)
			{
				node* nextCurrent = getNext(prev_current->next);

				setNext(pivot, getNext(prev_current));
				setNext(getNext(pivot), prev_current);
				setNext(prev_current, nextCurrent);
				changeLoc = TRUE;
			}
			else
			{
				node* current = getNext(prev_current);	// 현재 위치의 노드 다음
				node* nextPivot = getNext(pivot);	// pivot 다음 노드의 위치

				setNext(prev_current, getNext(prev_current->next));
				setNext(pivot, current);
				setNext(current, nextPivot);
			}

			pivot = pivot->next;	// data 정렬을 했기에 pivot을 넘겨준다
			pivotNum++;				// pivot의 위치를 위한 변수
		}
		else
		{
			prev_current = prev_current->next;	// current의 경우 정렬을 했든 안했든 넘겨준다
		}
		currentLoc++;
	}

	// pivot과 end의 위치를 바꾸는 작업
	// 
	while (getNext(prev_end) != (_end))
	{
		prev_end = prev_end->next;
	}

	if (prev_end == pivot || _end == pivot) {}
	else
	{
		node* last = getNext(_end);	// 현 List의 마지막 노드의 다음을 저장
		node* nextPivot = getNext(pivot);

		setNext(pivot, _end);
		setNext(_end, nextPivot);
		setNext(prev_end, last);
	}
	pivot = pivot->next;

	// 한바퀴 정렬을 끝낸 후 divide & conquer 실행
	prev_left = doQuickSort(head, start, pivotNum - 1);
	prev_right = doQuickSort(pivot, pivotNum + 1, end);

	return head;
}

int getQuickSize(node* _this)
{
	int size = 0;
	while (_this->next != NULL)
	{
		_this = _this->next;
		size++;
	}

	return size;
}