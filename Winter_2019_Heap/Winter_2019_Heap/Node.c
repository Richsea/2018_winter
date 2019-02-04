#include "Node.h"

node* new_node()
{
	node* _this;
	_this = NULL;
}

void setData(node* _this, char* data)
{
	_this->data = data;
}
char* getData(node* _this)
{
	return _this->data;
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