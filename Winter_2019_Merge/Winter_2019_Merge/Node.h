#pragma once

typedef enum _boolean {
	FALSE,
	TRUE
}boolean;

typedef struct _node {
	struct _node *next;
	int data;
}node;

#define FALSE 0
#define TRUE 1

node* new_node(void);

void setData(node* _this, int data);
int getData(node* _this);
void setNext(node* _this, node* _next);
node* getNext(node* _this);

boolean node_delete(node* _this);
