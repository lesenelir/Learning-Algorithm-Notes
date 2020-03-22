#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

最大连续子序列和及下标（浙江大学）P229

*/
const int maxn = 1010;
int dp[maxn];
int A[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			if (A[i] > 0) flag = true; // 判断是否都为负数
		}
		if (flag == false) {
			printf("0 %d %d\n", A[0], A[n-1]);
		} else {
			// 边界
			dp[0] = A[0];
			// 状态转移方程
			for (int i = 1; i < n; i++) {
				dp[i] = max(A[i], dp[i-1] + A[i]);
			}
			// 找最大值
			int k = 0;
			for (int i = 1; i < n; i++) {
				if (dp[i] > dp[k]) {
					k = i;
				}
			}
			// 逆序找子序列的第一个元素下标
			int sum = 0;
			int s = 0;
			for (int i = k; i >= 0; i--) {
				sum = sum + A[i];
				if (sum == dp[k]) {
					s = i;
					break;
				}
			}
			printf("%d %d %d\n", dp[k], A[s], A[k]);
		}
	
	}
}