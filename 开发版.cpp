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
	printf("学号：%s\t",a.student_id);
	printf("姓名：%s\t",a.name);
	printf("院系：%s\t",a.yuan_xi);
	printf("班级：%s\t",a.class_num);
	printf("辅导员:%s\t",a.fudaoyuan);
	printf("户籍：%s\t",a.home);
	printf("电话：%s\t",a.tel);
	printf("加权成绩：%f\n",a.sco);
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
	cout << "姓名 学号 院系 班级 加权成绩 户籍 电话\n";
	cout << "加*号为必填项，不详的用#代替\n";

	cout << "输入姓名：\n";
	scanf("%s",a.name);

	cout << "输入学号：\n";
	scanf("%s",a.student_id);

	cout << "输入院系：\n";
	scanf("%s",a.yuan_xi);

	cout << "输入班级：\n";
	scanf("%s",a.class_num);

	cout << "输入辅导员：\n";
	scanf("%s",a.fudaoyuan);

	cout << "输入户籍（例如：江苏南京)：\n";
	scanf("%s",a.home);

	cout << "输入电话：\n";
	scanf("%s",a.tel);

	cout << "输入加权成绩（保留一位小数）：\n";
	cin >> a.sco;

	v.push_back(a);
}
void delete_student() {
	string s;
	cout  << "请输入学号：";
	cin >> s;
	for(int i = 0; i < v.size(); i++) {
		if(s == v[i].student_id) {
			out(v[i]);
			cout << "确认删除按y,不删除按n:";
			char c;
			cin >> c;
			if(c == 'y')	v.erase(v.begin() + i);
			cout << "已删除\n";
			break;
		}
	}
	cout << "查无此人\n";
}
void modify_student() {
	char s[20], news[20];
	float newsco;
	cout  << "请输入学号：";
	scanf("%s",s);
	for(int i = 0; i < v.size(); i++) {
		if(s == v[i].student_id) {
			stu a = v[i];
			out(v[i]);
			cout << "学号为不可修改项!!!\n" ;
			char c;
			cout << "修改姓名y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新名字:\n";
				scanf("%s",news);
				strcpy(a.name, news);
			}
			cout << "修改院系y/n?:\n";

			if(c == 'y') {
				cout << "请输入新院系:\n";
				scanf("%s",news);
				strcpy(a.yuan_xi , news);
			}

			cout << "修改班级y/n?:\n";

			if(c == 'y') {
				cout << "请输入新班级:\n";
				scanf("%s",news);
				strcpy(a.class_num, news);
			}

			cout << "修改辅导员y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新辅导员:\n";
				scanf("%s",news);
				strcpy(a.fudaoyuan, news);
			}

			cout << "修改户籍y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新户籍:\n";
				scanf("%s",news);
				strcpy(a.home , news);
			}
			cout << "修改电话y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新电话:\n";
				scanf("%s",news);
				strcpy(a.tel , news);
			}
			cout << "修改加权成绩y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新加权成绩:\n";
				cin >> newsco;
				a.sco = newsco;
			}
			v[i] = a;
			break;
		}
	}
	cout << "查无此人\n";
}
void query_student() {
	char s[20];
	cout << "输入姓名或学号：\n";
	scanf("%s",s);
	int flag = 0;
	for(int i = 0; i < v.size(); i++) {
		if(strcmp(s, v[i].student_id) == 0 || strcmp(s, v[i].name) == 0) {
			out(v[i]);
			flag = 1;
		}
	}
	if(flag == 0) cout << "查无此人\n";
}
void sort_out_student() {
	int n;
	cout << "1.按加权成绩降序排序\n";
	cout << "2.按加权成绩升序排序\n";
	cout << "3.按学号降序排序\n";
	cout << "4.按学号升序排序\n";
	cout << "请输入1-4\n";
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
		cout << "\t\t\t\t\t\t\t学生信息管理系统\n";
		cout << "\t\t\t\t\t\t\t1.增添学生信息\n";
		cout << "\t\t\t\t\t\t\t2.删除学生信息\n";
		cout << "\t\t\t\t\t\t\t3.修改学生信息\n";
		cout << "\t\t\t\t\t\t\t4.查询学生信息\n";
		cout << "\t\t\t\t\t\t\t5.排序汇总学生信息\n";
		cout << "\t\t\t\t\t\t\t6.保存并退出\n";
		cout << "请输入序号1-6:";
		cin >> choice;
		if(choice < 1 || choice > 6)
			cout << "对不起，您输入的序号不在1-6中，重新输入：\n";
		if(choice == 1) add_student();
		if(choice == 2) delete_student();
		if(choice == 3) modify_student();
		if(choice == 4) query_student();
		if(choice == 5) sort_out_student();
		save();
	}
	return 0;
}

