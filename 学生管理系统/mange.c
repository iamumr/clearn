#include"student.h"
void print_desktop_mangage() {
	system("cls");
	printf("**************************************************************************************************************\n");
	printf("********************Student     Information   Mangement    System*********************************************\n");
	printf("**************************************************************************************************************\n");
	printf("                    1������ѧ����Ϣ                                                                           \n");
	printf("                    2������ѧ����Ϣ                                                                           \n");
	printf("                    3������ѧ����Ϣ                                                                           \n");
	printf("                    4��ɾ��ѧ����Ϣ                                                                           \n");
	printf("                    5�����ӹ����˻�                                                                           \n");
	printf("                    6�����¹����˻�                                                                           \n");
	printf("                    7��ɾ�������˻�                                                                           \n");
	printf("                    8�����������˻�                                                                           \n");
	printf("                    9���˳�ϵͳ                                                                               \n");
	printf("������ѡ����ţ�");

}
void print_desktop_stu() {
	system("cls");
	printf("**************************************************************************************************************\n");
	printf("********************Student     Information   Mangement    System*********************************************\n");
	printf("**************************************************************************************************************\n");
	printf("                    1������ѧ����Ϣ                                                                           \n");
	printf("������ѡ����ţ�");

}
//PUSR_ACCOUNT User_head = NULL;
//PSTU_INFO Stu_head = NULL;
//��ʼ���û���
void flush_usr(PUSR_ACCOUNT *User_head) {
	FILE *fp = fopen("usr_account.txt", "r");
	char usr[20], pwd[20]; int role;
	if (NULL == fp) { printf("ϵͳ���ϣ��޷����룬����ϵ����Ա��"); return; }
	while (!feof(fp)) {
		fscanf(fp, "%s%s%d", &usr, &pwd, &role);
		head_insert_account(User_head,usr, pwd, role);
	}
}
//��ʼ��ѧ����
void flush_stu(PSTU_INFO *Stu_head) {
	FILE *fp = fopen("usr_info.txt", "r");
	char name[20]; int id;double score[3];
	if (NULL == fp) { printf("ϵͳ���ϣ��޷����룬����ϵ����Ա��"); return; }
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
//����˻�
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
//д���û��ļ�
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
//д��ѧ���ļ�
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
//��Ӳ����û�
void add_usr_account(PUSR_ACCOUNT *head) {
	char usr[20], pwd[20];
	int role;
	printf("������������û�����");
	scanf("%s", &usr);
	printf("��������������룺");
	scanf("%s", &pwd);
	printf("�����������Ȩ�ޣ���1������Ա��0��ѧ����");
	scanf("%d", &role);
	while (role != 0 && role != 1) {
		printf("�����������������Ȩ���趨");
		scanf("%d", &role);
	}
	PUSR_ACCOUNT p1 = *head;
	while (p1 != NULL) {
		if (strcmp(p1->username, usr) == 0) {
			printf("�û����ѱ�ռ��");
			return;
		}
		else {
			p1 = p1->next;
		}
	}
	head_insert_account(head, usr, pwd, role);
}
//�û�����
int usr_login(PUSR_ACCOUNT* head,PUSR_ACCOUNT* now) {
	char usr[20], pwd[20];
	char p;
	int i = 0;
	printf("�����û�����");
	scanf("%s", &usr);
	printf("�������룺");
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
				printf("\n������������ԣ�\n");
				return 0;
			}
		}
		else {
			p1 = p1->next;
		}
	}
	printf("\n�û��������ڣ����������룡\n");
	return 0;
}
//����ѧ��
void add_student_information(PSTU_INFO* head) {
	char name[20];
	double score[3];
	int id;
	PSTU_INFO new;
	new = (PSTU_INFO)malloc(sizeof(STU_INFO));
	memset(new, 0,sizeof(STU_INFO));
	printf("������ѧ��ѧ��:");
	scanf("%d", &id);
	new->stu_id = id;
	printf("������ѧ��������");
	scanf("%s", &name);
	strcpy(new->stu_name, name);
	printf("������ѧ�����ƿ��Գɼ���");
	scanf("%lf%lf%lf", &score[0], &score[1], &score[2]);
	new->stu_scr[0] = score[0];
	new->stu_scr[1] = score[1];
	new->stu_scr[2] = score[2];
	PSTU_INFO p1, p2;
	p1 = *head; p2 = *head;
	if (NULL == *head) {
		*head = new;
		printf("����ѧ���ɹ�");
		return;
	}
	else if (p1->stu_id==new->stu_id) {
		printf("ѧ���ظ��������ԣ�");
		return;
	}
	else if (new->stu_id<p1->stu_id) {
		new->next = *head;
		*head = new;
		printf("����ѧ���ɹ�");
		return;
	}
	else {
		while (p1 != NULL) {

			if (new->stu_id==p1->stu_id) {
				printf("ѧ���ظ��������ԣ�");
				return;
			}
			else if (new->stu_id<p1->stu_id) {
				new->next = p1;
				p2->next = new;
				printf("����ѧ���ɹ�");
				return;
			}
			p2 = p1;
			p1 = p1->next;
		}
		if (NULL == p1) {
			p2->next = new;
			printf("����ѧ���ɹ�");
			return;
		}
	}
	printf("ϵͳ���ϣ���֪ͨ����Ա����2��");
}
//ɾ��ѧ��
void del_student_information(PSTU_INFO* Stu_head) {
	int num = 0;
	printf("������Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%d", &num);
	PSTU_INFO p1 = *Stu_head;
	PSTU_INFO p2 = *Stu_head;
	//while (p1 != NULL) {
		if ((*Stu_head)->stu_id == num) {
			*Stu_head = (*Stu_head)->next;
			printf("ѧ����Ϣ��ɾ����");
			return;
		}
		else {
			p1 = p1->next;
			while(p1!=NULL){
			if (p1->stu_id == num) {
				p2->next = p1->next;
				free(p1);
				printf("ѧ����Ϣ��ɾ����");
				return;
			}
			p1 = p1->next;
			p2 = p2 ->next;
		}
	}
		printf("�����ѧ�Ų����ڣ�");
}
//�޸�ѧ����Ϣ
void edit_student_information(PSTU_INFO* Stu_head) {
	int num = 0;
	double score[3];
	char name[20];
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d", &num);
	printf("������ѧ��������");
	scanf("%s", &name);
	printf("������ѧ�����ƿ��Գɼ���");
	scanf("%lf%lf%lf", &score[0], &score[1], &score[2]);
	PSTU_INFO p1 = *Stu_head;
	//PSTU_INFO p2 = *Stu_head;
	while (p1 != NULL) {
		if (p1->stu_id == num) {
			(p1)->stu_scr[0] = score[0];
			(p1)->stu_scr[1] = score[1];
			(p1)->stu_scr[2] = score[2];
			strcpy(p1->stu_name, name);
			printf("ѧ����Ϣ�Ѹ��¡�");
			return;
		}
		else {
			p1 = p1->next;
		}
	}
	printf("�����ѧ�Ų����ڣ�");
}
//����ѧ����Ϣ
void search_student_information(PSTU_INFO* Stu_head,int n) {
	if (n == 0) {
		PSTU_INFO p1 = *Stu_head;
		if (p1 == NULL) {
			printf("û������");
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
		printf("������Ҫ���ҵ�ѧ������:");
		scanf("%s", &name);
		PSTU_INFO p2 = *Stu_head;
		if (p2 == NULL) {
			printf("û������");
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
		printf("��������������!");
	}
	else if (2 == n) {
		int id;
		printf("������ѧ�ţ�");
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
		printf("ѧ�Ų����ڣ�");

	}
	else {
		printf("ϵͳ��������ϵ������Ա!");
	}
	
}
//�����û�
void search_usr_account(PUSR_ACCOUNT* Usr_head) {
	char usr[20];
	printf("�������û���:");
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
	printf("���û��������ڣ�");
}
//�޸Ĳ����û���Ϣ
void edit_usr_account(PUSR_ACCOUNT* Usr_head) {
	char usr[20];
	int role;
	char pwd[20];
	system("cls");
	printf("������Ҫ�޸ĵ��û�����");
	scanf("%s", &usr);
	printf("������Ҫ�޸ĵ����룺");
	scanf("%s", &pwd);
	printf("������Ҫ�޸ĵ�Ȩ�ޣ�");
	scanf("%d", &role);
	PUSR_ACCOUNT p = *Usr_head;
	while (p) {
		if (strcmp(p->username, usr) == 0) {
			p->role = role;
			strcpy(p->passwd, pwd);
			printf("�û���Ϣ�Ѹ��£�");
			return;
		}
		else {
			p = p->next;
		}
	}
	printf("�����ڸ��û���");
	return;
}
//ɾ�������û�
void del_usr_account(PUSR_ACCOUNT* Usr_head) {
	char usr[20];
	system("cls");
	printf("������Ҫɾ�����û�����");
	scanf("%s", &usr);
	PUSR_ACCOUNT p1 = *Usr_head;
	PUSR_ACCOUNT p2 = *Usr_head;
	if (strcmp((*Usr_head)->username, usr) == 0) {
		*Usr_head = (*Usr_head)->next;
		printf("�˻�ɾ���ɹ�");
		return;
	}
	else {
		p1 = p1->next;
	}
	while (p1) {
		if (strcmp(p1->username, usr) == 0) {
			p2->next = p1->next;
			free(p1);
			printf("�˻�ɾ���ɹ�");
			return;
		}
		else {
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	printf("�����ڸ��û���");
	return;
}
//��ӡ����ѧ����Ϣ����Ŀ¼
void print_search_stu_menu(PUSR_ACCOUNT* now) {
	if (1 == (*now)->role) {
		system("cls");
		printf("                    0������ȫ��ѧ����Ϣ                                                                           \n");
		printf("                    1��ͨ����������ѧ����Ϣ                                                                           \n");
		printf("                    2��ͨ��ѧ�Ų���ѧ����Ϣ                                                                           \n");
		printf("                    3���������˵�                                                                           \n");
		printf("������ѡ����ţ�");

	}
	else {
		system("cls");
		printf("                    1��ͨ����������ѧ����Ϣ                                                                           \n");
		printf("                    2��ͨ��ѧ�Ų���ѧ����Ϣ                                                                           \n");
		printf("                    3���������˵�                                                                           \n");
		printf("������ѡ����ţ�");

	}
}