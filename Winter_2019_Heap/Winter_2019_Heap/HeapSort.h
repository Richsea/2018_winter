#pragma once

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#include "Node.h"

node* doHeapSort(node* _this);
node* heapify(node* _this, int parent, int last);
int getSize(node* _this);