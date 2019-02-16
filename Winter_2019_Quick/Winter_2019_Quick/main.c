#include "Node.h"
//
#include <stdio.h>

int main()
{
	node* head = readFile();
	head = doQuickSort(head, 1, getSize(head));

	writeFile(head);

	return 0;
}