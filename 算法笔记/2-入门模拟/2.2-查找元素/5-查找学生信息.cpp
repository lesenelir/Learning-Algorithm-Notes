#include <iostream>
#include <cstdio>
using namespace std;

/*
输入的第一行为N，即学生的个数(N<=1000)

接下来的N行包括N个学生的信息，信息格式如下：
01 李江 男 21
然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号

输入：
5
001 张三 男 19
002 李四 男 20
003 王五 男 18
004 赵六 女 17
005 刘七 女 21
7
003
002
005
004
003
001
006
输出：
003 王五 男 18
002 李四 男 20
005 刘七 女 21
004 赵六 女 17
003 王五 男 18
001 张三 男 19
No Answer!

备注：
对于双重循环要有标记的变量，记得：
如果在第二个循环内就找到了相吻合的条件就要立即break跳出第二层循环，并在第一层循环后进行操作

*/

struct student {
	int id;
	char name[255];
	char sex[255];
	int age;	
}stu[100]; // 声明了student类型的数组名为stu的数组

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %s %s %d", &stu[i].id, stu[i].name, stu[i].sex, &stu[i].age);
		}
		int m;
		scanf("%d", &m);
		int a[100]; // a数组用来接收m行接收学生的id比较信息
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
		}
		
		for (int i = 0; i < m; i++) {
			int flag = 0; // flag 每次在遍历i的时候都要重新置为0
			int j;
			for (j=0; j < n; j++) { // 遍历stu数组
				if (a[i] == stu[j].id) {
					flag = 1;
					break; // break不能漏，易错！！！！找到以后，立即跳出循环
				} 
			}
			if (flag == 1) {
				printf("00%d %s %s %d\n", stu[j].id, stu[j].name, stu[j].sex, stu[j].age);
			} else {
				printf("No Answer!\n");
			}
		}
		
	}
}