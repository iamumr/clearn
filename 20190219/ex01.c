#include<stdio.h>
#include<stdlib.h>
//#define a -1111
char* mystrcpy(char *dest,char *from) {
	if (dest == NULL || from == NULL)
		return NULL;
	if (dest == from) {
		return dest;
	}
	char *tmp = dest;
	while ((*dest++ = *from++) != '\0');

}
int mystrcmp(const char *str1, const char *str2) {
	if (str1 == NULL || str2 == NULL) {
		return 0;
	}
	while (*str1 == *str2) {
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;

	}
	return *str1 - *str2;
}
char *mystrcat(char* str1, const char *str2) {
	if (str1 == NULL || str2 == NULL) {
		return 0;
	}
	char *ad = str1;
	/*while (*ad) {
		ad++;
	}*/
	while (*str1) {
		str1++;
	}
	//rewind(stdin);
	while (*str1++ = *str2++);
	return str1;
}
size_t mystrlen(char *str) {
	size_t tmp=0;
	while (*str) {
		str++; 
		tmp++;
	}
	return tmp;
}

int main() {
	//printf("%d", a);
	char a[40] = "HELLO";
	char b[40];
	mystrcpy(b, a);
	printf("%s", b);
	printf("%d", mystrcmp(b, a));
	 mystrcat(a, b);
	rewind(stdin);
	printf("%s", a);
	printf("%d", mystrlen(a));
}