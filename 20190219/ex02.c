#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char a[50];
	int n = 0;
	int i = 0;
	gets(a);
	printf("%s", a);
	while (a[i]!='\0') {
		if (a[i] > 'a'&&a[i] < 'z') {
			if(0==i) n++;
			if (i > 1 && a[i - 1] == ' ') n++;
		}
		i++;
	}
	printf("%d", n);
}