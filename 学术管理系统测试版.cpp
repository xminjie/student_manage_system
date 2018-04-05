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
	cout << "学号: " << a.student_id << "\t";
	cout << "姓名: " << a.name  << "\t";
	cout << "院系: " << a.yuan_xi << "\t";
	cout << "班级: " << a.class_num << "\t";
	cout << "辅导员: " << a.fudaoyuan << "\t";
	cout << "户籍: " << a.home  << "\t";
	cout << "电话: " << a.tel << "\t";
	cout << "加权成绩: "; printf("%.1f",a.sco);
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
	cout << "姓名 学号 院系 班级 加权成绩 户籍 电话\n";
	cout << "加*号为必填项，不详的用#代替\n";

	cout << "输入姓名：\n";
	cin >> a.name;

	cout << "输入学号：\n";
	cin >> a.student_id;

	cout << "输入院系：\n";
	cin >> a.yuan_xi;

	cout << "输入班级：\n";
	cin >> a.class_num;

	cout << "输入辅导员：\n";
	cin >> a.fudaoyuan;

	cout << "输入加权成绩（保留一位小数）：\n";
	cin >> a.sco;

	cout << "输入户籍（例如：江苏南京)：\n";
	cin >> a.home;

	cout << "输入电话：\n";
	cin >> a.tel;

	v.push_back(a);
	system("puase");

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
	system("puase");

} 
void modify_student() {
	string s, news;
	float newsco; 
	cout  << "请输入学号：";
	cin >> s;
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
				cin >> news;
				a.name = news;
			}
			cout << "修改院系y/n?:\n";

			if(c == 'y') {
				cout << "请输入新院系:\n";
				cin >>  news;
				a.name = news;
			}

			cout << "修改班级y/n?:\n";

			if(c == 'y') {
				cout << "请输入新班级:\n";
				cin >>  news;
				a.name = news;
			}
		
			cout << "修改辅导员y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新辅导员:\n";
				cin >>  news;
				a.name = news;
			}
			
			cout << "修改户籍y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新户籍:\n";
				cin >>  news;
				a.name = news;
			}
			cout << "修改电话y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新电话:\n";
				cin >>  news;
				a.name = news;
			}
			cout << "修改加权成绩y/n?:\n";
			cin >> c;
			if(c == 'y') {
				cout << "请输入新加权成绩:\n";
				cin >> newsco;
				a.name = news;
			}
			v[i] = a;
			break;
		} 
	} 
	cout << "查无此人\n";
	
}
void query_student() {
	string s;
	cout << "输入姓名或学号：\n";
	cin >> s;
	int flag = 0;
	for(int i = 0; i < v.size(); i++) {
		if(s == v[i].student_id || s == v[i].name) {
			out(v[i]);
			flag = 1;
		} 
	} 
	if(flag == 0) cout << "查无此人\n";
	system("puase");

}
void out_student() {
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
	system("puase");

}
int main() {
	get();
	int choice = 9;
	while(choice != 6) {
		cout << "学生信息管理系统\n";
		cout << "1.增添学生信息\n";
		cout << "2.删除学生信息\n";
		cout << "3.修改学生信息\n";
		cout << "4.查询学生信息\n";
		cout << "5.排序汇总学生信息\n";
		cout << "6.保存并退出\n";
		cout << "请输入序号1-6:";
		cin >> choice;
		if(choice < 1 || choice > 6)
			cout << "对不起，您输入的序号不在1-6中，重新输入：\n";
		if(choice == 1) add_student();
		if(choice == 2) delete_student();
		if(choice == 3) modify_student();
		if(choice == 4) query_student();
		if(choice == 5) out_student();
		save();
	}
	return 0;
}

