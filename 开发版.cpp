#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct stu {
	char name[20], student_id[20], yuan_xi[20], class_num[20], fudaoyuan[20], home[20], tel[20];
	float sco;
};
vector<stu> v;
bool cmp1 (stu x, stu y) {
	return strcmp(x.student_id,y.student_id) == 1;
}
bool cmp2 (stu x, stu y) {
	return strcmp(x.student_id,y.student_id) == -1;
}
bool cmp3 (stu x, stu y) {
	return x.student_id > y.student_id;
}
bool cmp4 (stu x, stu y) {
	return x.student_id < y.student_id;
}
void out(stu a) {
	printf("ѧ�ţ�%s\t",a.student_id);
	printf("������%s\t",a.name);
	printf("Ժϵ��%s\t",a.yuan_xi);
	printf("�༶��%s\t",a.class_num);
	printf("����Ա:%s\t",a.fudaoyuan);
	printf("������%s\t",a.home);
	printf("�绰��%s\t",a.tel);
	printf("��Ȩ�ɼ���%f\n",a.sco);
}
void get() {
	FILE *fp;
	struct stu a;
	fp = fopen("student.dat","r");
	while(fread(&a,sizeof(struct stu),1,fp) == 1) {
		v.push_back(a);
	}
	fclose(fp);
}
void save() {
	FILE *fp;
	struct stu a;
	int size = sizeof(stu);
	fp = fopen("student.dat","w");
	fclose(fp);
	fp = fopen("student.dat","a+");
	for(stu i : v) {
		fwrite(&i,sizeof(struct stu),1,fp);
	}
	fclose(fp);
}
void add_student() {

	stu a;
	cout << "���� ѧ�� Ժϵ �༶ ��Ȩ�ɼ� ���� �绰\n";
	cout << "��*��Ϊ������������#����\n";

	cout << "����������\n";
	scanf("%s",a.name);

	cout << "����ѧ�ţ�\n";
	scanf("%s",a.student_id);

	cout << "����Ժϵ��\n";
	scanf("%s",a.yuan_xi);

	cout << "����༶��\n";
	scanf("%s",a.class_num);

	cout << "���븨��Ա��\n";
	scanf("%s",a.fudaoyuan);

	cout << "���뻧�������磺�����Ͼ�)��\n";
	scanf("%s",a.home);

	cout << "����绰��\n";
	scanf("%s",a.tel);

	cout << "�����Ȩ�ɼ�������һλС������\n";
	cin >> a.sco;

	v.push_back(a);
}
void delete_student() {
	string s;
	cout  << "������ѧ�ţ�";
	cin >> s;
	for(int i = 0; i < v.size(); i++) {
		if(s == v[i].student_id) {
			out(v[i]);
			cout << "ȷ��ɾ����y,��ɾ����n:";
			char c;
			cin >> c;
			if(c == 'y')	v.erase(v.begin() + i);
			cout << "��ɾ��\n";
			break;
		}
	}
	cout << "���޴���\n";
}
void modify_student() {
	char s[20], news[20];
	float newsco;
	cout  << "������ѧ�ţ�";
	scanf("%s",s);
	for(int i = 0; i < v.size(); i++) {
		if(s == v[i].student_id) {
			stu a = v[i];
			out(v[i]);
			cout << "ѧ��Ϊ�����޸���!!!\n" ;
			char c;
			cout << "�޸�����y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "������������:\n";
				scanf("%s",news);
				strcpy(a.name, news);
			}
			cout << "�޸�Ժϵy/n?:\n";

			if(c == 'y') {
				cout << "��������Ժϵ:\n";
				scanf("%s",news);
				strcpy(a.yuan_xi , news);
			}

			cout << "�޸İ༶y/n?:\n";

			if(c == 'y') {
				cout << "�������°༶:\n";
				scanf("%s",news);
				strcpy(a.class_num, news);
			}

			cout << "�޸ĸ���Աy/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������¸���Ա:\n";
				scanf("%s",news);
				strcpy(a.fudaoyuan, news);
			}

			cout << "�޸Ļ���y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������»���:\n";
				scanf("%s",news);
				strcpy(a.home , news);
			}
			cout << "�޸ĵ绰y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������µ绰:\n";
				scanf("%s",news);
				strcpy(a.tel , news);
			}
			cout << "�޸ļ�Ȩ�ɼ�y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������¼�Ȩ�ɼ�:\n";
				cin >> newsco;
				a.sco = newsco;
			}
			v[i] = a;
			break;
		}
	}
	cout << "���޴���\n";
}
void query_student() {
	char s[20];
	cout << "����������ѧ�ţ�\n";
	scanf("%s",s);
	int flag = 0;
	for(int i = 0; i < v.size(); i++) {
		if(strcmp(s, v[i].student_id) == 0 || strcmp(s, v[i].name) == 0) {
			out(v[i]);
			flag = 1;
		}
	}
	if(flag == 0) cout << "���޴���\n";
}
void sort_out_student() {
	int n;
	cout << "1.����Ȩ�ɼ���������\n";
	cout << "2.����Ȩ�ɼ���������\n";
	cout << "3.��ѧ�Ž�������\n";
	cout << "4.��ѧ����������\n";
	cout << "������1-4\n";
	cin >> n;
	if(n == 1) sort(v.begin(), v.end(), cmp1);
	if(n == 2) sort(v.begin(), v.end(), cmp2);
	if(n == 3) sort(v.begin(), v.end(), cmp3);
	if(n == 4) sort(v.begin(), v.end(), cmp4);
	for(int i = 0; i < v.size(); i++ ) {
		out(v[i]);
		cout << endl;
	}

}
int main() {
	get();
	int choice = 9;
	while(choice != 6) {
		system("pause");
		system("cls");
		cout << "\t\t\t\t\t\t\tѧ����Ϣ����ϵͳ\n";
		cout << "\t\t\t\t\t\t\t1.����ѧ����Ϣ\n";
		cout << "\t\t\t\t\t\t\t2.ɾ��ѧ����Ϣ\n";
		cout << "\t\t\t\t\t\t\t3.�޸�ѧ����Ϣ\n";
		cout << "\t\t\t\t\t\t\t4.��ѯѧ����Ϣ\n";
		cout << "\t\t\t\t\t\t\t5.�������ѧ����Ϣ\n";
		cout << "\t\t\t\t\t\t\t6.���沢�˳�\n";
		cout << "���������1-6:";
		cin >> choice;
		if(choice < 1 || choice > 6)
			cout << "�Բ������������Ų���1-6�У��������룺\n";
		if(choice == 1) add_student();
		if(choice == 2) delete_student();
		if(choice == 3) modify_student();
		if(choice == 4) query_student();
		if(choice == 5) sort_out_student();
		save();
	}
	return 0;
}

