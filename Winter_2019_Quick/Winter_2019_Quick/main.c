#include "Node.h"

int main()
{
	node* head = readFile();
	doQuickSort(head, 1, getSize(head));

	return 0;
}