#include <iostream>
#include <cstdio>
using namespace std;

/*

Problem Description
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？


Input
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。


Output
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。


Sample Input
2
4
5
0


Sample Output
2
4
6

*/
const int maxn = 100;
int a[maxn];



// 递归求解
int cow_son(int n) {
	if (n <= 4) return n;
	else {
		return cow_son(n-1) + cow_son(n-3);
	}
}

// 记忆化搜索 
int cow(int n) {
	if (n < 5) return a[n] = n;
	else return a[n] = cow(n-1) + cow(n-3);
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int dp[maxn];
		for (int i = 1; i <= 4; i++) {
			dp[i] = i;
		}
		for (int i = 5; i < 60; i++) { // 嵌套循环
			dp[i] = dp[i-1] + dp[i-3];
		}
		printf("%d\n", dp[n]);
	}
}