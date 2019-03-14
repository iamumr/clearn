#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	int num;
	char name[20];
	int score[3];
}stu,*pstu;
void ex01(pstu a){
	stu tmp;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4 - j; k++) {
			if (a[k].num > a[k + 1].num) {
				//tmp1 = sum[k]; sum[k] = sum[k + 1]; sum[k + 1] = tmp1;
				tmp = a[k]; a[k] = a[k + 1]; a[k + 1] = tmp;

			}
		}
	}
	for (int j = 0; j < 5; j++) {
		printf("%d %s %d %d %d\n", a[j].num, a[j].name, a[j].score[0], a[j].score[1], a[j].score[2]);
	}
}
void ex03(pstu a) {
	int sum1=0, sum2=0, sum3=0;
	for (int i = 0; i < 5; i++) {
		sum1 += a[i].score[0];
		sum2 += a[i].score[1];
		sum3 += a[i].score[2];
	}
	sum1 /= 5;
	sum2 /= 5;
	sum3 /= 5;
	printf("%d %d %d", sum1, sum2, sum3);
}
void ex02(pstu a) {
	int m0=0, m1=0, m2=0;
	for (int i = 1; i < 5; i++) {
		if (a[m0].score[0] < a[i].score[0]) {
			m0 = i;
		}
		if (a[m1].score[1] < a[i].score[1]) {
			m1 = i;
		}
		if (a[m2].score[2] < a[i].score[2]) {
			m2 = i;
		}
	}
	printf("%d %s %d %d %d\n", a[m0].num, a[m0].name, a[m0].score[0], a[m0].score[1], a[m0].score[2]);
	printf("%d %s %d %d %d\n", a[m1].num, a[m1].name, a[m1].score[0], a[m1].score[1], a[m1].score[2]);
	printf("%d %s %d %d %d\n", a[m2].num, a[m2].name, a[m2].score[0], a[m2].score[1], a[m2].score[2]);

}
void ex04(pstu a) {
	//pstu p[5];
	int sum[5];
	stu tmp;
	int tmp1;
	for (int i = 0; i < 5; i++) {
		sum[i] = a[i].score[0] + a[i].score[1] + a[i].score[2];
	}
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4 - j; k++) {
			if (sum[k] > sum[k + 1]) {
				tmp1 = sum[k]; sum[k] = sum[k + 1]; sum[k + 1] = tmp1;
				tmp = a[k]; a[k] = a[k + 1]; a[k + 1] = tmp;

			}
		}
	}
	for (int j = 0; j < 5; j++) {
		printf("%s ", a[4 - j].name);
	}
}
int main() {
	int n, sc[3];
	char na[20];
	stu st[5];
	//st = (pstu)malloc(5 * sizeof(stu));
	for (int i = 0; i < 5; i++) {
		scanf("%d %s%d%d%d", &n, &na, &sc[0], &sc[1], &sc[2]);
		(st[i]).num = n;
		strcpy((st[i]).name, na);
		(st[i]).score[0] = sc[0];
		(st[i]).score[1] = sc[1];
		(st[i]).score[2] = sc[2];
	}
	ex01(st);//学号递增
	ex02(st);//单门最高分
	ex03(st);//每门课平均分
	ex04(st);//总分排名
	system("pause");
}