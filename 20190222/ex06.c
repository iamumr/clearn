#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	struct student *next;
}stu, *pstu;
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
void mid(pstu *phead) { //中间结点
	pstu begin;
	begin = *phead;
	int i = 0;
	while (begin != NULL) {
		i++;
		begin = begin->next;
	}
	begin = *phead;
	for (int j = 0; j < (i-1) / 2; j++) {
		begin = begin->next;
	}
	printf("%d", begin->num);
}
void last_four(pstu *phead) { //中间结点
	pstu begin;
	begin = *phead;
	int i = 0;
	while (begin != NULL) {
		i++;
		begin = begin->next;
	}
	begin = *phead;
	for (int j = 0; j < i - 4; j++) {
		begin = begin->next;
	}
	printf("%d", begin->num);
}
void list_reverse(pstu *phead) {
	pstu p1, p2,p3;
	int n = 0;
	//p1 = *phead;
	//while (p1) {
	//	n++;
	//	p1 = p1->next;
	//}
	p1 = *phead;
	p2 = p3 = NULL;
	/*for (int i = 1; i < n-1; i++) {
		p1 = p1->next;
	}
	p2 = p1->next;
	p1->next = NULL;
	p2->next = *phead;
	*phead = p2;*/
	while (p1) {
		p2 = p1->next;
		p1->next = p3;
		p3 = p1;
		p1 = p2;
	}
	*phead = p3;
}
int is_circle(pstu *phead) {
	pstu p1, p2;
	p1 = p2 = *phead;
	while (p1 != NULL && p2->next != NULL) {//注意判断条件，否则会报错。
		p1 = p1->next;
		p2 = (p2->next)->next;

		if (p1 == p2) {
			return 1;
		}
	}
	return 0;

	
}//1为有环，0位无环
pstu is_cross(pstu *phead1,pstu *phead2) {
	pstu p1, p2;
	p1 = *phead1; p2 = *phead2;
	int n1=0, n2=0;
	while (p1) {
		n1++;
		p1 = p1->next;
	}
	while (p2) {
		n2++;
		p2 = p2->next;
	}
	p1 = *phead1;
	p2 = *phead2;
	if (n2 > n1) {
		for (int i = 0; i < n2 - n1; i++) {
			p2 = p2->next;
		}
	}
	else if (n1 > n2) {
		for (int i = 0; i < n1 - n2; i++) {
			p1 = p1->next;
		}
	}
	while (p1) {
		if (p1->num = p2->num) {
			return p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}
int main() {
	pstu head = NULL, tail = NULL;
	int addr;
	for (int i = 1; i < 6; i++) {
		list_tail_insert(&head, &tail, i);
	}
	/*pstu tmp;
	pstu b = head, e = b->next;
	while (b->next != e) {
		tmp = b->next;

	}*/
	//mid(&head);
	//last_four(&head);
	list_reverse(&head);
	printf("%d", is_circle(&head));
	while (head != NULL) {
		printf("%d ", head->num);
		head = head->next;
	}
	
}