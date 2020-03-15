#include <iostream>
#include <cstdio>
using namespace std;

/*

Fibonacci动态规划递归写法

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int dp[maxn];
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		printf("%d\n", dp[n]);
	}
}