#include <iostream>
#include <cstdio>
using namespace std;

/*

Fibonacci数列非递归版本（整数保存数据）
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
		int f1 = 1, f2 = 1;
		int f3 = 0;
		for (int i = 3; i <= n; i++) { // 轮转思想
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		printf("%d\n", f3);
	}
}