#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char a[200];
	char b[200];
	int n = 0;
	while (gets(a) != NULL) {
		char *c;
		c = a;
		while (*c) {
			if (*c != ' ') {
				b[n++] = *c;
				if (*(c + 1) == ' ') {
					b[n++] = '_';
				}				
			}
			c++;
		}
		b[n] = '\0';
		puts(b);
	}
	
}