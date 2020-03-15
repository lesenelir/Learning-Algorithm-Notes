#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

数塔问题（二维dp）
输入：
5
5
8 3
12 7 16
4 10 11 6
9 5 3 9 4
输出：
44

备注：
dp[i][j]是第i层第j列到最底层的路径最大值

*/

const int maxn = 1010;
int dp[maxn][maxn];
int f[maxn][maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		// 输入
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				scanf("%d", &f[i][j]);
			}
		}
		// 边界
		for (int j = 1; j <= n; j++) {
			dp[n][j] = f[n][j];
		}
		// 状态转移方程，从第n-1层往上递推得到[1][1]
		for (int i = n-1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
			}
		}
		printf("%d\n", dp[1][1]);
	}
}