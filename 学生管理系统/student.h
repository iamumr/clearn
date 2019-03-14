#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct usr_account { //登入账户信息保存链表
	char username[20];
	char passwd[20];
	int role;
	struct usr_acount *next;
}USR_ACCOUNT,*PUSR_ACCOUNT;
typedef struct stu_info
{
	int stu_id;
	char stu_name[20];
	double stu_scr[3];
	struct stu_info *next;
}STU_INFO,*PSTU_INFO;
//PUSR_ACCOUNT User_head=NULL;
//PSTU_INFO Stu_head = NULL;
void print_desktop_mangage();
void print_desktop_stu();
int usr_login(PUSR_ACCOUNT*, PUSR_ACCOUNT* );
void head_insert_account(PUSR_ACCOUNT *, char *, char *, int);
void write_file_usr(PUSR_ACCOUNT);
void flush_usr(PUSR_ACCOUNT *);
void flush_stu(PSTU_INFO *);
void add_student_information(PSTU_INFO*);
void write_file_stu(PSTU_INFO);
void del_student_information(PSTU_INFO*);
void edit_student_information(PSTU_INFO*);
void search_student_information(PSTU_INFO*, int);
void search_usr_account(PUSR_ACCOUNT*);
void edit_usr_account(PUSR_ACCOUNT*); 
void del_usr_account(PUSR_ACCOUNT*);
void print_search_stu_menu(PUSR_ACCOUNT*);
void add_usr_account(PUSR_ACCOUNT *);