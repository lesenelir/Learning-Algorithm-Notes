#include <iostream>
#include <cstdio>
using namespace std;

/*

最大上升子序列和（北京大学）P232

备注：
相对于最长不下降子序列的不同点在于:
	dp[i]代表的是以A[i]为结尾的

*/
const int maxn = 1010;
int A[maxn];
int dp[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		// 边界
		for (int i = 0; i < n; i++) {
			dp[i] = A[i];
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i] && dp[j] + A[i] > dp[i]) {
					dp[i] = dp[j] + A[i];
				}
			}
		}
		// 找最大值
		int k = 0;
		for (int i = 1; i < n; i++) {
			if (dp[i] > dp[k]) {
				k = i;
			}
		}
		printf("%d\n", dp[k]);
	}
}