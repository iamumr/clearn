#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<setjmp.h>
jmp_buf envbuf;
 
void b() {
	printf("i am b func \n");
	longjmp(envbuf, 5);

}