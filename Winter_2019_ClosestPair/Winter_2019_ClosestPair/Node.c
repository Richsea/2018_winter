#include "Node.h"
#include <stdlib.h>

#define NewObject(TYPE)		(TYPE*)malloc(sizeof(TYPE))

node* new_node()
{
	node* _this = NewObject(node);
	_this->next = NULL;

	return _this;
}

void setDataX(node* _this, float data)
{
	_this->xData = data;
}
float getDataX(node* _this)
{
	return _this->xData;
}
void setDataY(node* _this, float data)
{
	_this->yData = data;
}
float getDataY(node* _this)
{
	return _this->yData;
}
void setNext(node* _this, node* _next)
{
	_this->next = _next;
}
node* getNext(node* _this)
{
	return _this->next;
}

boolean node_delete(node* _this)
{
	free(_this);
}