#include<stdio.h>
#include<stdlib.h>
int main() {
	char a;
	while (rewind(stdin),scanf("%c",&a)!=EOF){
		//if ('Z'==a) return 0;
		printf("%c", a - 32);
		printf("\n");
		//rewind(stdin);
	}
	return 0;
}