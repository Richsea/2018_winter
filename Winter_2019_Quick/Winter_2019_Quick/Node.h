#pragma once

typedef enum boolean {
	FALSE,
	TRUE
}boolean;

typedef struct _node {
	struct _node *next;
	int data;
}node;

#define	FALSE 0;
#define	TRUE 1;

node*  new_node(void);

void setNext(node* _this, node* _next);
void setData(node* _this, int data);
node* getNext(node* _this);
int getData(node* _this);

boolean node_delete(node* _this);