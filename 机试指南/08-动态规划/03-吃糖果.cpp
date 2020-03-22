#include <iostream>
#include <cstdio>
using namespace std;

/*

吃糖果（北京大学）P224

每天可以吃一块糖果或者两块糖果
类似于N阶楼梯上楼问题，也类似于Fibonacci数列

*/
const int maxn = 1010;
int dp[maxn];

// 递归版本
int Function(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else return Function(n-1) + Function(n-2);
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		printf("%d\n", dp[n]);
	}
}