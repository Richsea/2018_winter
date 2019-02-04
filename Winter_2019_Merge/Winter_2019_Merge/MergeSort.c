#include "MergeSort.h"
#include <stdlib.h>
#include <stdio.h>

// Linked List를 이용한 merge sort
node* listMergeSort(node* _this, int start, int end)
{
	if (start == end)
	{
		node* newNode = new_node();
		setNext(newNode, _this->next);
		return newNode;
	}

	int mid = (start + end) / 2;

	node* front = listMergeSort(_this, start, mid);
	for (int i = start; i < mid+1; i++)
	{
		_this = _this->next;
	}
	node* back = listMergeSort(_this, mid+1, end);

	// mergeSort의 conquer 진행
	node* mergedNode = new_node();
	node* head = mergedNode;
	int front_Loc = 0;
	int back_Loc = 0;
	
	while (front_Loc + start <= mid && back_Loc + mid + 1 <= end)
	{
		node* temp = new_node();
		if (getNext(front)->data < getNext(back)->data)
		{
			setData(temp, getData(front->next));
			setNext(mergedNode, temp);
			front = getNext(front);
			front_Loc++;
			mergedNode = mergedNode->next;
		}
		else
		{
			setData(temp, getData(back->next));
			setNext(mergedNode, temp);
			back = getNext(back);
			back_Loc++;
			mergedNode = mergedNode->next;
		}
	}

	if (front_Loc + start <= mid)
	{
		while (front_Loc + start <= mid)
		{
			node* temp = new_node();
			setData(temp, getData(front->next));
			setNext(mergedNode, temp);
			front = getNext(front);
			front_Loc++;
			mergedNode = mergedNode->next;
		}
	}

	if (back_Loc + mid + 1 <= end)
	{
		while (back_Loc + mid + 1 <= end)
		{
			node* temp = new_node();
			setData(temp, getData(back->next));
			setNext(mergedNode, temp);
			back = getNext(back);
			back_Loc++;
			mergedNode = mergedNode->next;
		}
	}

	return head;
}

// 배열 데이터를 이용한 merge sort
int* doMergeSort(int* data, int start, int end)
{
	if (end == start) {
		return &data[start];
	}
	int mid = (start+end) / 2;

	int *front = (int*)malloc(sizeof(int)*(mid - start + 1));
	int *back = (int*)malloc(sizeof(int)*(end-mid));

	memset(front, NULL, sizeof(int)*(mid - start + 1));
	memset(back, NULL, sizeof(int)*(end - mid));

	front = doMergeSort(data, start, mid);
	back = doMergeSort(data, mid+1, end);

	int mergeSize = end - start + 1;
	
	// mergeArray를 위한 선언 및 초기화
	int* mergeArray = (int*)malloc(sizeof(int)*mergeSize);
	memset(mergeArray, NULL, sizeof(int)*mergeSize);
	int loc1 = 0;
	int loc2 = 0;
	int location = 0;
	while (loc1+start <= mid && loc2+mid+1 <= end) 
	{
		int temp;
		if (front[loc1] > back[loc2])
		{
			temp = back[loc2];
			loc2++;
		}
		else
		{
				temp = front[loc1];
			loc1++;
		}
		mergeArray[location] = temp;
		location++;
	}

	if (loc1+start <= mid) 
	{
		while (loc1+start <= mid) 
		{
			mergeArray[location] = front[loc1];
			loc1++;
			location++;
		}
	}

	if (loc2+mid+1 <= end)
	{
		while (loc2+mid+1 <= end)
		{
			mergeArray[location] = back[loc2];
			loc2++;
			location++;
		}
	}

	return mergeArray;
}

/*
int getSize() 
{
	return size;
}
*/

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