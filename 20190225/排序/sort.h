#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500000
#define SWAP(a,b) {int tmp;tmp=a;a=b;b=tmp;}
void arrPrint(int*);
void arrSelect(int*);
void arrInsert(int*);
void arrQuick(int *, int, int);
int compare(const void *, const void *); 