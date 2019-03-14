#include "sort.h"

int main()
{
	int *arr;
	int i;
	time_t start, end;
	arr = (int*)malloc(N * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	//arrPrint(arr);
	//arrInsert(arr);
	start = time(NULL);
	//arrQuick(arr,0,N-1);
	qsort(arr, N, sizeof(int), compare);
	//arrSelect(arr);
	end = time(NULL);
	printf("use time=%d\n", end - start);
	//arrPrint(arr);
	system("pause");
}