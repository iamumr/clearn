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
void list_del_same(pstu *phead) {//	去除重复元素，需要序列有序，无序现调用排序算法
	//int n=-1;
	pstu p1,pre;
	pre = *phead;
	if(pre) p1 = (*phead)->next;
	while (p1) {
		if (p1->num == pre->num) {
			pre->next = p1->next;
			p1 = p1->next;
		}
		else {
			p1 = p1->next;
			pre = pre->next;
		}
	}
}

int main() {
	pstu head = NULL, tail = NULL;
	int addr;
	for (int i = 1; i < 6; i++) {
		list_tail_insert(&head, &tail, i);
		list_tail_insert(&head, &tail, i);

	}


	list_del_same(&head);
		while (head != NULL) {
			printf("%d ", head->num);
			head = head->next;
		}
}