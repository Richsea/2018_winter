#pragma once

#include "Node.h"

typedef struct _shortNode {
	node* point1;
	node* point2;
	float length;
}shortestPair;

shortestPair* new_nodePair(void);
void setShortestPair(shortestPair* _this, node* _point1, node* _point2);
shortestPair* getShortestPair(shortestPair* _this);
void setLength(shortestPair* _this, float _length);
float getLength(shortestPair* _this);