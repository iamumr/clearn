#include<stdio.h>
#include<stdlib.h>
int sum;
int step[100][2];
void print(int index) {
	for (int h = 0; h < index; h++) {
		printf("(%d,%d)->", step[h][0], step[h][1]);
	}
	printf("(%d,%d)", step[index][0], step[index][1]);
	printf("     %d\n", sum);
}
void search(int x, int y, int m, int n, int index) {
	step[index][0] = x;
	step[index][1] = y;
	if (x == m && y == n) {
		sum++;
		print(index);
		return;
	}
	else if (x > m || y > n) {
		return;
	}
	else {
		search(x+1, y, m, n, index + 1);
		search(x, y + 1, m, n, index + 1);
	}
	//printf("总计：%d", sum);
}


int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		printf("(0,0)->(%d,%d)\n", m, n);
		search(0, 0, m, n, 0);
		printf("总计：%d\n", sum);
		sum = 0;
	}
}