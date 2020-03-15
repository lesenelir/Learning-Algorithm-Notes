#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

最长上升子序列
输入：
7
1 7 3 5 9 4 8
输出：
4

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
		int ans = -1;
		for (int i = 0; i < n; i++) {
			dp[i] = 1; // 初始状态
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i] && (dp[j] + 1 > dp[i])) {
					dp[i] = dp[j] + 1;
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
}