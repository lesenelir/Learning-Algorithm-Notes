#include <iostream>
#include <cstdio>
using namespace std;

/*

定义一个结构体student，存储学生的学号、名字、性别和年龄，读入每个学生的所有信息，保存在结构体中，并输出。
输入：
3
10101 LiLin M 18
10102 ZhangFun M 19
10104 WangMin F 20
输出：
10101 LiLin M 18
10102 ZhangFun M 19
10104 WangMin F 20

笔记：
此题是结构体类型题目
struct student {
	int num;
	char name[20];
	char sex;
	int age;	
};
如上，此结构体类型是student类型
student stu[20];  // 创建一个student类型 数组名为stu的数组
第二种创建结构体方式：
struct student {
	int num;
	char name[20];
	char sex;
	int age;	
}stu[20];

*/

struct student {
	int num;
	char name[20];
	char sex;
	int age;	
};



int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	student stu[20]; // 定义一个student类型的数组
	for (int i = 0; i < n; i++) {
		scanf("%d %s %c %d", &stu[i].num, stu[i].name, &stu[i].sex, &stu[i].age);
	}
	for (int i = 0; i < n; i++) {
		printf("%d %s %c %d\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].age);
	}
}