#include "HeapSort.h"

node* doHeapSort(node* _this)
{
	node* head = _this;
	int size = getSize(_this);
	
	int start = 0;
	while (start == size)
	{
		heapify(head, start, size);
		size--;
	}
	
}

node* heapify(node* _this, int parent, int last)
{
	//parent는 현재 노드
	//last는 노드의 끝의 위치
	if (parent <= last)
	{
		return _this;
	}

	node* head = _this;
	node* _parent = _this->next;

	int leftLoc = 2 * parent;
	int rightLoc = leftLoc + 1;
	boolean changeLeft = FALSE;

	for (int i = 0; i < leftLoc + 1; i++)
	{
		_this = _this->next;
	}
	node* _left = doHeapSort(_this, leftLoc, last);
	_this = _this->next;
	node* _right = doHeapSort(_this, rightLoc, last);

	if (rightLoc > last)
	{
		if (getNum(_left) > getNum(_parent))
		{
			node* _temp = _left;
			_left = _parent;
			setNext(_left, _temp->next);

			setNum(_parent, getNum(_temp));
			setTitle(_parent, getTitle(_temp));
		}
	}

	int max = MAX(getNum(_left), getNum(_right));
	if (getNum(_parent) < max)
	{
		node* _temp;
		if (getNum(_left) == max)
		{
			_temp = _left;
			_left = _parent;
			setNext(_left, getNext(_temp));
			changeLeft = TRUE;
		}
		else
		{
			_temp = _right;
			_right = _parent;
			setNext(_right, _temp->next);
		}

		setNum(_parent, getNum(_temp));
		setTitle(_parent, getTitle(_temp));

		if (changeLeft)
		{
			head = doHeapSort(_this, leftLoc, last);
		}
		else
		{
			head = doHeapSort(_this, rightLoc, last);
		}
	}
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