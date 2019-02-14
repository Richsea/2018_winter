#include "Node.h"

#define NewObject(TYPE)	(TYPE*)malloc(sizeof(TYPE));

node* new_node()
{
	node* _this = NewObject(node);
	//_this->title = NewObject(char);	->	중단점 오류가 생기는데 이유는 파악 못함
	_this->next = NULL;
	return _this;
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
void setNum(node* _this, int num)
{
	_this->number = num;
}
int getNum(node* _this)
{
	return _this->number;
}

boolean node_delete(node* _this)
{
	free(_this);
}