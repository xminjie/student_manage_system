#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
using namespace std;

struct stu {
	string name, student_id, yuan_xi, class_num, fudaoyuan, home, tel;
	float sco;
};
vector<stu> v;

//void add_student();
//void delete_student();
//void modify_student();
//void query_student();
//void out_student();

void get() {
	FILE *fp;
	stu a;
	fp = fopen("student.txt","r");
	while(fread(&a,sizeof(stu),1,fp) == 1) {
		v.push_back(a);
	}
	fclose(fp);
}
void save() {
	FILE *fp, *fp2;
	stu a;
	fp = fopen("student.txt","w");
	fclose(fp);
	fp2 = fopen("student.txt","a+");
	for(stu i : v) {
		fwrite(&a,sizeof(stu),1,fp2);
	}
	fclose(fp2);
}
void add_student() {
	stu a;
	cout << "���� ѧ�� Ժϵ �༶ ��Ȩ�ɼ� ���� �绰\n";
	cout << "��*��Ϊ������������#����\n";

	cout << "����������\n";
	cin >> a.name;

	cout << "����ѧ�ţ�\n";
	cin >> a.student_id;

	cout << "����Ժϵ��\n";
	cin >> a.yuan_xi;

	cout << "����༶��\n";
	cin >> a.class_num;

	cout << "���븨��Ա��\n";
	cin >> a.fudaoyuan;

	cout << "�����Ȩ�ɼ�������һλС������\n";
	cin >> a.sco;

	cout << "���뻧�������磺�����Ͼ�)��\n";
	cin >> a.home;

	cout << "����绰��\n";
	cin >> a.tel;

	v.push_back(a);

}
int main() {
	get();
	int choice = 9;
	while(choice != 6) {
		cout << "ѧ����Ϣ����ϵͳ\n";
		cout << "1.����ѧ����Ϣ\n";
		cout << "2.ɾ��ѧ����Ϣ\n";
		cout << "3.�޸�ѧ����Ϣ\n";
		cout << "4.��ѯѧ����Ϣ\n";
		cout << "5.�������ѧ����Ϣ\n";
		cout << "6.���沢�˳�\n";
		cout << "���������1-6";
		cin >> choice;
		if(choice < 1 || choice > 6)
			cout << "�Բ������������Ų���1-6�У��������룺\n";
//		if(choice == 1) add_student();
//		if(choice == 2) delete_student();
//		if(choice == 3) modify_student();
//		if(choice == 4) query_student();
//		if(choice == 5) out_student();
		if(choice == 6) save();
	}
	return 0;
}

