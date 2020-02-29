#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

对每个测试用例，首先输出1行“Case i:”，其中 i 是测试用例的编号（从1开始）。随后在 N 行中输出按要求排序后的结果
即当 C=1 时，按学号递增排序；当 C=2时，按姓名的非递减字典序排序；当 C=3 时，按成绩的非递减排序。
当若干学生具有相同姓名或者相同成绩时，则按他们的学号递增排序。

每个测试用例的第1行包含两个整数 N (N<=100000) 和 C，其中 N 是纪录的条数，C 是指定排序的列号。
当读到 N=0 时，全部输入结束，相应的结果不要输出。

先输出1行“Case i:”，其中 i 是测试用例的编号（从1开始）。随后在 N 行中输出按要求排序后的结果

输入：
4 1
000001 Zhao 75
000004 Qian 88
000003 Li 64
000002 Sun 90
4 2
000005 Zhao 95
000011 Zhao 75
000007 Qian 68
000006 Sun 85
4 3
000002 Qian 88
000015 Li 95
000012 Zhao 70
000009 Sun 95
0 3

输出：
Case 1:
000001 Zhao 75
000002 Sun 90
000003 Li 64
000004 Qian 88
Case 2:
000007 Qian 68
000006 Sun 85
000005 Zhao 95
000011 Zhao 75
Case 3:
000012 Zhao 70
000002 Qian 88
000009 Sun 95
000015 Li 95

*/

const int maxn = 1010;


struct student {
	int id;
	char name[maxn];
	int score;
}stu[maxn];

bool cmp1(student a, student b) {
	return a.id < b.id;
}

bool cmp2(student a, student b) {
	if (a.score == b.score || strcmp(a.name, b.name) == 0) {
		return a.id < b.id;
	} else {
		return strcmp(a.name, b.name) < 0;
	}
}

bool cmp3(student a, student b) {
	if (a.score == b.score || strcmp(a.name, b.name) == 0) {
		return a.id < b.id;
	} else {
		return a.score < b.score;	
	}
}


int main(int argc, char *argv[]) {
	int n, c;
	while (scanf("%d %d", &n, &c) != EOF) {
		if (n == 0) break;
		// 输入
		for (int i = 0; i < n; i++) {
			scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
		}
		// 排序
		if (c == 1) {
			sort(stu, stu+n, cmp1);
		} else if (c == 2) {
			sort(stu, stu+n, cmp2);
		} else {
			sort(stu, stu+n, cmp3);
		}
		// 输出
		printf("Case %d:\n", c);
		for (int i = 0; i < n; i++) {
			printf("%d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
		}
			
	}
}