#pragma once

#include <stdio.h>

typedef enum _boolean {
	FALSE,
	TRUE
}boolean;

typedef struct _node 
{
	struct _node *next;
	int number;
	char* title;
}node;

#define FALSE 0
#define TRUE 1

node* new_node(void);

void setTitle(node* _this, char* data);
char* getTitle(node* _this);
void setNext(node* _this, node* _next);
node* getNext(node* _this);
void setNumber(node* _this, int num);
int getNumber(node* _this);

boolean node_delete(node* _this);

