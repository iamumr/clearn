#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	struct student *next;
}stu,*pstu;
void list_tail_insert(pstu *phead, pstu *ptail, int i) {
	pstu new;
	new = (pstu)malloc(sizeof(stu));
	memset(new, 0, sizeof(stu));
	new->num = i;
	if (NULL == *ptail) {
		*phead = new;
		*ptail = new;
	}
	else {
		(*ptail)->next = new;
		*ptail = new;
	}
}
void list_head_insert(pstu *phead, pstu *ptail, int i) {
	pstu new;
	new = (pstu)malloc(sizeof(stu));
	memset(new, 0, sizeof(stu));
	new->num = i;
	if (NULL == *phead) {
		*phead = new;
		*ptail = new;
	}
	else {
		new->next = *phead;
		*phead = new;
	}
}
void list_sort_insert(pstu *phead, pstu *ptail, int i) {
	pstu new;
	new = (pstu)malloc(sizeof(stu));
	memset(new, 0, sizeof(stu));
	new->num = i;
	pstu begin;
	pstu end;
	begin = *phead;
	end = *phead;
	if (NULL == *phead) {
		*phead = new;
		*ptail = new;
	}
	else if(i<begin->num){
		new->next = *phead;
		*phead = new;
	}
	else {
		while (begin != NULL) {
			if (i > begin->num) {
				new->next=begin;
				end->next = new;
			}
			end = begin;
			begin = begin->next;
		}
	}
	if (NULL == begin) {
		(*ptail)->next = new;
		*ptail = new;
	}
}

int main() {
	pstu p;
	int i;
	pstu head = NULL, tail = NULL;
	while (scanf("%d", &i) != EOF) {
		list_head_insert(&head, &tail, i);
		list_tail_insert(&head, &tail, i);
		list_sort_insert(&head, &tail, i);

	}
}

