#include "QuickSort.h"

node* doQuickSort(node* _this, int start, int end)
{
	if (start == end)
	{
		return _this;
	}

	node* head = _this;
	node* prev_start = _this;	// 시작점을 저장하기 위한 node 변수
	node* prev_end = _this;		// 마지막을 저장하기 위한 node 변수
	node* prev_pivot = _this;	// pivot의 위치를 저장하기 위한 node 변수


	for (int i = start; i < end; i++)
	{
		prev_end = prev_end->next;
	}

	node* newNode = new_node();

	int pivot = start;

	node* prev_left;	// divide & conquer 진행할 때 좌측 부분
	node* prev_right;	// divide & conquer 진행할 때 우측 부분

	while (start < end)
	{
		if (getData(prev_end) < getData(prev_start)) {	// end의 data와 start의 data 크기 비교
			
		}
	}

	
}