#include"student.h"
PUSR_ACCOUNT User_head = NULL;
PSTU_INFO Stu_head = NULL;
PUSR_ACCOUNT now=NULL;
int main() {
	int tmp;
	flush_usr(&User_head); 
	flush_stu(&Stu_head);
	tmp = usr_login(&User_head, &now);
	while (0 == tmp) { tmp=usr_login(&User_head, &now); }
labelA:
	if (0 == now->role) {
		print_desktop_stu();
	}
	else {
		print_desktop_mangage();
	}
labelC:
	scanf("%d", &tmp);
	if (1 == tmp) {
		print_search_stu_menu(&now);
labelB:
		scanf("%d", &tmp);
		if (0 == tmp) {
			if (now->role == 1) {
				search_student_information(&Stu_head, tmp);
				system("pause");
				goto labelA;
			}
		}
		else if(1==tmp||2==tmp){
			search_student_information(&Stu_head, tmp);
			system("pause");
			goto labelA;
		}
		else if (3 == tmp) {
			goto labelA;
		}
		else{
			system("cls");
			printf("序号输入错误,请重新输入：");
			goto labelB;
		}
	}
	else if (2 == tmp) {
		system("cls");
		add_student_information(&Stu_head);
		write_file_stu(Stu_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if (3 == tmp) {
		system("cls");
		edit_student_information(&Stu_head);
		write_file_stu(Stu_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if (4 == tmp) {
		system("cls");
		del_student_information(&Stu_head);
		write_file_stu(Stu_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if (5 == tmp) {
		system("cls");
		add_usr_account(&User_head);
		write_file_usr(User_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if(6==tmp){
		system("cls");
		edit_usr_account(&User_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if (7 == tmp) {
		system("cls");
		del_usr_account(&User_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if (8 == tmp) {
		system("cls");
		search_usr_account(&User_head);
		system("pause");
		system("cls");
		goto labelA;
	}
	else if (9 == tmp) {
		return;
	}
	else {
		system("cls");
		printf("输入指令有误，请重新输入");
		goto labelC;
	}
	
	//add_student_information(&Stu_head);
	//add_student_information(&Stu_head);
	//add_student_information(&Stu_head);
	//write_file_stu(Stu_head);
	//del_student_information(&Stu_head);
	/*edit_usr_account(&User_head);
	del_usr_account(&User_head);
	search_usr_account(&User_head);
	search_student_information(&Stu_head, 0);
	edit_student_information(&Stu_head);*/
	//while (Stu_head != NULL) {
	//	printf("%.2f ", Stu_head->stu_scr[0]);
	//	Stu_head = Stu_head->next;
	//}

	
	//head_insert_account(&User_head, "root", "root", 1);
	//head_insert_account(&User_head, "rt", "root", 1);
	//head_insert_account(&User_head, "liguo", "root", 0);
	//write_file_usr(User_head);
}