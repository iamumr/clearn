#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct num {
	char n;
	struct num *next;
}number,*pnum;
void list_head_insert(pnum *phead, char i) {
	pnum new;
	new = (pnum)malloc(sizeof(number));
	memset(new, 0, sizeof(number));
	new->n = i;
	if (*phead == NULL) {
		*phead = new;
	}
	else {
		new->next = *phead;
		*phead = new;
	}
}
pnum sum(pnum* phead1, pnum* phead2) {
	int i, j;
	int tmp = 0;
	pnum p1, p2;
	pnum new=NULL;
	p1 = *phead1;
	p2 = *phead2;
	while (p1&&p2) {
		i = p1->n - '0';
		j = p2->n - '0';
		//tmp = i + j;
		if (i + j + tmp >= 0 && i + j + tmp <= 19) {
			if (i + j + tmp > 9) {
				list_head_insert(&new, ((i + j + tmp) % 10) + '0');
				tmp = (i + j + tmp) / 10;
			}
			else {
				list_head_insert(&new, (i + j + tmp) + '0');
				tmp = 0;
			}
		}
		p1 = p1->next;
		p2 = p2->next;
	}	
	while (p1) {
		list_head_insert(&new, p1->n + tmp);
		tmp = 0;
		p1 = p1->next;
	}
	while (p2) {
		list_head_insert(&new, p2->n + tmp);
		tmp = 0;
		p2 = p2->next;
	}

	if (tmp == 1) {
		list_head_insert(&new, tmp+'0');
	}
	return new;

}
int main() {
	number st;
	pnum head1 = NULL;
	pnum head2 = NULL;
	char tmp;
	while (scanf("%c", &tmp) != EOF) {
		if (tmp != 10) {
			list_head_insert(&head1, tmp);
			//list_head_insert(&head2, tmp);
		}
	}
	while (scanf("%c", &tmp) != EOF) {
		if (tmp != 10) {
			//list_head_insert(&head1, tmp);
			list_head_insert(&head2, tmp);
		}
	}
	//while (head1) {
	//	printf("%c", head1->n);
	//	head1 = head1->next;
	//}
	pnum sum1=sum(&head1,&head2);
	while (sum1) {
		printf("%c", sum1->n);
		sum1 = sum1->next;
	}3

	
}