#include "Node.h"
#include <stdlib.h>
#include <limits.h>	// 자료형의 최대값과 최소값이 정의된 헤더파일

#define	NewObject(TYPE)		(TYPE*)malloc(sizeof(TYPE))

node* new_node()
{
	node* _this = NewObject(node);
	_this->next = NULL;
	//_this->next = NULL;		->		initialize 오류가 발생한 이유 : 데이터 할당이 되지 않아서?	NULL값이 초기화되지 않은 이유는?

	return _this;
}		

void setData(node* _this, int data)
{
	_this->data = data;
}

int getData(node* _this)
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