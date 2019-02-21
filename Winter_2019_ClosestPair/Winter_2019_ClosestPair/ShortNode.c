#include "ShortNode.h"

#define NewObject(TYPE)	(TYPE*)malloc(sizeof(TYPE))

shortestPair* new_nodePair()
{
	shortestPair* _this = NewObject(shortestPair);

	return _this;
}

void setShortestPair(shortestPair* _this, node* _point1, node* _point2)
{
	_this->point1 = _point1;
	_this->point2 = _point2;
}
shortestPair* getShortestPair(shortestPair* _this)
{
	return _this;
}

void setLength(shortestPair* _this, float _length)
{
	_this->length = _length;
}
float getLength(shortestPair* _this)
{
	return _this->length;
}