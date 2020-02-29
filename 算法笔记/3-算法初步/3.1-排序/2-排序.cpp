#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

对输入的n个数进行排序并输出。
可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。
每组测试数据的结果占一行。
输入：
5
5 4 3 1 2
输出
1 2 3 4 5

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}