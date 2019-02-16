#include "Node.h"
#include <stdlib.h>

#define NewObject(TYPE)		(TYPE*)malloc(sizeof(TYPE))

node*  new_node(void)
{
	node* _this = NewObject(node);
	_this->next = NULL;

	return _this;
}

void setNext(node* _this, node* _next)
{
	_this->next = _next;
}
void setData(node* _this, int data)
{
	_this->data = data;
}
node* getNext(node* _this)
{
	return _this->next;
}
int getData(node* _this)
{
	return _this->data;
}

boolean node_delete(node* _this)
{
	free(_this);
}