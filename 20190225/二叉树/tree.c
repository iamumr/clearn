#include"tree.h"
pNode buildTree(char* t) {
	pNode p[N];
	int i, j;
	for (i = 0; i < N; i++) {
		p[i] = (pNode)malloc(sizeof(Node));
		p[i]->val = t[i];
	}
	j = 0;
	for (i = 1; i < N; i++) {
		if (NULL == p[j]->pleft) {
			p[j]->pleft = p[i];
		}
		else if(NULL==p[j]->pright) {
			p[j]->pright = p[i];
			j++;
		}

	}
	return p[0];
}
pNode buildTreePlus(char *t) {
	pNode treeR, new;
	pQueue head, tail, qnew, qfree;
	head = tail = NULL;
	while (*t) {
		new = (pNode)malloc(sizeof(Node));
		qnew = (pQueue)malloc(sizeof(Queue));
		new->val = t;
		qnew->treepos = new;
		if (treeR == NULL) {
			treeR = new;
			head = qnew;
			tail = qnew;
		}
		else {
			tail->pnext = qnew;
			tail = qnew;
			if (NULL == head->treepos->pleft) {
				head->treepos->pleft = new;
			}
			else if (NULL == head->treepos->pleft) {
				head->treepos->pleft = new;
				qfree = head;
				head = head->pnext;
				free(qfree);
				qfree = NULL;
			}
		}
		c++;
	}
	return treeR;
}
void preOrder(pNode t) {
	if (t) {
		putchar(t->val);
		preOrder(t->pright);
		preOrder(t->pleft);
	}
}
void midOrder(pNode t) {
	if (t) {
		
		misOrder(t->pright);
		putchar(t->val);
		misOrder(t->pleft);
	}
}
void latOrder(pNode t){
	latOrder(t->pleft);
	latOrder(t->pright);
	putchar(t->val);
}