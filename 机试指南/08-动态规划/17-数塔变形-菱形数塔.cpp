#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/*

monkey banana problem P248

*/
const int maxn = 1010;
int dp[maxn][maxn];
int A[maxn][maxn];


int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		int ans = 1;
		while (T--) {
			int n;
			scanf("%d", &n);
			memset(dp, 0, sizeof(dp));
			memset(A, 0, sizeof(A));
			// 上半部分
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= i; j++) {
					scanf("%d", &A[i][j]);
				}
			}
			// 下半部分
			for (int i = n + 1; i <= 2 * n - 1; i++) {
				for (int j = 1; j <= 2 * n - i; j++) {
					scanf("%d", &A[i][j]);
				}
			}
//			dp[1][1] = A[1][1];
			dp[2*n-1][1] = A[2*n-1][1];
			// 下半部分
			for (int i = 2 * n - 2; i >= n; i--) {
				for (int j = 0; j < 2 * n - i; j++) {
					if (j == 0) { // 最左端
						dp[i][j] = dp[i+1][j] + A[i][j];
					} else if (j == 2 * n - i) { // 最右端
						dp[i][j] = dp[i+1][j-1] + A[i][j];
					} else {
						dp[i][j] = max(dp[i+1][j-1], dp[i+1][j]) + A[i][j];
					}
				}
			}
			// 上半部分
			for (int i = n - 1; i >= 1; i--) {
				for (int j = 1; j <= i; j++) {
					dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + A[i][j];
				}
			}
			
			
			printf("Case %d: %d\n", ans++, dp[1][1]);
		}
	}
}