#include <iostream>
#include <cstdio>
using namespace std;

/*

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。

输入：
2
6 3
7 2
输出：
7
4

*/
int f(int m, int n) {
	if (n == 1 || m == 0) {
		return 1;
	}
	if (n > m) { // 盘子比苹果多必定有n-m个盘子永远空着，去掉这些盘子不对结果产生影响
		return f(m, m);
	}
	return f(m, n-1) + f(m-n, n); // 有至少一个盘子空着+盘子都有苹果，从每个盘子拿掉一个苹果不影响结果
}


int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int m, n;
			scanf("%d %d", &m, &n);
			int res = f(m, n);
			printf("%d\n", res);
		}
	}
}