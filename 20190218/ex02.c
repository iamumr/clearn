#include<stdlib.h>
#include<stdio.h>
struct ll {
	int number;
	char name;
};
void compare(struct ll *a, struct ll *b) {
	int tmp; char tmpc;
	if (a->number < b->number) {
		tmp = a->number; a->number =  b->number; b->number = tmp;
		tmpc = a->name; a->name = b->name; b->name = tmpc;
	}
}
void printw(struct ll a) {
	if (a.name == 'a') printf("alp      ");
	if (a.name == 'o') printf("oth      ");
	if (a.name == 'n') printf("num      ");
}
int main() {
	struct ll max, min, mid;
	max.number = 0; min.number = 0; mid.number = 0;
	char x;
	//int max,mid,min;
	while (rewind(stdin), scanf("%c", &x) != EOF) {
		if (x >= 48 && x <= 57) { max.number++; max.name = 'n'; }
		else if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) { mid.number++; mid.name = 'a'; }
		else { min.number++; min.name = 'o'; }
	}
	//printf("%d %d %d", alp, num, oth);
	//max = (alp > num ? alp : num) > oth ? (alp > num ? alp : num) : oth;

	
	/*for (int i = 1; i <= max + 2; i++) {
		if (1 == i) { printf("  %d  ", max); }
	}*/
	compare(&max, &mid);
	compare(&max,&min);
	compare(&mid, &min);
	for (int i = 1; i <= max.number + 2; i++) {
		if (1 == i) { printf("  %d  ", max.number); }
		else if(i > 1 && i < max.number + 2) { 
			printf("*****"); 
			printf("    ");
			if (i == max.number - mid.number + 1) {
				printf("  %d  ", mid.number);
			}
			else if (i > max.number - mid.number&& i < max.number+2) { printf("*****    "); }
			//printf("    ");
			if (i == max.number - min.number + 1) {
				printf("  %d  ", min.number);
			}
			else if (i > max.number - min.number && i<max.number+2) { printf("*****"); }
		}
		else { printf(" "); printw(max); printw(mid); printw(min); }
		printf("\n");
	}
}