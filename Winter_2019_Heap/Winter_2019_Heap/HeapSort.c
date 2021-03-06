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
		
		if (start + 1 == size)
		{
			node* nextBegin = getNext(begin->next);
			setNext(head, end->next);
			setNext(head->next, begin);
			setNext(begin, nextBegin);
		}
		else
		{
			node* temp = getNext(end->next);

			setNext(head, end->next);
			setNext(head->next, getNext(begin));

			setNext(end, begin);
			setNext(end->next, temp);
		}

		size--;	
	}

	return head;
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
	boolean change = FALSE;

	for (int i = parent; i < leftLoc; i++)
	{
		_this = _this->next;
	}
	node* _left = heap(_this, leftLoc, last);
	_this = _this->next;
	node* _right = heap(_this, rightLoc, last);

	if (rightLoc > last)
	{
		if (getNum(getNext(_left)) > getNum(getNext(_parent)))
		{
			if (parent == 1)
			{
				node* _nextRight = _right->next;
				node* tempLeft = _left;

				_left = getNext(_left);
				setNext(_parent, _left);
				setNext(_left, tempLeft);
				setNext(tempLeft, _nextRight);
			}
			else
			{
				node* _leftChild = getNext(_left);
				node* _nextParent = getNext(_parent->next);

				setNext(_left, _parent->next);
				setNext(_left->next, _leftChild->next);

				setNext(_parent, _leftChild);
				setNext(_leftChild, _nextParent);
			}
		}

		change = TRUE;
	}

	int max;
	if (getNext(_right) != NULL)
	{
		max = MAX(getNum(getNext(_left)), getNum(getNext(_right)));
	}
	else
	{
		max = getNum(getNext(_left));
	}
	
	if (getNum(getNext(_parent)) < max && !change)
	{
		node* _newChild;
		node* _nextParent;

		if (getNum(getNext(_left)) == max)
		{
			if (parent == 1)
			{
				node* _nextRight = _right->next;
				node* tempLeft = _left;

				_left = getNext(_left);
				setNext(_parent, _left);
				setNext(_left, tempLeft);
				setNext(tempLeft, _nextRight);
			}
			else
			{
				_newChild = getNext(_left);
				_nextParent = getNext(_parent->next);

				setNext(_left, _parent->next);
				setNext(_left->next, _newChild->next);

				setNext(_parent, _newChild);
				setNext(_newChild, _nextParent);
			}

			change = TRUE;
		}
		else
		{
			_newChild = getNext(_right);
			_nextParent = getNext(_parent->next);

			setNext(_right, _parent->next);
			setNext(_right->next, _newChild->next);

			setNext(_parent, _newChild);
			setNext(_newChild, _nextParent);
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

void insert(node* _this, int number, char* title)
{
	node* head = _this;
	node* _newNode = new_node();
	
	while (_this->next != NULL)
	{
		_this = _this->next;
	}

	setNum(_newNode, number);
	setTitle(_newNode, title);
	setNext(_this, _newNode);

	doHeapSort(head);
}

node* min(node* _this)
{
	return _this->next;
}
void extract_min(node* _this)
{
	node* _newNode = getNext(_this->next);
	node_delete(_this->next);
	_this->next = _newNode;
	doHeapSort(_this);
}
boolean increase_key(node* _this, int prevNum, int changeNum)
{
	node* _newNode = getNext(_this->next);

	while (_newNode->next != NULL)
	{
		if (getNum(_newNode->next) == prevNum)
		{
			setNum(_newNode->next, changeNum);
			doHeapSort(_this);
			return TRUE;
		}
		_newNode = _newNode->next;
	}
	return FALSE;
}
boolean delete(node* _this, int number)
{
	node* head = _this;

	while (_this->next != NULL)
	{
		if (getNum(_this->next) == number)
		{
			node* _newNode = getNext(_this->next);
			node_delete(_this->next);
			_this->next = _newNode;
			doHeapSort(head);

			return TRUE;
		}

		_this = _this->next;
	}
	return FALSE;
}