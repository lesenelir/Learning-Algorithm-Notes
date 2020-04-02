#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 101;
int A[maxn];
int dp1[maxn], dp2[maxn];


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		// 边界
		for (int i = 0; i < n; i++) {
			dp1[i] = 1;
			dp2[i] = 1;
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) { // 从前往后
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i] && dp1[j] + 1 > dp1[i]) {
					dp1[i] = dp1[j] + 1;
				}
			}
		}
		for (int i = n-1; i >= 0; i--) { // 从后往前
			for (int j = n-1; j > i; j--) {
				if (A[j] < A[i] && dp2[j] + 1 > dp2[i]) {
					dp2[i] = dp2[j] + 1;
				}
			}
		}
		// 找最大
		int res1 = 0;
		for (int i = 1; i < n; i++) {
			if (dp1[i] > dp1[res1]) {
				res1 = i;
			}
		}
		int res2 = n-1;
		for (int i = n - 2; i >= 0; i--) {
			if (dp2[i] > dp2[res2]) {
				res2 = i;
			}
		}
		// 遍历维护max求出答案
		int total = -1;
		for (int i = 0; i < n; i++) {
			total = max(dp1[i] + dp2[i] - 1, total); // dp合计会重复计算一次所以要减去1
		}
		printf("%d\n", n-total);
		
	}
	return 0;
}