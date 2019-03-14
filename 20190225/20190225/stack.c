#include"stack.h"

void init_stack(pStack t) {
	memset(t, 0, sizeof(Stack));
}

void pop(pStack t) {
	pStack tmp;
	if (!t->size) {
		printf("EMPTY!!!");
		return;
	}
	else {
		tmp = t->head;
		t->head = t->head->next;
		free(tmp);
		t->size--;
	}
}
void push(pStack t, Datatype i) {
	pNode new = (pNode)calloc(1, sizeof(Node));
	new->val = i;
	if (NULL == t->head) {
		t->head = new;
	}
	else {
		new->next = t->head;
		t->head = new;
	}
	t->size++;
}
Datatype top(pStack t) {
	if (t->head) {
		return t->head->val;
	}
	printf("EMPTY!!!\n");
}
int empty(pStack t) {
	return !t->size;
}
int size(pStack t) {
	return t->size;
}