#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 100
void input();//������û�����
void amend();//�޸��û���Ϣ����
void delete_client();//ɾ���û���Ϣ����
void demand_client();//�û���Ϣ��ѯ����
void collect_telephone();//�û���Ϣ���ܺ���
void save_client(struct telephone message);//���溯��
void demand_name();//���û�����ѯ
void demand_telephone();//���绰�����ѯ

struct telephone {
	char client_name[20];
	char client_address[30];
	char client_telephone[15];
};  //������û�����
void input() {
	struct telephone message;
	char reply='y';
	char save='y';
	while (reply=='y') {
		printf("�û�������");
		scanf("%s",message.client_name);

		printf("�绰���룺");
		scanf("%s",message.client_telephone);
		save_client(message);

		printf("Ҫ������?(y/n):");
		scanf(" %c",&reply);
	}
	printf("��������������˵�����\n");
	getchar();
	getchar();
} //���溯��
void save_client(struct telephone message) {
	FILE *fp;
	fp=fopen("message.dat","a+");
	if (fp!=NULL) {
		fwrite(&message,sizeof(struct telephone),1,fp);
	} else {
		printf("\n���ļ�ʱ���ִ��󣬰���������ء���\n");
		getchar();
		return;
	}
	fclose(fp);
} //�޸��û���Ϣ����
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
			printf("\n������Ҫ�޸ĵ�������");
			scanf("%s",amend_name);
			while ((fread(&message,size,1,fp))==1) {
				if ((strcmp(amend_name,message.client_name))==0) {
					found='y';
					break;
				}
			}
			if (found=='y') {
				printf("==========================================\n");
				printf("\n�û�����:%s\n",message.client_name);

				printf("\n�绰����:%s\n",message.client_telephone);
				printf("==========================================\n");
				printf("�޸��û���Ϣ��\n");
				printf("\n�û�������");
				scanf("%s",message.client_name);
				printf("\n�绰���룺");
				scanf("%s",message.client_telephone);
				printf("\nҪ������?(y/n):");
				scanf(" %c",&save);
				if (save=='y') {
					fseek(fp,-size,1);
					fwrite(&message,sizeof(struct telephone),1,fp);
				}
			} else {
				printf("�޴�����Ϣ!\n");
			}
		} else {
			printf("���ļ�ʱ���ִ��󣬰���������ء���\n");
			getchar();
			return;
		}
		fclose(fp);
		printf("Ҫ������?(y/n):");
		scanf(" %c",&reply);
	}
	printf("��������������˵�����\n");
	getchar();
	getchar();
} //ɾ���û���Ϣ����
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
			printf("\n������������");
			scanf("%s",delete_name);
			while ((fread(&temp_str,sizeof(struct telephone),1,fp))==1) {
				if ((strcmp(delete_name,temp_str.client_name))==0) {
					found='y';
					delete_str=temp_str;
				}//����Ҫɾ���ļ�¼
				else {
					message[i]=temp_str;
					i++;
				}//�������޹ؼ�¼��������
			}
		} else {
			printf("���ļ�ʱ���ִ��󣬰���������ء���\n");
			getchar();
			return;
		}
		fclose(fp);
		if (found=='y') {
			printf("==========================================\n");
			printf("�û�����:%s\n",delete_str.client_name);

			printf("�绰����:%s\n",delete_str.client_telephone);
			printf("==========================================\n");
		} else {
			printf("�޴�����Ϣ������������ء���\n");
			getchar();
			break;
		}
		printf("ȷ��Ҫɾ����?(y/n):");
		scanf(" %c",&confirm);
		if (confirm=='y') {
			fp=fopen("message.dat","w");
			if (fp!=NULL) {
				for(j=0; j<i; j++) {
					fwrite(&message[j],sizeof(struct telephone),1,fp);
				}
				printf("��¼��ɾ��!!!\n");
			} else {
				printf("���ļ�ʱ���ִ��󣬰���������ء���\n");
				getchar();
				return;
			}
			fclose(fp);
		}
		printf("Ҫ������?(y/n):");
		scanf(" %c",&reply);
	}
	printf("��������������˵�����\n");
	getchar();
}
//�û���Ϣ��ѯ����
void demand_client() {
	int choice=1;
	while (choice!=3) {
		system("cls");
		printf("�绰��ѯ�˵�\n");
		printf(" 1 ����ϵ��������ѯ\n");
		printf(" 2 ����ϵ�˵绰�����ѯ\n");
		printf(" 3 �������˵�\n");
		printf("��ѡ��(1-3):");
		scanf("%d%*c",&choice);
		if (choice>3) {
			printf("������1-6֮�������\n");
			printf("����������ز˵�����\n");
			getchar();
			continue;
		}
		if (choice==1) {
			demand_name();
		} else if (choice==2) {
			demand_telephone();
		}
	}
} //���û�����ѯ
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
			printf("\n������������");
			scanf("%s",amend_name);
			while ((fread(&message,sizeof(struct telephone),1,fp))==1) {
				if ((strcmp(amend_name,message.client_name))==0) {
					found='y';
					break;
				}
			}
			if (found=='y') {
				printf("==========================================\n");
				printf("�û�����:%s\n",message.client_name);
				printf("�绰����:%s\n",message.client_telephone);
				printf("==========================================\n");
			} else {
				printf("�޴�����Ϣ!\n");
			}
		} else {
			printf("���ļ�ʱ���ִ��󣬰���������ء���\n");
			getchar();
			return;
		}
		fclose(fp);
		printf("Ҫ������?(y/n):");
		scanf(" %c",&reply);
	}
	printf("��������������˵�����\n");
	getchar();
	getchar();
} //���绰�����ѯ
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
			printf("\n������绰���룺");
			scanf("%s",telephone);
			while ((fread(&message,sizeof(struct telephone),1,fp))==1) {
				if ((strcmp(telephone,message.client_telephone))==0) {
					found='y';
					break;
				}
			}
			if (found=='y') {
				printf("==========================================\n");
				printf("�û�����:%s\n",message.client_name);
				printf("�绰����:%s\n",message.client_telephone);
				printf("==========================================\n");
			} else {
				printf("�޴˵绰������й���Ϣ!\n");
			}
		} else {
			printf("���ļ�ʱ���ִ��󣬰���������ء���\n");
			getchar();
			return;
		}
		fclose(fp);
		printf("Ҫ������?(y/n):");
		scanf(" %c",&reply);
	}
	printf("��������������˵�����\n");
	getchar();
	getchar();
} //�û���Ϣ���ܺ���
void collect_telephone() {
	struct telephone message;
	FILE *fp;
	fp=fopen("message.dat","r");
	if (fp!=NULL) {
		system("cls");
		printf("\n�û�����\t\t�绰����\n");
		while ((fread(&message,sizeof(struct telephone),1,fp))==1) {
			printf("\n%-24s",message.client_name);
			printf("%-12s\n",message.client_telephone);
		}
	} else {
		printf("���ļ�ʱ���ִ��󣬰���������ء���\n");
		getchar();
		return;
	}
	fclose(fp);
	printf("��������������˵�����\n");
	getch();
}
int main() {
	char choice[10]="";
	int len=0;
	while (choice[0]!='7') {
		printf("\t==========�绰�������ѯϵͳ=============\n");
		printf("\t\t 1���������ϵ��\n");
		printf("\t\t 2���޸���ϵ����Ϣ\n");
		printf("\t\t 3��ɾ����ϵ����Ϣ\n");
		printf("\t\t 4����ϵ����Ϣ��ѯ\n");
		printf("\t\t 5����ϵ����Ϣ����\n");

		printf("\t\t 7���˳�\n");
		printf("\t=========================================\n");
		printf("��ѡ��(1-7):");
		scanf("%s",choice);
		len=strlen(choice);
		if (len>1) {
			printf("������1-6֮�������\n");
			printf("��������������˵�����\n");
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
