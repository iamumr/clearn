#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void replace(char *a) {
	char *p;
	p = (char *)malloc(strlen(a));
	int t = a;
	strcpy(p, a);
	while (*p) {
		if (*p == ' ') {
			*a++ = '%';
			*a++ = '0';
			*a++ = '2';
			*a++ = '0';
		}
		else {
			*a++ = *p;
		}
		p++;
	}
	*a = '\0';
	//*a = *p;
	a = t;
}
int main() {
	char a[50];
	while (gets(a)!=NULL) {
		replace(a);
		puts(a);
	}
	
}