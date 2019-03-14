#include"sort.h"
void adjustMaxHeap(int *arr, int start, int end) {
	int dad = start;
	int son = 2 * dad + 1;
	while (son < end) {
		if (son < end&&arr[son] < arr[son + 1]) {
			son++;
		}
		if (arr[son] > arr[dad]) {
			SWAP(arr[son], arr[dad]);
			dad = son;
			son = dad * 2 + 1;
		}
		else {
			return;
		}

	}
}
//¶ÑÅÅĞò
void arrheap(int *arr) {
	int i;
	for (i = N / 2 - 1; i >= 0; i--) {
		adjustMaxHeap(arr, i, N);
	}
	SWAP(arr[0],arr[N-1]);
	for (i = N - 1; i >= 0; i--) {
		adjustMaxHeap(arr, 0, N - 1);
		swap(arr[0], arr[i - 1]);
	}
}
void arrCount(int *arr) {
	int i, j, k;
	int count[100] = {0};
	k = 0;
	for (i = 0; i < N; i++) {
		count[arr[i]]++;
	}
	for (i = 99; i >= 0; i--) {
		for (j = 0; j < count[i]; j++) {
			arr[k++] = i;
		}
	}
}