#include <iostream>
#include <cstdio>
using namespace std;

/*

The Triangle (数塔) P246

*/
const int maxn = 1010;
int A[maxn][maxn];
int dp[maxn][maxn];


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		// 边界
		for (int j = 1; j <= n; j++) {
			dp[n][j] = A[n][j];
		}
		// 状态转移方程
		for (int i = n-1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + A[i][j];
			}
		}
		printf("%d\n", dp[1][1]);
	}
}