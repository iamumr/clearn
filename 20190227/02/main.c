#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
typedef struct word {
	char s[50];
	int n;
	struct word *next;
}Word,*pWord;
Word ten[10];
void insert_word(pWord *a,char *b) {
	pWord new;
	new = (pWord)malloc(sizeof(Word));
	memset(new, 0, sizeof(Word));
	new->n++;
	strcpy(new->s, b);
	if (*a == NULL) {
		*a = new;
	}
	else {
		(*a)->next = new;
	}
}
void insert_word_sort(pWord *a, char *b) {
	pWord new;
	new = (pWord)malloc(sizeof(Word));
	memset(new, 0, sizeof(Word));
	new->n = 1;
	strcpy(new->s, b);
	pWord begin,end;
	begin = *a;
	end = *a;
	if (NULL == *a) {
		*a = new;
	}
	else if(strcmp(new->s,(begin)->s)==0){
		begin->n++;
		free(new);
		return;
	}
	else if (strcmp(new->s, (begin)->s) < 0) {
		new->next = *a;
		*a = new;
	}
	else {
		while (begin != NULL) {

			if (strcmp(new->s, (begin)->s) == 0) {
				begin->n++;
				free(new);
				break;
			}
			else if (strcmp(new->s, (begin)->s) < 0) {
				new->next = begin;
				end->next = new;
				break;
			}
			end = begin;
			begin = begin->next;
		}
		if (NULL == begin) {
			end->next = new;
		}
	}
}
//int compare(const void *pleft, const void *pright) {
//	pWord p1 = (pWord)pleft;
//	pWord p2 = (pWord)pright;
//	return p1->n - p2->n;
//}
int compare(const void *pleft, const void *pright)
{
	Word *p1 = (Word *)pleft;
	Word *p2 = (Word *)pright;
	return p1->n - p2->n;
}
//int first_ten(pWord *a,int sum) {
//	int i, j;
//	Word tmp;
//	char t1[50];
//	int t2;
//	pWord p1,p2;
//	p1 = *a;
//	if(NULL!=p1) p2 = (*a)->next;
//	for (i = 0; i < sum - 1; i++) {
//		for (j = 0; j < sum - 1 - i; j++) {
//			if (p1->n > p2->n) {
//				strcpy(t1, p1->s);
//				t2 = p1->n;
//				p1->n = p2->n;
//				strcpy(p1->s, p2->s);
//				p2->n = t2;
//				strcpy(p2->s, t1);
//			}
//			p1 = p1->next;
//			if(NULL!=p2->next)p2 = p2->next;
//			
//		}
//		p1 = *a;
//		if (NULL != *a) p2 = (*a)->next;
//	}
//}

int first_ten(pWord *a, int sum) {
	int i, j;
	int n = 0;
	Word tmp;

	char t1[50];
	int t2;
	pWord p1, p2,p1pre,p2pre;
	p1 = *a;
	if (NULL != p1) p2 = (*a)->next;
	while (NULL != p1) {
		//for (j = 0; j < sum - 1 - n; j++) {
		while (NULL != p2){
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
		if(NULL!=p1pre) p1pre->next = NULL;
		if (n == 10) return;
		p1 = *a;
		if (NULL != *a) p2 = (*a)->next;
	}
}
int main() {
	FILE *fp = fopen("The_Holy_Bible_Res.txt", "r");
	pWord head = NULL;
	int num = 0;
	//insert_word_sort(&head, "aa");
	//insert_word_sort(&head, "ee");
	//insert_word_sort(&head, "bb");

	//printf("%s", head->s);
	//printf("%s", head->next->s);
	//int n;
	clock_t start, end;
	start = clock();
	char tmp[50] = {0};
	char b;
	int line=0, charnum=0;
	//while (!feof(fp)) {
	//	fscanf(fp, "%s", tmp);
	//	if (tmp[0] >= '0'&&tmp[0] <= '9') {
	//		continue;
	//	}
	//	insert_word_sort(&head, tmp);
	//	num++;
	//}
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
	printf("sum of char:%d;sum of line:%d;sum of word:%d",charnum,line, num);
}