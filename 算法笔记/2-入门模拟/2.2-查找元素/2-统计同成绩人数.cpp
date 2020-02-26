#include <iostream>
#include <cstdio>
using namespace std;

/*

读入N名学生的成绩，将获得某一给定分数的学生人数输出。
第1行：N
第2行：N名学生的成绩，相邻两数字用一个空格间隔。
第3行：给定分数
当读到N=0时输入结束。

输入：
4
70 80 90 100
80
3
65 75 85
55
5
60 90 90 90 85
90
0
输出：
1
0
3

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == x) {
				count++;
			}
		}
		printf("%d\n", count);
	}
}