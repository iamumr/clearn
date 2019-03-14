#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *addbigtest(char *a, char* b) {
	int lena = strlen(a), lenb = strlen(b);
	int lens = lena > lenb ? lena : lenb;
	char *sum = (char *)malloc((lens + 1) * sizeof(char));
	sum[lens] = 0;
	//printf("%d %d", strlen(a), strlen(b));
	//for (int i = 0; i < strlen(a); i++) {
		a[0] = a[0] - '0';
		printf("%c", a[0]);
	//}
}
char *addbig(char *a, char* b) {
	int lena = strlen(a), lenb = strlen(b);
	int lens = lena > lenb ? lena : lenb;
	char *sum = (char *)malloc((lens+2)*sizeof(char));
	sum[lens] = 0;
	//sum[lens + 1] = '\0';
	//printf("%d %d", strlen(a), strlen(b));
	for (int i = 0; i < lena; i++) {
		a[i] = a[i] - '0';
	}
	for (int i = 0; i < lenb; i++) {
		b[i] = b[i] - '0';
	}
	for (int i = 0,j = 0; i < lena && i < lenb; i++, j++) {
		sum[i] = a[lena - i - 1] + b[lenb - i - 1];
	}
	if (lena > lenb) {
		for (int i = lenb; i < lena; i++) {
			sum[i] = a[lena - i - 1];
		}
	}
	else {
		for (int i = lena; i < lenb; i++) {
			sum[i] = a[lenb - i - 1];
		}
	}
	for (int i = 0; i < lens - 1; i++) {
		if (sum[i] > 9) {
			sum[i + 1] = sum[i + 1] + sum[i] / 10;
			sum[i] = sum[i] % 10;
		}
	}
	if (sum[lens-1] > 9) {
		sum[lens] = sum[lens] + sum[lens - 1] / 10;
		sum[lens - 1] = sum[lens - 1] % 10;
	}
	if (sum[lens] == 0) {
		for (int i = 0; i < lens / 2; i++) {
			char tmp = sum[i];
			sum[i] = sum[lens - i - 1];
			sum[lens - i - 1] = tmp;
		}
		for (int i = 0; i < lens; i++) {
			sum[i] = sum[i] + '0';
		}
	}
	else {
		for (int i = 0; i < lens / 2+1; i++) {
			char tmp = sum[i];
			sum[i] = sum[lens - i];
			sum[lens - i] = tmp;
		}
		for (int i = 0; i < lens + 1; i++) {
			sum[i] = sum[i] + '0';
		}
	}
	/*for (int i = 0; i < lens+1; i++) {
		sum[i] = sum[i] + '0';
	}*/
	sum[lens + 1] = 0;
	return sum;
}
int main() {
	char a[50];
	char b[50];
	scanf("%s", &a);
	rewind(stdin);
	scanf("%s", &b);
	//addbigtest(&a, &b);
	char *sum =addbig(a, b);
	//printf("%d %d", strlen(a), strlen(b));
	puts(sum);
	//printf("%c", sum[7]);
}