#include"word.h"
//重新分配动态数组容量
void dynarray_realloc(DynArray* parr, int new_size) {
	int capacity;
	void *data;
	capacity = parr->capacity;
	while (capacity < new_size) {
		capacity *= 2;
	}
	data = realloc(parr->data, capacity);
	if (!data) {
		printf("分配内存失败");
	}
	parr->capacity = capacity;
	parr->data = data;
}
//追加动态数组元素
void dynarray_add(DynArray* parr, void *data) {
	int count;
	count = parr->count + 1;
	if (count * sizeof(void*) > parr->capacity) {
		dynarray_realloc(parr, count * sizeof(void*));
	}
	parr->data[count - 1] = data;
	parr->count = count;
}
//初始化动态数组储存容量
void dynarray_init(DynArray* parr, int initsize) {
	if (parr != NULL) {
		parr->data = (void**)malloc(sizeof(char)*initsize);
		parr->count = 0;
		parr->capacity = initsize;
	}
}
//释放动态数组使用的内存空间
void dynarray_free(DynArray* parr) {
	void **p;
	for (p = parr->data; parr->count; ++p, --parr->count) {
		if (*p) {
			free(*p);
		}
		free(parr->data);
		parr->data = NULL;
	}
}
//动态数组元素查找
//key为数组的地址信息
int dynarray_search(DynArray* parr, int key) {
	int i;
	int **p;
	p = (int**)parr->data;//指针类型强转，便于比较
	for (i = 0; i < parr->count; i++) {
		if (key == **p) {
			return i;
		}
	}
	return -1;
}

