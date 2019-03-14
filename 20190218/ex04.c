#include<stdio.h>
#include<stdlib.h>
int to2_10(int a) {
	int b, tmp = a, num = 0, i = 0;
	while (tmp != 0) {
		b = tmp % 2;
		if (1 == b) i++;
		tmp = tmp / 2;
	}
	return i;

}
int main() {
	int a;
	scanf("%d", &a);
	a = to2_10(a);
	printf("%d", a);

}