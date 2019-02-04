#include "Node.h"

#define NewObject(TYPE)	(TYPE*)malloc(sizeof(TYPE));

node* new_node()
{
	node* _this = NewObject(node);
	_this->title = NewObject(char);
	_this = NULL;
}

void setTitle(node* _this, char* data)
{
	_this->title = data;
}
char* getTitle(node* _this)
{
	return _this->title;
}
void setNext(node* _this, node* _next)
{
	_this->next = _next;
}
node* getNext(node* _this)
{
	return _this->next;
}
void setNumber(node* _this, int num)
{
	_this->number;
}
int getNumber(node* _this)
{
	return _this->number;
}

boolean node_delete(node* _this)
{
	free(_this);
}