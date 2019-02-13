#pragma once

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#include "Node.h"

node* doHeapSort(node* _this);
node* heap(node* _this, int parent, int last);
int getSize(node* _this);

node* insert(node* _this);
node* map(node* _this);
