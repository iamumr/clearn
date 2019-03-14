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
void list_divide(pstu *phead, pstu *head1, pstu *head2) {
	pstu p1,p2,p3,p4;
	int n = 1;
	p1 = *phead;
	p2 = *head1;
	p3 = *head2;
	p4 = NULL;
	while (p1) {
		if (n % 2 == 0) {
			if (NULL == *head2) { 
				*head2 = p1; 
				p3 = *head2;
				//p3->next = NULL;
			}
			p3->next = p1;
			p1 = p1->next;
			n++;
			p3 = p3->next;
			/*if (NULL == p3) { p3 = p1; }
			else { p3->next = p1; }*/
		}
		else {
			if (NULL == *head1) {
				*head1 = p1;
				p2 = *head1;
				
			}
			p2->next = p1;
			p1 = p1->next;
			n++;
			p2 = p2->next;
		}
		//p1 = p4;
	}
	if (p2->next == NULL) {
		p3->next = NULL;
	}
	else {
		p2->next = NULL;
	}
}


int main() {
	pstu head = NULL, tail = NULL;
	int addr;
	for (int i = 1; i < 10; i++) {
		list_tail_insert(&head, &tail, i);
	}


	
	while (head != NULL) {
		printf("%d ", head->num);
		head = head->next;
	}
}