#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	int num;
	struct strudent *next;
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
void del(pstu *phead, pstu *ptail, int i) {
	pstu first;
	pstu scond;
	first = *phead;
	scond = *phead;
	if (first != NULL) {
		if (first->num == i) {
			*phead = (*phead)->next;

			if (NULL == *phead) {
				*ptail = NULL;
			}
			free(first);
		}
		else {
			while (first != NULL) {
				if (first->num == i) {
					scond->next = first->next;
					free(first);
					break;
				}
				scond = first;
				first = first->next;
			}
			if (scond->next == NULL) {
				*ptail = scond;
			}
			if (NULL == first) {
				printf("no this node\n");
			}
		}
	}
	else {
	printf("list is NULL\n");
}
}
void list_combine(pstu *phead1, pstu *phead2) {
	pstu pend1,pend2;
	pend1 = *phead1;
	pend2 = *phead2;
	while (pend1->next != NULL) {
		pend1 = pend1->next;
	}
	while (pend2->next != NULL) {
		pend1->next = pend2;
		pend1 = pend1->next;
		pend2 = pend2->next;
	}
	pend1->next = pend2;
}
void list_merge(pstu *phead1, pstu *phead2) {
	if (phead1 == NULL) return phead2;
	if (phead2 == NULL) return phead1;
	pstu head,p1,p2;
	if ((*phead1)->num <= (*phead2)->num) {
		head = *phead1;
		p1 = (*phead1)->next;
		p2 = *phead2;
	}
	else {
		head = *phead2;
		p1 = (*phead2)->next;
		p2 = *phead1;
	}
	pstu change = head;
	while (p1&&p2) {
		if (p1->num <= p2->num) {
			change->next = p1;
			change = p1;
			p1 = p1->next;
		}
		else {
			change->next = p2;
			change = p2;
			p2 = p2->next;
		}
	}
	if (p1) change->next=p1;
	if (p2) change->next = p2;
	*phead1 = head;
}
int main() {
	pstu head = NULL, tail = NULL;
	pstu head1 = NULL, tail1 = NULL;
	char i;
	int s;
	/*FILE *open;
	if ((open = fopen("text.txt", "r")) == NULL) {
	printf("can't open\n");
	};*/
	//i = getc(open);
	//s = getw(open);

	while (scanf("%d",&s) != EOF) {
		//i = getc(open);
		//s = i - '0';
		list_tail_insert(&head, &tail, s);
		//s = getw(open);
		//i = getc(open);
	}
	while (scanf("%d", &s) != EOF) {
		list_tail_insert(&head1, &tail1, s);
	}
	//list_combine(&head, &head1);
	list_merge(&head, &head1);
	while (head != NULL) {
		printf("%d ", head->num);
		head = head->next;
	}
}