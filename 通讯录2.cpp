#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 100
void input();//添加新用户函数
void amend();//修改用户信息函数
void delete_client();//删除用户信息函数
void demand_client();//用户信息查询函数
void collect_telephone();//用户信息汇总函数
void save_client(struct telephone message);//保存函数
void demand_name();//按用户名查询
void demand_telephone();//按电话号码查询

struct telephone {
	char client_name[20];
	char client_address[30];
	char client_telephone[15];
};  //添加新用户函数
void input() {
	struct telephone message;
	char reply='y';
	char save='y';
	while (reply=='y') {
		printf("用户姓名：");
		scanf("%s",message.client_name);

		printf("电话号码：");
		scanf("%s",message.client_telephone);
		save_client(message);

		printf("要继续吗?(y/n):");
		scanf(" %c",&reply);
	}
	printf("按任意键返回主菜单……\n");
	getchar();
	getchar();
} //保存函数
void save_client(struct telephone message) {
	FILE *fp;
	fp=fopen("message.dat","a+");
	if (fp!=NULL) {
		fwrite(&message,sizeof(struct telephone),1,fp);
	} else {
		printf("\n打开文件时出现错误，按任意键返回……\n");
		getchar();
		return;
	}
	fclose(fp);
} //修改用户信息函数
void amend() {
	struct telephone message;
	FILE *fp;
	char amend_name[20];
	char reply='y';
	char found='y';
	char save='y';
	int size=sizeof(struct telephone);
	while (reply=='y') {
		found='n';
		fp=fopen("message.dat","r+w");
		if (fp!=NULL) {
			system("cls");
			printf("\n请输入要修改的姓名：");
			scanf("%s",amend_name);
			while ((fread(&message,size,1,fp))==1) {
				if ((strcmp(amend_name,message.client_name))==0) {
					found='y';
					break;
				}
			}
			if (found=='y') {
				printf("==========================================\n");
				printf("\n用户姓名:%s\n",message.client_name);

				printf("\n电话号码:%s\n",message.client_telephone);
				printf("==========================================\n");
				printf("修改用户信息：\n");
				printf("\n用户姓名：");
				scanf("%s",message.client_name);
				printf("\n电话号码：");
				scanf("%s",message.client_telephone);
				printf("\n要保存吗?(y/n):");
				scanf(" %c",&save);
				if (save=='y') {
					fseek(fp,-size,1);
					fwrite(&message,sizeof(struct telephone),1,fp);
				}
			} else {
				printf("无此人信息!\n");
			}
		} else {
			printf("打开文件时出现错误，按任意键返回……\n");
			getchar();
			return;
		}
		fclose(fp);
		printf("要继续吗?(y/n):");
		scanf(" %c",&reply);
	}
	printf("按任意键返回主菜单……\n");
	getchar();
	getchar();
} //删除用户信息函数
void delete_client() {
	struct telephone message[N];
	struct telephone temp_str;
	struct telephone delete_str;
	int i=0,j=0;
	char reply='y';
	char found='y';
	char confirm='y';
	char delete_name[20];
	FILE *fp;
	while (reply=='y') {
		system("cls");
		fp=fopen("message.dat","r");
		if (fp!=NULL) {
			i=0;
			found='n';
			printf("\n请输入姓名：");
			scanf("%s",delete_name);
			while ((fread(&temp_str,sizeof(struct telephone),1,fp))==1) {
				if ((strcmp(delete_name,temp_str.client_name))==0) {
					found='y';
					delete_str=temp_str;
				}//查找要删除的记录
				else {
					message[i]=temp_str;
					i++;
				}//将其它无关记录保存起来
			}
		} else {
			printf("打开文件时出现错误，按任意键返回……\n");
			getchar();
			return;
		}
		fclose(fp);
		if (found=='y') {
			printf("==========================================\n");
			printf("用户姓名:%s\n",delete_str.client_name);

			printf("电话号码:%s\n",delete_str.client_telephone);
			printf("==========================================\n");
		} else {
			printf("无此人信息，按任意键返回……\n");
			getchar();
			break;
		}
		printf("确定要删除吗?(y/n):");
		scanf(" %c",&confirm);
		if (confirm=='y') {
			fp=fopen("message.dat","w");
			if (fp!=NULL) {
				for(j=0; j<i; j++) {
					fwrite(&message[j],sizeof(struct telephone),1,fp);
				}
				printf("记录已删除!!!\n");
			} else {
				printf("打开文件时出现错误，按任意键返回……\n");
				getchar();
				return;
			}
			fclose(fp);
		}
		printf("要继续吗?(y/n):");
		scanf(" %c",&reply);
	}
	printf("按任意键返回主菜单……\n");
	getchar();
}
//用户信息查询函数
void demand_client() {
	int choice=1;
	while (choice!=3) {
		system("cls");
		printf("电话查询菜单\n");
		printf(" 1 按联系人姓名查询\n");
		printf(" 2 按联系人电话号码查询\n");
		printf(" 3 返回主菜单\n");
		printf("请选择(1-3):");
		scanf("%d%*c",&choice);
		if (choice>3) {
			printf("请输入1-6之间的整数\n");
			printf("按任意键返回菜单……\n");
			getchar();
			continue;
		}
		if (choice==1) {
			demand_name();
		} else if (choice==2) {
			demand_telephone();
		}
	}
} //按用户名查询
void demand_name() {
	struct telephone message;
	FILE *fp;
	char amend_name[20];
	char reply='y';
	char found='y';
	while (reply=='y') {
		found='n';
		fp=fopen("message.dat","r+w");
		if (fp!=NULL) {
			system("cls");
			printf("\n请输入姓名：");
			scanf("%s",amend_name);
			while ((fread(&message,sizeof(struct telephone),1,fp))==1) {
				if ((strcmp(amend_name,message.client_name))==0) {
					found='y';
					break;
				}
			}
			if (found=='y') {
				printf("==========================================\n");
				printf("用户姓名:%s\n",message.client_name);
				printf("电话号码:%s\n",message.client_telephone);
				printf("==========================================\n");
			} else {
				printf("无此人信息!\n");
			}
		} else {
			printf("打开文件时出现错误，按任意键返回……\n");
			getchar();
			return;
		}
		fclose(fp);
		printf("要继续吗?(y/n):");
		scanf(" %c",&reply);
	}
	printf("按任意键返回主菜单……\n");
	getchar();
	getchar();
} //按电话号码查询
void demand_telephone() {
	struct telephone message;
	FILE *fp;
	char telephone[20];
	char reply='y';
	char found='y';
	while (reply=='y') {
		found='n';
		fp=fopen("message.dat","r+w");
		if (fp!=NULL) {
			system("cls");
			printf("\n请输入电话号码：");
			scanf("%s",telephone);
			while ((fread(&message,sizeof(struct telephone),1,fp))==1) {
				if ((strcmp(telephone,message.client_telephone))==0) {
					found='y';
					break;
				}
			}
			if (found=='y') {
				printf("==========================================\n");
				printf("用户姓名:%s\n",message.client_name);
				printf("电话号码:%s\n",message.client_telephone);
				printf("==========================================\n");
			} else {
				printf("无此电话号码的有关信息!\n");
			}
		} else {
			printf("打开文件时出现错误，按任意键返回……\n");
			getchar();
			return;
		}
		fclose(fp);
		printf("要继续吗?(y/n):");
		scanf(" %c",&reply);
	}
	printf("按任意键返回主菜单……\n");
	getchar();
	getchar();
} //用户信息汇总函数
void collect_telephone() {
	struct telephone message;
	FILE *fp;
	fp=fopen("message.dat","r");
	if (fp!=NULL) {
		system("cls");
		printf("\n用户姓名\t\t电话号码\n");
		while ((fread(&message,sizeof(struct telephone),1,fp))==1) {
			printf("\n%-24s",message.client_name);
			printf("%-12s\n",message.client_telephone);
		}
	} else {
		printf("打开文件时出现错误，按任意键返回……\n");
		getchar();
		return;
	}
	fclose(fp);
	printf("按任意键返回主菜单……\n");
	getch();
}
int main() {
	char choice[10]="";
	int len=0;
	while (choice[0]!='7') {
		printf("\t==========电话本号码查询系统=============\n");
		printf("\t\t 1、添加新联系人\n");
		printf("\t\t 2、修改联系人信息\n");
		printf("\t\t 3、删除联系人信息\n");
		printf("\t\t 4、联系人信息查询\n");
		printf("\t\t 5、联系人信息汇总\n");

		printf("\t\t 7、退出\n");
		printf("\t=========================================\n");
		printf("请选择(1-7):");
		scanf("%s",choice);
		len=strlen(choice);
		if (len>1) {
			printf("请输入1-6之间的整数\n");
			printf("按任意键返回主菜单……\n");
			getchar();
			getchar();
			continue;
		}
		switch (choice[0]) {
			case '1':
				input();
				break;
			case '2':
				amend();
				break;
			case '3':
				delete_client();
				break;
			case '4':
				demand_client();
				break;
			case '5':
				collect_telephone();
				break;
			default:
				break;

		}
	}
}
