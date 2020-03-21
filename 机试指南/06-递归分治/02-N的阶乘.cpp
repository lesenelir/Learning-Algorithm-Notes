#include <iostream>
#include <cstdio>
using namespace std;

/*

n的阶乘 非递归版本 动态规划

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int dp[100];
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = i * dp[i-1];
		}
		printf("%d\n", dp[n]);
	}
}