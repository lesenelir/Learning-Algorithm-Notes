#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

A1045 Favorite Color Strip LCS
最长公共子序列
特别：允许公共部分产生相同元素


*/
const int maxc = 210;
const int maxn = 1010;
int A[maxc]; // 喜欢颜色数组
int B[maxn]; // 带子数组
int dp[maxn][maxn];

int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		for (int i = 1; i <= m; i++) {
			scanf("%d", &A[i]);
		}
		int L;
		scanf("%d", &L);
		for (int i = 1; i <= L; i++) {
			scanf("%d", &B[i]);
		}
		// 边界
		for (int i = 0; i <= m; i++) {
			dp[i][0] = 0;
		}
		for (int j = 0; j <= L; j++) {
			dp[0][j] = 0;
		}
		// 状态转移方程
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= L; j++) {
				if (A[i] == B[j]) { // 允许公共部分产生相同元素，要稍微修改状态方程
					// 正常不允许相同元素是dp[i] = dp[i-1][j-1] + 1;
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("%d\n", dp[m][L]);
	}
}