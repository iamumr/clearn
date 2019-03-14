#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void del(char *a,char b) {
	char *c,*d;
	c = a;
	d = a;
	while (*c) {
		if (*c == b) {
			c++;
		}
		else {
			*d++ = *c++;
		}
	}
	*d = '\0';
	/*while (*c) c++;
	while (*c != *a) {
		if (*c == b) {
			*c = *(c + 1);
		}
	}*/
	/*while (*c) {
		if (*c == b) {
			
		}
	}*/
}
int main() {
	char a[50];
	char b;
	scanf("%s", &a);
	rewind(stdin);
	scanf("%c", &b);
	del(a, b);
	puts(a);
	
}