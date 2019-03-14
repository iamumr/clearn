#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef int Datatype;
typedef struct node {
	Datatype val;
	struct node *pleft;
	struct node *pright;
}Node,*pNode;

typedef struct queue {
	pNode treepos;
	struct queue *pnext;
}Queue,*pQueue;

pNode buildTree(char*);
pNode buildTreePlus(char *);
void preOrder(pNode);
void midOrder(pNode);
void latOrder(pNode);
#define N 10