#include"sort.h"

void arrPrint(int* arr) {
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void arrSelect(int* arr) {
	int max;
	for (int i = 0; i < N; i++) {
		max = 0;
		for (int j = 1; j < N - i; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		SWAP(arr[max], arr[N - 1 - i]);
	}
}
void arrInsert(int* arr) {
	int tmp,k;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			tmp = arr[j];
			if (arr[i] < arr[j]) {
				for (k = i; k > j; k--) {
					arr[i] = arr[i - 1];
				}
				arr[k] = tmp;
				break;
			}
		}
		
	}
}
int partition(int *arr, int left, int right) {
	int i, j;
	i = left + 1;
	for (j = left + 1; j <= right; j++) {
		if (arr[j] < arr[left]) {
			SWAP(arr[j],arr[i]);
			i++;
		}
	}
	SWAP(arr[i - 1], arr[left]);
	return i - 1;
}
void arrQuick(int *arr, int left, int right) {
	int prior;
	if (left < right) {
		prior = partition(arr, left, right);
		arrQuick(arr, left, prior-1);//prior已经到达最佳位置，不用参与下一轮排序，务必注意。
		arrQuick(arr, prior + 1, right);
	}
}
int compare(const void *pleft, const void *pright) {
	int *p1 = (int *)pleft;
	int *p2 = (int *)pright;
	return *p1 - *p2;
}
