#include "QuickSort.h"
#include <stdlib.h>

node* doXQuickSort(node* _this, int start, int end)
{
	if (start >= end)
	{
		return _this;
	}

	node* head = _this;
	node* prev_current = _this;	// ���� ��ġ�� �����ϱ� ���� node ����. next�� start ��ġ
	node* prev_end = _this;		// �������� �����ϱ� ���� node ����. next�� end ��ġ
	node* pivot = _this;	// pivot�� ��ġ�� �����ϱ� ���� node ����
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
				node* current = getNext(prev_current);	// ���� ��ġ�� ��� ����
				node* nextPivot = getNext(pivot);	// pivot ���� ����� ��ġ

				setNext(prev_current, getNext(prev_current->next));
				setNext(pivot, current);
				setNext(current, nextPivot);
			}

			pivot = pivot->next;	// data ������ �߱⿡ pivot�� �Ѱ��ش�
			pivotNum++;				// pivot�� ��ġ�� ���� ����
		}
		else
		{
			prev_current = prev_current->next;	// current�� ��� ������ �ߵ� ���ߵ� �Ѱ��ش�
		}
		currentLoc++;
	}

	// pivot�� end�� ��ġ�� �ٲٴ� �۾�
	// 
	while (getNext(prev_end) != (_end))
	{
		prev_end = prev_end->next;
	}

	if (prev_end == pivot || _end == pivot) {}
	else
	{
		node* last = getNext(_end);	// �� List�� ������ ����� ������ ����
		node* nextPivot = getNext(pivot);

		setNext(pivot, _end);
		setNext(_end, nextPivot);
		setNext(prev_end, last);
	}
	pivot = pivot->next;

	// �ѹ��� ������ ���� �� divide & conquer ����
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