#pragma once

typedef enum _boolean {
	FALSE,
	TRUE
}boolean;

typedef struct _node {
	struct _node *next;
	float xData;
	float yData;
}node;

#define FALSE 0
#define TRUE 1

node* new_node(void);

void setDataX(node* _this, float data);
float getDataX(node* _this);
void setDataY(node* _this, float data);
float getDataY(node* _this);
void setNext(node* _this, node* _next);
node* getNext(node* _this);

boolean node_delete(node* _this);