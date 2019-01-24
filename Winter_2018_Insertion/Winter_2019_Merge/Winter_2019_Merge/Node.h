#pragma once

typedef struct _node {
	struct _node *next;
	int data;
}node;

node* getNext() {};
void setNext(node* next);

void setData(int data);
int getData();