#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 300
#define BIG 10
typedef struct word {
	char s[50];
	int n;
	struct word *next;
}Word, *pWord;
Word hash[MAX];
Word max[BIG];
//int ten[10];
int get_index(char *a) {
	int sum = 0;
	while (*a) {
		sum += *a;
		a++;
	}
	return sum % MAX;
}
void insert_word_sort(char *b) {
	int flag = 0;
	int index = get_index(b);
	pWord p1;
	if (hash[index].n == 0 || strcmp(hash[index].s, b) == 0) {
		hash[index].n++;
		strcpy(hash[index].s, b);
	}
	else {
		if (NULL == hash[index].next) {
			pWord pnew = (pWord)malloc(sizeof(Word));
			pnew->n = 1;
			pnew->next = NULL;
			strcpy(pnew->s, b);
			hash[index].next = pnew;
		}
		else {
			p1 = hash[index].next;
			while (p1 != NULL) {
				if (strcmp(p1->s, b) == 0) {
					p1->n++;
					flag = 1;
					break;
				}
				else {
					p1 = p1->next;
				}
			}
			if (flag == 0) {
				pWord pnew = (pWord)malloc(sizeof(Word));
				pnew->n = 1;
				//pnew->next = NULL;
				strcpy(pnew->s, b);
				//hash[index].next = pnew;
				pnew->next = hash[index].next;
				hash[index].next = pnew;
			}
		}
	}
}

void output1(pWord a) {
	int i;
	for (i = 0; i < MAX; i++) {
		if (hash[i].n != 0) {

		}
	}
}
void del_hash(char *a) {
	int index = get_index(a);
	if (strcmp(hash[index].s, a) == 0) {
		if (hash->next == NULL) {
			//hash[index].s = 0;
			hash[index].n = 1;
			return;
		}
	}
	else {
		Word *p1 = hash[index].next;
		while (p1) {
			if (strcmp(p1->s, a) == 0) {
				p1->n = 1;
				return;
			}
			p1 = p1->next;
		}
	}
}
void insert_max(char *a, int b) {
	int j;
	for (int i = 0; i < BIG; i++) {
		if (b > max[i].n) {
			for (j = 9; j > i; j--) {
				if (max[j - 1].n != 0) {
					max[j].n = max[j - 1].n;
					strcpy(max[j].s, max[j - 1].s);
				}
			}
			max[i].n = b;
			strcpy(max[i].s, a);
			break;
		}
	}
}
void OutPut(Word hash[])
{
	int i;
	int top = 0;
	//FILE *fn = fopen("word.txt", "w+");

	for (i = 0; i < 10; i++) {
		max[i].n = 0; max[i].next = NULL;
	}
	Word *p, *q;
	for (i = 0; i < MAX; i++)
	{
		if (hash[i].n != 0) {
			/*if(hash[i].n>max.n){
				max.n=hash[i].n;
				strcpy(max.s, hash[i].s);
			}*/
			//fprintf(fn, "%4d %s\n", hash[i].n, hash[i].s);
			insert_max(hash[i].s, hash[i].n);
			//ten[top] = i;
		}
		//fprintf(stdout, "%4d %s\n", hash[i].n, hash[i].s);
		if (hash[i].next != NULL)
		{
			p = hash[i].next;
			while (p)
			{
				/*if (hash[i].n > max.n) {
					max.n = hash[i].n;
					strcpy(max.s, hash[i].s);
				}*/
				//fprintf(fn, "%4d %s\n", p->n, p->s);
				insert_max(p->s, p->n);
				//q = p;
				p = p->next;
				//free(q);
				//q = NULL;
			}
		}
	}
	//del_hash(max.s);
	//printf("%s %d", max.s, max.n);
		//max.n = 0; max.next = NULL;
}
int main() {
	FILE *fp = fopen("The_Holy_Bible_Res.txt", "r");
	pWord head = NULL;
	int num = 0, line = 0, charnum = 0, wordcount = 0;
	char tmp[50], b;
	clock_t start, end;
	for (int i = 0; i < MAX; i++) {
		hash[i].n = 0;
		hash[i].next = NULL;
	}
	for (int i = 0; i < 10; i++) {
		max[i].n = 0;
		max[i].next = NULL;
	}
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
			if (wordcount != 0) { insert_word_sort(tmp); num++; }
			wordcount = 0;
		}
	}
	start = clock();
	OutPut(hash);
	end = clock();
	for (int i = 0; i < BIG; i++) {
		printf("%s\t%d\n", max[i].s, max[i].n);
	}
	printf("time=%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("sum of char:%d;sum of line:%d;sum of word:%d", charnum, line, num);
	//int ttt = get_index("the");
	//hash[get_index("the")].n = 1;
	//OutPut(hash);
	//char a[10] = "abcdefge";
	//printf("%d", get_index(a));
}
