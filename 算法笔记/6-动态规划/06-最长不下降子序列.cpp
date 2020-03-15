#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

最长不下降子序列（一维）
输入：
8
1 2 3 -9 3 9 0 11
输出：
6

备注：
dp[i]代表以A[i]结尾的最长不下降子序列长度

*/
const int maxn = 1010;
int dp[maxn];
int A[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		// 读入序列
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		int ans = -1; // 记录最大的dp[i]
		for (int i = 0; i < n; i++) { // 按顺序计算出dp[i]
			dp[i] = 1; // 初始条件
			for (int j = 0; j < i; j++) {
				if (A[i] >= A[j] && (dp[j] + 1 > dp[i])) {
					dp[i] = dp[j] + 1;
				}
			}
			ans = max(ans, dp[i]);
		}	
		printf("%d\n", ans);	
	}
}