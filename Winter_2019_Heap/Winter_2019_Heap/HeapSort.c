#include "HeapSort.h"

node* doHeapSort(node* _this)
{
	node* head = _this;
	int size = getSize(_this);
	
	int start = 1;
	while (start != size)
	{
		heap(head, start, size);

		node* end = head;
		node* begin = getNext(head);
		for (int i = 0; i < size - start; i++)
		{
			end = end->next;
		}
		
		node* temp = getNext(end->next);

		setNext(head, end->next);
		setNext(head->next, getNext(begin));

		setNext(end, begin);
		setNext(end->next, temp);
		size--;

		temp = head;
		temp = temp->next;
		while (temp != NULL)
		{
			printf("%d\n", temp->number);
			temp = temp->next;
		}
		printf("-----------------------------------\n");
	}

	head = head->next;
	while (head != NULL)
	{
		printf("%d\n", head->number);
		head = head->next;
	}
	
}

node* heap(node* _this, int parent, int last)
{
	//parent는 현재 노드
	//last는 노드의 끝의 위치
	if (parent*2 > last)
	{
		return _this;
	}

	node* head = _this;
	node* _parent = _this;

	int leftLoc = 2 * parent;
	int rightLoc = leftLoc + 1;
	//
	int checkParent = parent;
	boolean change = FALSE;

	for (int i = parent; i < leftLoc; i++)
	{
		_this = _this->next;
	}
	node* _left = heap(_this, leftLoc, last);
	_this = _this->next;
	node* _right = heap(_this, rightLoc, last);

	/*
	parent가 1, child가 2인 data를 이용
	*/
	if (rightLoc > last)
	{
		if (getNum(getNext(_left)) > getNum(getNext(_parent)))
		{
			node* _temp = _left->next;
			node* _temp2 = getNext(_parent->next);
			setNext(_left, _parent->next);
			setNext(_left->next, _temp->next);

			setNext(_parent, _temp);
			setNext(_parent->next, _temp2);	
		}
		change = TRUE;
	}

	int max = MAX(getNum(getNext(_left)), getNum(getNext(_right)));
	if (getNum(getNext(_parent)) < max && !change)
	{
		node* _temp;
		node* _temp2;
		if (getNum(getNext(_left)) == max)
		{
			_temp = _left->next;
			_temp2 = getNext(_parent->next);

			setNext(_left, _parent->next);
			setNext(_left->next, getNext(_temp));

			setNext(_parent, _temp);
			setNext(_parent->next, _temp2);

				
			change = TRUE;
		}
		else
		{
			_temp = _right->next;
			_temp2 = getNext(_parent->next);

			setNext(_right, _parent->next);
			setNext(_right->next, getNext(_temp));

			setNext(_parent, _temp);
			setNext(_parent->next, _temp2);
		}

		if (change)
		{
			heap(_left, leftLoc, last);
		}
		else
		{
			heap(_right, rightLoc, last);
		}
	}
	return head;
}

int getSize(node* _this)
{
	int size = 0;
	
	while (_this->next != NULL)
	{
		size++;
		_this = _this->next;
	}

	return size;
}