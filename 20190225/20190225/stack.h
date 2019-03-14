#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Datatype;
typedef struct tag{
	Datatype val;
	struct tag *next;
}Node, *pNode;

typedef struct {
	pNode head;
	int size;
}Stack,*pStack;

void init_stack(pStack);
void pop(pStack);
void push(pStack,Datatype);
Datatype top(pStack);
int empty(pStack);
int size(pStack);
