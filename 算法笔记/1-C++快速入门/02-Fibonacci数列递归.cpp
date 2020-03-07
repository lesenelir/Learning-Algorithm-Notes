#include <iostream>
#include <cstdio>
using namespace std;

/*

Fibonacci数列递归版本
Fibonacci数列的特点：第1,2个数为1,1。从第3个数开始，概述是前面两个数之和。
输入：20
输出：6765

*/

int Fibonacci(int n) {
	if (n == 1 || n == 2) {
		return 1;
	} else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}



int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int res = Fibonacci(n);
	printf("%d\n", res);	
}