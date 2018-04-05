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
		cout << "请输入序号1-6";
		cin >> choice;
		if(choice < 1 || choice > 6)
			cout << "对不起，您输入的序号不在1-6中，重新输入：\n";
//		if(choice == 1) add_student();
//		if(choice == 2) delete_student();
//		if(choice == 3) modify_student();
//		if(choice == 4) query_student();
//		if(choice == 5) out_student();
		if(choice == 6) save();
	}
	return 0;
}

