#include <iostream>
#include <cstdio>
using namespace std;

/*

最长不下降子序列模板

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
			dp[i] = 1;
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] <= A[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
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