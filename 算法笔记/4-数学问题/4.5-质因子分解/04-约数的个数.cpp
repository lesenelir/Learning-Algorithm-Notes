#include <iostream>
#include <cstdio>
using namespace std;

/*

输入n个整数,依次输出每个数的约数的个数。

输入的第一行为N，即数组的个数(N<=1000)
接下来的1行包括N个整数，其中每个数的范围为(1<=Num<=1000000000)
当N=0时输入结束。

输入：
6
1 4 6 8 10 12
0
输出：
1
3
4
4
4
6

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
		for (int i = 0; i < n; i++) { // 对于数组中每一个数字来说
			int count = 0;
			for (int j = 1; j <= a[i]; j++) { // 从1开始遍历到a[i]数字判断
				if (a[i] % j == 0) count++;
			}
			printf("%d\n", count);
		}
	}
}