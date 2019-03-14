#include"word.h"
FILE *fp = NULL;
char *filename;

void* mallocz(int size) {
	void *ptr;
	ptr = malloc(size);
	if (!ptr&&size) {
		printf("内存分配失败");
	}
	memset(ptr, 0, size);
	return ptr;
}

void init() {
	line_num = 1;
	init_lex();
}

int main() {
	//printf("%d", TK_BEGIN);
	//char word[100];
	//char tmp;
	//FILE *fp = fopen("test.c", "r");
	//while (!feof(fp)) {
	//	tmp = fgetc(fp);
	//	if()
	//}
	/*char *a = "int";
	printf("%d", elf_half(a));*/
	fp = fopen("HelloWorld.txt", "rb");
	init();
	getch();
	test_lex();
	fclose(fp);
	printf("词法分析成功");
}