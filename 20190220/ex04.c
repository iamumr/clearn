#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int a[50] = {1,2,2,2,3,3,3,4,4,5,5,5,6,6,6};
	int b[50] = {0};
	int n = 0;
	for (int i = 0; i < 49; i++) {
		if (a[i] != a[i + 1]) {
			b[n] = a[i];
			n++;
		}
	}
	//b[n] = a[50];
	//printf("%d\n", a[30]);
	for (int i = 0; i < 50; i++) {
		if(b[i]!=0) printf("%d ", b[i]);
	}
}