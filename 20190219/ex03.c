#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char a[50];
	gets(a);
	int i = 0;
	while (a[i]) {
		if (a[i] > 'a'&&a[i] < 'z') {
			printf("%c", a[i]);
			if (a[i + 1] == ' ') {
				printf("\n"); 
			}
		}
		i++;
		/*if (a[i] == ' '&& a[i - 1] > 'a'&&a[i - 1] < 'z') {
			printf("\n");
		}*/
	}
}