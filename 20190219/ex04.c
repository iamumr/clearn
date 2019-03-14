#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main() {
//	char a[50];
//	gets(a);
//	int i = 0;
//	char *b = a;
//	char *c = a;
//	char tmp;
//	while (*b) {
//		b++;
//	}
//	b--;
//	while (c!=b) {
//		tmp = *c;
//		*c = *b;
//		*b = tmp;
//		c++;
//		b--;
//	}
//	printf("%s", a);
//	*b = a;
//	char *d=a;
//	*c = a;
//	while (*b) {
//		while (*b != ' ') {
//			d = b;
//			b++;
//			break;
//		}
//		while (*b != ' ') {
//			c = b;
//			b++;
//		}
//		while (d != c) {
//			tmp = *d;
//			*d = *c;
//			*c = tmp;
//			c--;
//			d++;
//		}
//		b++;
//		*d = *c = a;
//	}
//	printf("%s", a);
//}
int main() {
	char a[50];
	gets(a);
	int n=0;
	int begin =0,end = 0;
	while (a[n] != '\0') {
		n++;
	}
	n--;
	printf("%d\n", n);
	for (int i = 0; i <= n / 2; i++) {
		char tmp = a[i];
		a[i] = a[n - i];
		a[n - i] = tmp;
	}
	printf("%s\n", a);
	for (int i = 0; i <= n; i++) {
		while (a[i] != ' ') {
			begin = i;
			end = i;
			i++;
			break;
		}
		while (a[i] != ' '){
			if (a[i] == '\0') break;
			end = i;
			i++;
		}
		for (int j = begin; j <= (end - begin) / 2 + begin; j++) {
			char tmp = a[j];
			a[j] = a[end - j+begin];
			a[end - j+begin] = tmp;
		}
	}
	printf("%s", a);
}