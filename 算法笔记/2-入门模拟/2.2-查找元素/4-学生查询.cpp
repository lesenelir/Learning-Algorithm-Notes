#include <iostream>
#include <cstdio>
using namespace std;

/*

输入n个学生的信息，每行包括学号、姓名、性别和年龄，每一个属性使用空格分开。最后再输入一学号，将该学号对应的学生信息输出。
测试数据有多组，第一行为样例数m。对于每个样例，第一行为学生人数n(n不超过20)，加下来n行每行4个整数分别表示学号、姓名、性别和年龄，最后一行表示查询的学号。

输入：
1
4
1 李江 男 21
2 刘唐 男 23
3 张军 男 19
4 王娜 女 19
2
输出：
2 刘唐 男 23

*/

struct student {
	int id;
	char name[20];
	char sex[20];
	int age;
}stu[20];

int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			int n;
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				scanf("%d %s %s %d", &stu[i].id, stu[i].name, stu[i].sex, &stu[i].age);
			}
			int k;
			scanf("%d", &k);
			for (int i = 0; i < n; i++) {
				if (k == stu[i].id) {
					printf("%d %s %s %d", stu[i].id, stu[i].name, stu[i].sex, stu[i].age);
				}
			}
		}
	}
}