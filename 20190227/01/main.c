#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main() {
	FILE *fp = fopen("The_Holy_Bible.txt", "r");
	FILE *newb = fopen("The_Holy_Bible_Res.txt", "w+");
	if (NULL == fp) {
		perror("fopen");
	}
	char c;
	while ((c = fgetc(fp)) != EOF) {
		if (c != '\n'&& (c<'a'||c>'z')&&(c<'0'||c>'9')) {
			if (c <= 'Z'&&c >= 'A') {
				c = c + 32;
			}
			else {
				c = ' ';
			}
		}
		fputc(c, newb);
		/*printf("%c", c);*/
	}
	
}