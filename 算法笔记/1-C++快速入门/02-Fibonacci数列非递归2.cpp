#include <iostream>
#include <cstdio>
using namespace std;

/*

Fibonacci数列非递归版本（数组保存数据）
Fibonacci数列的特点：第1,2个数为1,1。从第3个数开始，概述是前面两个数之和。
输入：20
输出：6765

*/

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	if (n == 1 || n == 2) {
		printf("%d\n", 1);
	} else {
		int a[25];
		a[0] = 1, a[1] = 1;
		for (int i = 2; i <= n; i++) {
			a[i] = a[i-1] + a[i-2];
		}
		printf("%d\n", a[n-1]);
	}
}