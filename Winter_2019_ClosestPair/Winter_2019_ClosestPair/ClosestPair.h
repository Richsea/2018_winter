#pragma once

#include "Node.h"
#include "ShortNode.h"

node* doXSorting(node* _this);	// x축을 기준으로 가장 작은 크기의 점부터 순차적으로 sorting
node* doYSorting(node* _this);
int getSize(node* _this);
shortestPair* getShortestBetweenThree(node* _point1, node* _point2, node* _point3);

shortestPair* doClosestPair(node* _this);
shortestPair* findClosestPair(node* _this);

float getLengthBetweenTwo(node* _point1, node* _point2);