#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stu {
	string name, student_id, yuan_xi, class_num, fudaoyuan, home, tel;
	float sco;
};
vector<stu> v;
bool cmp1 (stu x, stu y) {
	return x.sco > y.sco;
}
bool cmp2 (stu x, stu y) {
	return x.sco < y.sco;
}
bool cmp3 (stu x, stu y) {
	return x.student_id > y.student_id;
}
bool cmp4 (stu x, stu y) {
	return x.student_id < y.student_id;
}
void out(stu a) {
	cout << "ѧ��: " << a.student_id << "\t";
	cout << "����: " << a.name  << "\t";
	cout << "Ժϵ: " << a.yuan_xi << "\t";
	cout << "�༶: " << a.class_num << "\t";
	cout << "����Ա: " << a.fudaoyuan << "\t";
	cout << "����: " << a.home  << "\t";
	cout << "�绰: " << a.tel << "\t";
	cout << "��Ȩ�ɼ�: "; printf("%.1f",a.sco);
	system("puase");
}
void get() {
	FILE *fp;
	stu a;
	fp = fopen("student.dat","r");
	while(fread(&a,sizeof(stu),1,fp) == 1) {
		v.push_back(a);
	}
	fclose(fp);
}
void save() {
	FILE *fp, *fp2;
	stu a;
	fp = fopen("student.dat","w");
	fclose(fp);
	fp2 = fopen("student.dat","a+");
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
	system("puase");

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
	system("puase");

} 
void modify_student() {
	string s, news;
	float newsco; 
	cout  << "������ѧ�ţ�";
	cin >> s;
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
				cin >> news;
				a.name = news;
			}
			cout << "�޸�Ժϵy/n?:\n";

			if(c == 'y') {
				cout << "��������Ժϵ:\n";
				cin >>  news;
				a.name = news;
			}

			cout << "�޸İ༶y/n?:\n";

			if(c == 'y') {
				cout << "�������°༶:\n";
				cin >>  news;
				a.name = news;
			}
		
			cout << "�޸ĸ���Աy/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������¸���Ա:\n";
				cin >>  news;
				a.name = news;
			}
			
			cout << "�޸Ļ���y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������»���:\n";
				cin >>  news;
				a.name = news;
			}
			cout << "�޸ĵ绰y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������µ绰:\n";
				cin >>  news;
				a.name = news;
			}
			cout << "�޸ļ�Ȩ�ɼ�y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "�������¼�Ȩ�ɼ�:\n";
				cin >> newsco;
				a.name = news;
			}
			v[i] = a;
			break;
		} 
	} 
	cout << "���޴���\n";
	
}
void query_student() {
	string s;
	cout << "����������ѧ�ţ�\n";
	cin >> s;
	int flag = 0;
	for(int i = 0; i < v.size(); i++) {
		if(s == v[i].student_id || s == v[i].name) {
			out(v[i]);
			flag = 1;
		} 
	} 
	if(flag == 0) cout << "���޴���\n";
	system("puase");

}
void out_student() {
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
	system("puase");

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
		cout << "���������1-6:";
		cin >> choice;
		if(choice < 1 || choice > 6)
			cout << "�Բ������������Ų���1-6�У��������룺\n";
		if(choice == 1) add_student();
		if(choice == 2) delete_student();
		if(choice == 3) modify_student();
		if(choice == 4) query_student();
		if(choice == 5) out_student();
		save();
	}
	return 0;
}

