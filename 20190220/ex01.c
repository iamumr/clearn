#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change(char *a) {
	char *b = *a;
	char *c = *a;
	int d = a;
	while (*a) {
		if (*a >= '0'&&*a <= '9') {
			a++;
			return;
		}
		if (*a >= 'a'&&*a <= 'z') {
			b = a;
			a++;
		}
		while (*a >= 'a'&&*a <= 'z') {
			a++;
			
		}
		if (*a) {
			char tmp = *b;
			*b = *a;
			b++;
			while (b != a) {
				*a = *(a - 1);
				a--;
			}
			*a = tmp;
			/*b++;
			char tmp2 = *b;
			*b = tmp;
			b++;
			while (b != a) {
				*b = tmp2;
				b++;
				tmp2 = *b;
			}*/
		}
		//a = b;
	}
	a = d;
}
int main() {
	char a[50];
	while (gets(a) != NULL) {
		puts(a);
		change(a);
		puts(a);
	}
}