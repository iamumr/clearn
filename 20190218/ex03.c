#include<stdio.h>
#include<stdlib.h>
void to2_10(int a) {
	int b,tmp=a,num=0,i=1;
	while (tmp!=0) {
		b = tmp % 2;
		num += b * i;
		i *= 10;
		tmp = tmp / 2;
	}
	printf("%d", num);

}
void to10_2(char *a) {
	int num=0,h=1;
	for (int i = 0; a[i] != '\0'; i++) {
		//printf("%c", a[1]);
		num += (a[i]-'0') * h;
		h *= 2;
	}
	printf("%d", num);

}
to16_10(int a) {
	//char a16[6] = { 'A','B','C','D','E','F' };
	static int i = 0;
	int tmp = a, h; char b[20];
	while (tmp) {
		h = tmp % 16;
		if (h < 10) { b[i] = h + '0'; }
		else { b[i] = h + 'A' - 10; }
		tmp = tmp / 16;
		i++;
	}
	rewind(stdin);
	for (i=i-1; i >= 0; i--) {
		
		printf("%c",b[i]);
	}

}
to10_16(char *a) {
	int i, num=0,h=1;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= '0'&&a[i] <= 9) { num += (a[i] - '0')*h; }
		else { num += (a[i] - 'A' + 10)*h; }
		h *= 16;
	}
	printf("%d", num);
}
int main() {
	int a;
	//char b[50];
	//scanf("%d", &a);
	//to2_10(a);
	//scanf("%s", b);
	//to10_2(&b);
	//to10_16(&b);
	scanf("%d",&a);
	to16_10(a);
}