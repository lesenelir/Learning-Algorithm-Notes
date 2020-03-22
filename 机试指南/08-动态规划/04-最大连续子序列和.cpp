#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

最大连续子序列和最大（清华大学）P225

*/
const int maxn = 1010;
int dp[maxn];
int A[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		// 边界
		dp[0] = A[0];
		// 状态转移方程
		for (int i = 1; i < n; i++) {
			dp[i] = max(A[i], dp[i-1] + A[i]);
		}
		// 找最大的dp值
		int res = 0;
		for (int i = 1; i < n; i++) {
			if (dp[i] > dp[res]) {
				res = i;
			}
		}
		printf("%d\n", dp[res]);
	}
}