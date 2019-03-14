#include<stdlib.h>
#include<stdio.h>
int ex01() {
	int a[101];
	for (int i = 1; i <= 50; i++) {
		a[i-1] = i;
		a[101 - i] = i;
	}
	a[50] = 99;
	int num=0;
	for (int i = 0; i < 101; i++) {
		num = num ^ a[i];
	}
	printf("%d", num);
}
//unsigned int first1(int a) {
//	int n=0;
//	while ((a & 1 == 1) && (n < 32)) {
//		a = a >> 1;
//		n++;
//	}
//	return n;
//}
int findfirst1(int a) {
	return a & (-a);
}
int isbit1(int a,unsigned int n) {
	a = a >> (n-1);
	return(a & 1);
}
void ex02() {
	int a[102];
	for (int i = 1; i <= 50; i++) {
		a[i - 1] = i;
		a[102 - i] = i;
	}
	a[50] = 536;
	a[51] = 379;
	int num = 0;
	for (int i = 0; i < 102; i++) {
		num = num ^ a[i];
	}
	unsigned int index = findfirst1(num);
	int n1=0, n2=0;
	for (int i = 0; i < 102; i++) {
		if (isbit1(a[i], index)==1) {
			n1 = n1 ^ a[i];
		}
		else {
			n2 = n2 ^ a[i];
		}
	}
	printf("%d  %d", n1, n2);
}

void find2(int a[], int n,int tmp) {
	int num = tmp;
	for (int i = 0; i < n; i++) {
		num = num ^ a[i];
	}
	unsigned int index = findfirst1(num);
	int n1 = 0, n2 = 0;
	for (int i = 0; i < n; i++) {
		if (isbit1(a[i], index) == 1) {
			n1 = n1 ^ a[i];
		}
		else {
			n2 = n2 ^ a[i];
		}
	}
	if (isbit1(tmp, index)) {
		n1 ^= tmp;
	}
	else {
		n2 ^= tmp;
	}
	printf("%d  %d", n1, n2);
}
void ex03() {
	int a[103];
	for (int i = 0; i < 50; i++) {
		a[i] = i + 1;
		a[102 - i] = i + 1;
	}
	a[50] = 100; a[51] = 101; a[52] = 102;
	int num=0,tmp1,tmp2,c1,c2;
	//for (int i = 0; i < 103; i++) {
	//	num = num ^ a[i];
	//}
	//tmp = findfirst1(num);
	for (int i = 0; i < 32; i++) {
		tmp1 = tmp2 = c1 = c2 = 0;
		for (int j = 0; j < 103; j++) {
			if (isbit1(a[j], i)) {
				tmp1 ^= a[j];
				c1++;
			}
			else {
				tmp2 ^= a[j];
				c2++;
			}
		}
		if (c1 % 2 != 0) {
			if (0 == tmp2) {
				continue;
			}
			else {
				find2(a, 103, tmp1);
				printf(" %d", tmp1);
				return;
			}
		}
		else {
			if (0 == tmp1) {
				continue;
			}
			else {
				find2(a, 103, tmp2);
				printf(" %d", tmp2);
			}
		}
	}

}
int main() {
	//ex01();
	//ex02();
	//int a = 8;
	//printf("%d", isbit1(a,1));
	//printf("%d", findfirst1(a));
	//int a[8] = { 1,1,2,2,3,3,4,5 };
	//find2(a, 8);
	ex03();
}