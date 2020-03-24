#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

A1007 Maximum Subsequence Sum P387

*/
const int maxn = 1010;
int dp[maxn];
int A[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			if (A[i] > 0) flag = true;
		}
		if (flag == false) {
			printf("0 %d %d\n", A[0], A[n-1]);
		} else {
			// 边界
			dp[0] = A[0];
			// 状态转移方程
			for (int i = 1; i < n; i++) { //【注意易错】转移方程下标从不是边界的第一个元素开始
				dp[i] = max(A[i], dp[i-1] + A[i]);
			}
			// 找最大值
			int k = 0;
			for (int i = 1; i < n; i++) {
				if (dp[i] > dp[k]) {
					k = i;
				}
			}
			// 找序列下标
			int num = 0;
			int s = 0;
			for (int i = k; i >= 0; i--) {
				num = num + A[i]; // 加元素值
				if (num == dp[k]) {
					s = i;
					break;
				}
			}
			printf("%d %d %d\n", dp[k], A[s], A[k]);
		}
	}
}