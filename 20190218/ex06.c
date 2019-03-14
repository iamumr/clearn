#include<stdlib.h>
#include<stdio.h>
static int monthd[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
static char *begin[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int ex01(int year, int month, int day) {
	int sum = 0;
	for (int i = 0; i < month - 1; i++) {
		sum += monthd[i];
	}
	if (month > 2) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			sum++;
		}
	}
	return sum + day;

}
int back(int year, int month, int day) {
	int sum = 0;
	for (int i = month; i < 12; i++) {
		sum += monthd[i];
	}
	if (month == 2) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			sum += (29 - day);
		}
		else {
			sum += (28 - day);
		}
	}
	else {
		sum += (monthd[month-1] - day);
	}
	return sum;
}
int ex02(int year1, int year2, int month1, int month2, int day1, int day2) {
	int sum = 0;
	if (year1 > year2) {
		if (year1-year2>1){
			sum = back(year2, month2, day2) + ex01(year1, month1, day1);
			for (int i = year2 + 1; i < year1; i++) {
				sum += ex01(i, 12, 31);
			}
		}
		else {
			if (year2 - year1 > 1) {
				sum = back(year2, month2, day2) + ex01(year1, month1, day1);
				for (int i = year1 + 1; i < year2; i++) {
					sum += ex01(i, 12, 31);
				}
			}
			else {
				sum = back(year2, month2, day2) + ex01(year1, month1, day1);
			}
			}
		}
	else if(year1 < year2){
		sum = back(year1,month1,day1) + ex01(year2,month2,day2);
		}
	else {
		/*if (month1 = month2) {
			sum = (day1 > day2) ? day1 - day2 : day2 - day1;
		}
		else {*/
			sum = abs(ex01(year1, month1, day1) - ex01(year2, month2, day2));
	/*	}*/
	}
	return sum;
}
char* ex03(int year, int month, int day) {
	return begin[ex02(year, 1970, month, 1, day, 4) % 7 - 1];
}
int monthday(int year, int month) {
	if (year % 4 == 0 && year % 400 != 0 || year % 100 == 0) {
		if (month == 2) {
			return monthd[month-1] + 1;
		}
		else {
			return monthd[month-1];
		}
	}
	else {
		return monthd[month-1];
	}
}
void ex04(int *year, int *month, int *day, int *n) {
	int m;
	m = monthday(*year, *month) - *day;
	if (*n < m) {
		*day += *n;
		return;
	}
	while (*n > m) {
		/*if (*n < m) {
			*day += *n;
			return;
		}
		else {*/
			*n -= m;
			if (*month < 12) {
				*month=*month +1;
				*day = 0;
			}
			else {
				*month = 1;
				*year = *year + 1;
				*day = 0;
			}
			m = monthday(*year,*month);
			}
		*day = *n;
		return;
		
	//}
}
void ex05(int year, int month) {
	int m = monthday(year, month);
	printf("******************************************************\n");
	printf("%6s", "SUN");
	for (int i = 0; i < 6; i++) {
		printf("%6s", begin[i]);
	}
	printf("\n");
	int tmp = ex02(year, 1970, month, 1, 1, 4) % 7;
	for (int i = 0; i < tmp; i++) {
		printf("      ");
	}
	for (int i = 1; i <= m; i++) {
		if (ex02(year, 1970, month, 1, i, 4) % 7 != 6) {
			printf("%6d", i);
		}
		else {
			//printf("\n");
			rewind(stdin);
			printf("%6d\n",i);
		}
	}
}
int main() {
	//printf("%d ", ex01(2019,3,25));
	//printf("%d ", back(2018, 3, 30));
	//printf("%d",ex02(2019, 2016, 3, 3, 25, 30));
	//printf("%d", ex01(2019,3,1));
	//printf("%s", ex03(2019, 2, 19));
	//printf("%d", monthday(2008, 2));
	/*int a = 2019, b = 2, c = 19, d = 100;
	ex04(&a,&b,&c,&d);
	printf("%d %d %d", a, b, c);*/
	ex05(2019, 10);
}