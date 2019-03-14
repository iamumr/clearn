#include"student.h"
void print_desktop_mangage() {
	system("cls");
	printf("**************************************************************************************************************\n");
	printf("********************Student     Information   Mangement    System*********************************************\n");
	printf("**************************************************************************************************************\n");
	printf("                    1、查找学生信息                                                                           \n");
	printf("                    2、增加学生信息                                                                           \n");
	printf("                    3、更新学生信息                                                                           \n");
	printf("                    4、删除学生信息                                                                           \n");
	printf("                    5、增加管理账户                                                                           \n");
	printf("                    6、更新管理账户                                                                           \n");
	printf("                    7、删除管理账户                                                                           \n");
	printf("                    8、搜索管理账户                                                                           \n");
	printf("                    9、退出系统                                                                               \n");
	printf("请输入选项序号：");

}
void print_desktop_stu() {
	system("cls");
	printf("**************************************************************************************************************\n");
	printf("********************Student     Information   Mangement    System*********************************************\n");
	printf("**************************************************************************************************************\n");
	printf("                    1、查找学生信息                                                                           \n");
	printf("请输入选项序号：");

}
//PUSR_ACCOUNT User_head = NULL;
//PSTU_INFO Stu_head = NULL;
//初始化用户表
void flush_usr(PUSR_ACCOUNT *User_head) {
	FILE *fp = fopen("usr_account.txt", "r");
	char usr[20], pwd[20]; int role;
	if (NULL == fp) { printf("系统故障，无法登入，请联系管理员。"); return; }
	while (!feof(fp)) {
		fscanf(fp, "%s%s%d", &usr, &pwd, &role);
		head_insert_account(User_head,usr, pwd, role);
	}
}
//初始化学生表
void flush_stu(PSTU_INFO *Stu_head) {
	FILE *fp = fopen("usr_info.txt", "r");
	char name[20]; int id;double score[3];
	if (NULL == fp) { printf("系统故障，无法登入，请联系管理员。"); return; }
	int test = feof(fp);
	while (feof(fp)==0) {
		fscanf(fp, "%d%s%lf%lf%lf", &id, &name, &score[0],&score[1],&score[2]);
		PSTU_INFO new;
		new = (PSTU_INFO)malloc(sizeof(STU_INFO));
		memset(new, 0, sizeof(STU_INFO));
		strcpy(new->stu_name, name); 
		new->stu_id = id;
		new->stu_scr[0] = score[0];
		new->stu_scr[1] = score[1];
		new->stu_scr[2] = score[2];
		if (NULL == *Stu_head) {
			*Stu_head = new;
		}
		else {
			new->next = *Stu_head;
			*Stu_head = new;
		}
	}
}
//添加账户
void head_insert_account(PUSR_ACCOUNT *phead, char *usr,char *pwd,int role) {
	PUSR_ACCOUNT new;
	new = (PUSR_ACCOUNT)malloc(sizeof(USR_ACCOUNT));
	memset(new, 0, sizeof(USHRT_MAX));
	new->role = role;
	new->next = NULL;
	strcpy(new->username, usr);
	strcpy(new->passwd, pwd);
	if (NULL == *phead) {
		*phead = new;
	}
	else {
		new->next = *phead;
		*phead = new;
	}
}
//写入用户文件
void write_file_usr(PUSR_ACCOUNT head) {
	PUSR_ACCOUNT p = head;
	FILE *fp = fopen("usr_account.txt", "w+");
	while (p->next != NULL) {
		fprintf(fp, "%s\t%s\t%d\n", p->username, p->passwd, p->role);
		p = p->next;
	}
	fprintf(fp, "%s\t%s\t%d", p->username, p->passwd, p->role);
	fclose(fp);
}
//写入学生文件
void write_file_stu(PSTU_INFO head) {
	FILE *fp = fopen("usr_info.txt", "w+");
	PSTU_INFO p1 = head;
	while (p1->next != NULL) {
		fprintf(fp, "%d\t%s\t%lf\t%lf\t%lf\n", p1->stu_id, p1->stu_name, p1->stu_scr[0], p1->stu_scr[1], p1->stu_scr[2]);
		p1 = p1->next;
	}
	fprintf(fp, "%d\t%s\t%lf\t%lf\t%lf", p1->stu_id, p1->stu_name, p1->stu_scr[0], p1->stu_scr[1], p1->stu_scr[2]);
	fclose(fp);
}
//添加操作用户
void add_usr_account(PUSR_ACCOUNT *head) {
	char usr[20], pwd[20];
	int role;
	printf("请输入新添加用户名：");
	scanf("%s", &usr);
	printf("请输入新添加密码：");
	scanf("%s", &pwd);
	printf("请输入新添加权限：（1：管理员，0、学生）");
	scanf("%d", &role);
	while (role != 0 && role != 1) {
		printf("输入错误，请重新输入权限设定");
		scanf("%d", &role);
	}
	PUSR_ACCOUNT p1 = *head;
	while (p1 != NULL) {
		if (strcmp(p1->username, usr) == 0) {
			printf("用户名已被占用");
			return;
		}
		else {
			p1 = p1->next;
		}
	}
	head_insert_account(head, usr, pwd, role);
}
//用户登入
int usr_login(PUSR_ACCOUNT* head,PUSR_ACCOUNT* now) {
	char usr[20], pwd[20];
	char p;
	int i = 0;
	printf("输入用户名：");
	scanf("%s", &usr);
	printf("输入密码：");
	while (1) {
		p = getch();
		if (p == '\r') { break; }
		if (p == '\b') {
			printf("\b \b");
			i--;
			pwd[i] = '\0';
			continue;
		}
		else {
			pwd[i++] = p;
		}
		printf("*");

	}
	pwd[i] = '\0';
	PUSR_ACCOUNT p1 = *head;
	while (p1 != NULL) {
		if (strcmp(usr, p1->username) == 0) {
			if (strcmp(pwd, p1->passwd) == 0) {
				*now = p1;
				return 1;
			}
			else {
				printf("\n密码错误，请重试！\n");
				return 0;
			}
		}
		else {
			p1 = p1->next;
		}
	}
	printf("\n用户名不存在！请重新输入！\n");
	return 0;
}
//增加学生
void add_student_information(PSTU_INFO* head) {
	char name[20];
	double score[3];
	int id;
	PSTU_INFO new;
	new = (PSTU_INFO)malloc(sizeof(STU_INFO));
	memset(new, 0,sizeof(STU_INFO));
	printf("请输入学生学号:");
	scanf("%d", &id);
	new->stu_id = id;
	printf("请输入学生姓名：");
	scanf("%s", &name);
	strcpy(new->stu_name, name);
	printf("请输入学生三科考试成绩：");
	scanf("%lf%lf%lf", &score[0], &score[1], &score[2]);
	new->stu_scr[0] = score[0];
	new->stu_scr[1] = score[1];
	new->stu_scr[2] = score[2];
	PSTU_INFO p1, p2;
	p1 = *head; p2 = *head;
	if (NULL == *head) {
		*head = new;
		printf("新增学生成功");
		return;
	}
	else if (p1->stu_id==new->stu_id) {
		printf("学号重复，请重试！");
		return;
	}
	else if (new->stu_id<p1->stu_id) {
		new->next = *head;
		*head = new;
		printf("新增学生成功");
		return;
	}
	else {
		while (p1 != NULL) {

			if (new->stu_id==p1->stu_id) {
				printf("学号重复，请重试！");
				return;
			}
			else if (new->stu_id<p1->stu_id) {
				new->next = p1;
				p2->next = new;
				printf("新增学生成功");
				return;
			}
			p2 = p1;
			p1 = p1->next;
		}
		if (NULL == p1) {
			p2->next = new;
			printf("新增学生成功");
			return;
		}
	}
	printf("系统故障，请通知管理员！（2）");
}
//删除学生
void del_student_information(PSTU_INFO* Stu_head) {
	int num = 0;
	printf("请输入要删除的学生的学号：");
	scanf("%d", &num);
	PSTU_INFO p1 = *Stu_head;
	PSTU_INFO p2 = *Stu_head;
	//while (p1 != NULL) {
		if ((*Stu_head)->stu_id == num) {
			*Stu_head = (*Stu_head)->next;
			printf("学生信息已删除。");
			return;
		}
		else {
			p1 = p1->next;
			while(p1!=NULL){
			if (p1->stu_id == num) {
				p2->next = p1->next;
				free(p1);
				printf("学生信息已删除。");
				return;
			}
			p1 = p1->next;
			p2 = p2 ->next;
		}
	}
		printf("输入的学号不存在！");
}
//修改学生信息
void edit_student_information(PSTU_INFO* Stu_head) {
	int num = 0;
	double score[3];
	char name[20];
	printf("请输入要修改的学生的学号：");
	scanf("%d", &num);
	printf("请输入学生姓名：");
	scanf("%s", &name);
	printf("请输入学生三科考试成绩：");
	scanf("%lf%lf%lf", &score[0], &score[1], &score[2]);
	PSTU_INFO p1 = *Stu_head;
	//PSTU_INFO p2 = *Stu_head;
	while (p1 != NULL) {
		if (p1->stu_id == num) {
			(p1)->stu_scr[0] = score[0];
			(p1)->stu_scr[1] = score[1];
			(p1)->stu_scr[2] = score[2];
			strcpy(p1->stu_name, name);
			printf("学生信息已更新。");
			return;
		}
		else {
			p1 = p1->next;
		}
	}
	printf("输入的学号不存在！");
}
//搜索学生信息
void search_student_information(PSTU_INFO* Stu_head,int n) {
	if (n == 0) {
		PSTU_INFO p1 = *Stu_head;
		if (p1 == NULL) {
			printf("没有数据");
			return;
		}
		while (p1->next != NULL) {
			fprintf(stdout, "%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p1->stu_id, p1->stu_name, p1->stu_scr[0], p1->stu_scr[1], p1->stu_scr[2]);
			p1 = p1->next;
		}
		fprintf(stdout, "%d\t%s\t%.2lf\t%.2lf\t%.2lf", p1->stu_id, p1->stu_name, p1->stu_scr[0], p1->stu_scr[1], p1->stu_scr[2]);
		return;
	}
	else if (1 == n) {
		char name[20];
		printf("请输入要查找的学生姓名:");
		scanf("%s", &name);
		PSTU_INFO p2 = *Stu_head;
		if (p2 == NULL) {
			printf("没有数据");
			return;
		}
		while (p2) {
			if (strcmp(p2->stu_name, name) == 0) {
				fprintf(stdout, "%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p2->stu_id, p2->stu_name, p2->stu_scr[0], p2->stu_scr[1], p2->stu_scr[2]);
				return;
			}
			else {
				p2 = p2->next;
			}
		}
		printf("输入姓名不存在!");
	}
	else if (2 == n) {
		int id;
		printf("请输入学号：");
		scanf("%d", &id);
		PSTU_INFO p3 = *Stu_head;
		while (p3) {
			if (p3->stu_id == id) {
				fprintf(stdout, "%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p3->stu_id, p3->stu_name, p3->stu_scr[0], p3->stu_scr[1], p3->stu_scr[2]);
				return;
			}
			else {
				p3 = p3->next;
			}
		}
		printf("学号不存在！");

	}
	else {
		printf("系统错误，请联系开发人员!");
	}
	
}
//搜索用户
void search_usr_account(PUSR_ACCOUNT* Usr_head) {
	char usr[20];
	printf("请输入用户名:");
	scanf("%s", usr);
	PUSR_ACCOUNT p1 = *Usr_head;
	while (p1) {
		if (strcmp(p1->username, usr) == 0) {
			system("cls");
			printf("%s\t%s\t%d", p1->username, p1->passwd, p1->role);
			return;
		}
		else {
			p1 = p1->next;
		}
	}
	printf("该用户名不存在！");
}
//修改操作用户信息
void edit_usr_account(PUSR_ACCOUNT* Usr_head) {
	char usr[20];
	int role;
	char pwd[20];
	system("cls");
	printf("请输入要修改的用户名：");
	scanf("%s", &usr);
	printf("请输入要修改的密码：");
	scanf("%s", &pwd);
	printf("请输入要修改的权限：");
	scanf("%d", &role);
	PUSR_ACCOUNT p = *Usr_head;
	while (p) {
		if (strcmp(p->username, usr) == 0) {
			p->role = role;
			strcpy(p->passwd, pwd);
			printf("用户信息已更新！");
			return;
		}
		else {
			p = p->next;
		}
	}
	printf("不存在该用户！");
	return;
}
//删除操作用户
void del_usr_account(PUSR_ACCOUNT* Usr_head) {
	char usr[20];
	system("cls");
	printf("请输入要删除的用户名：");
	scanf("%s", &usr);
	PUSR_ACCOUNT p1 = *Usr_head;
	PUSR_ACCOUNT p2 = *Usr_head;
	if (strcmp((*Usr_head)->username, usr) == 0) {
		*Usr_head = (*Usr_head)->next;
		printf("账户删除成功");
		return;
	}
	else {
		p1 = p1->next;
	}
	while (p1) {
		if (strcmp(p1->username, usr) == 0) {
			p2->next = p1->next;
			free(p1);
			printf("账户删除成功");
			return;
		}
		else {
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	printf("不存在该用户！");
	return;
}
//打印查找学生信息二级目录
void print_search_stu_menu(PUSR_ACCOUNT* now) {
	if (1 == (*now)->role) {
		system("cls");
		printf("                    0、查找全部学生信息                                                                           \n");
		printf("                    1、通过姓名查找学生信息                                                                           \n");
		printf("                    2、通过学号查找学生信息                                                                           \n");
		printf("                    3、返回主菜单                                                                           \n");
		printf("请输入选项序号：");

	}
	else {
		system("cls");
		printf("                    1、通过姓名查找学生信息                                                                           \n");
		printf("                    2、通过学号查找学生信息                                                                           \n");
		printf("                    3、返回主菜单                                                                           \n");
		printf("请输入选项序号：");

	}
}