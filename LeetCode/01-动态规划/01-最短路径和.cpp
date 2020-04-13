#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

从左上角到右下角找一条路径，使路径总和的数字最小

输入：
3 3
[1,3,1],
[1,5,1],
[4,2,1].

输出：
7

*/
const int maxn = 1001;
int a[maxn][maxn];
int dp[maxn][maxn]; // 路径长度


int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		// 输入
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		// 边界
		dp[0][0] = a[0][0];
		for (int i = 1; i < n; i++) { // 第0列
			dp[i][0] = dp[i-1][0] + a[i][0];
		}
		for (int j = 1; j < m; j++) { // 第0行
			dp[0][j] = dp[0][j-1] + a[0][j];
		}
		// 状态转移方程
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
			}
		}
		printf("%d\n", dp[n-1][m-1]);
	}
}