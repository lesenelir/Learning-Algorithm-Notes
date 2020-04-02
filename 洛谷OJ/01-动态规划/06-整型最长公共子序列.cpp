#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100001;
int A[maxn], B[maxn];
int dp[maxn][maxn];
int n;

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &B[i]);
		}
		// 边界
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 0;
		}
		for (int j = 0; j <= n; j++) {
			dp[0][j] = 0;
		}
		// 状态转移方程
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (A[i] == B[j]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("%d\n", dp[n][n]);
	}
	return 0;
}