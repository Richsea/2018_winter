#include "Node.h"

int main()
{
	node* _node;
	_node = readFile();
	_node = doHeapSort(_node);
	printScreen(_node);
}