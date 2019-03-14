#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
typedef struct word {
	char s[50];
	int n;
	struct word *next;
}Word, *pWord;
//Word hash[15000];

Word ten[10];

void insert_word_sort(pWord *a, char *b) {
	pWord pnew;
	pnew = (pWord)malloc(sizeof(Word));
	memset(pnew, 0, sizeof(Word));
	pnew->n = 1;
	strcpy(pnew->s, b);
	pWord begin, end;
	begin = *a;
	end = *a;
	if (NULL == *a) {
		*a = pnew;
	}
	else if (strcmp(pnew->s, (begin)->s) == 0) {
		begin->n++;
		free(pnew);
		return;
	}
	else if (strcmp(pnew->s, (begin)->s) < 0) {
		pnew->next = *a;
		*a = pnew;
	}
	else {
		while (begin != NULL) {

			if (strcmp(pnew->s, (begin)->s) == 0) {
				begin->n++;
				free(pnew);
				break;
			}
			else if (strcmp(pnew->s, (begin)->s) < 0) {
				pnew->next = begin;
				end->next = pnew;
				break;
			}
			end = begin;
			begin = begin->next;
		}
		if (NULL == begin) {
			end->next = pnew;
		}
	}
}

int first_ten(pWord *a, int sum) {
	int i, j;
	int n = 0;
	Word tmp;

	char t1[50];
	int t2;
	pWord p1, p2, p1pre, p2pre;
	p1 = *a;
	if (NULL != p1) p2 = (*a)->next;
	while (NULL != p1) {
		//for (j = 0; j < sum - 1 - n; j++) {
		while (NULL != p2) {
			if (p1->n > p2->n) {
				strcpy(t1, p1->s);
				t2 = p1->n;
				p1->n = p2->n;
				strcpy(p1->s, p2->s);
				p2->n = t2;
				strcpy(p2->s, t1);
			}
			p1pre = p1;
			p2pre = p2;
			p1 = p1->next;
			p2 = p2->next;
			/*if (NULL != p1->next) p1 = p1->next;
			if (NULL != p2->next)p2 = p2->next;*/
		}
		ten[n++] = *p2pre;
		free(p2pre);
		if (NULL != p1pre) p1pre->next = NULL;
		if (n == 10) return;
		p1 = *a;
		if (NULL != *a) p2 = (*a)->next;
	}
}
int main1() {
	FILE *fp = fopen("The_Holy_Bible_Res.txt", "r");
	pWord head = NULL;
	int num = 0;
	clock_t start, end;
	start = clock();
	char tmp[50] = { 0 };
	char b;
	int line = 0, charnum = 0;
	int wordcount = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%c", &b);
		charnum++;
		if (b == '\n') { line++; }
		if (b >= 'a'&&b <= 'z') {
			tmp[wordcount++] = b;
		}
		else {
			tmp[wordcount] = '\0';
			if (wordcount != 0) { insert_word_sort(&head, tmp); num++; }
			wordcount = 0;

		}

	}
	//end = clock();
	//qsort(*head, num, sizeof(Word), compare);
	first_ten(&head, num);
	num = 0;
	while (head != NULL) {
		num++;
		head = head->next;
	}
	/*for (int g = 0; g < 10; g++) {
		printf("%s\t%d\n", ten[g].s, ten[g].n);
	}
	end= clock();
	printf("time=%f\n", (double)(end - start) / CLOCKS_PER_SEC);*/
	printf("sum of char:%d;sum of line:%d;sum of word:%d", charnum, line, num);
}
int get_index(char *a) {
	int sum = 0;
	while (*a) {
		sum += *a;
		a++;
	}
}
int main() {
	//FILE *fp = fopen("The_Holy_Bible_Res.txt", "r");
	//pWord head = NULL;
	//int num = 0, line = 0, charnum = 0;
	//char w[50];
	//clock_t start, end;
	//for (int i = 0; i < 15000; i++) {
	//	hash[i].n = 0;
	//	hash[i].next = NULL;
	//}
	char a[10] = "abcdefg";
	printf("%d", get_index(a));
}