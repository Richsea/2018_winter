#pragma once

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#include "Node.h"

node* doHeapSort(node* _this);
node* heap(node* _this, int parent, int last);
int getSize(node* _this);

void insert(node* _this, int number, char* title);
node* min(node* _this);
void extract_min(node* _this);
boolean increase_key(node* _this, int prevNum, int changeNum);
boolean delete(node* _this, int number);