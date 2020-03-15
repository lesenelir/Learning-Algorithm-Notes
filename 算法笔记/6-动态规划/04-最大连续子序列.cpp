#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

最大连续子序列和（一维）
输入：
6
-2 11 -4 13 -5 -2
输出：
20

备注：
dp[i]代表以A[i]作为末尾的连续序列的和最大值

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
		// 边界
		dp[0] = A[0];
		// 状态转移方程
		for (int i = 1; i < n; i++) { // 除去边界第一个元素之外
			dp[i] = max(A[i], dp[i-1] + A[i]);
		}
		// 遍历得到最大值
		int k = 0;
		for (int i = 1; i < n; i++) {
			if (dp[i] > dp[k]) {
				k = i;
			}
		}
		printf("%d\n", dp[k]);
	}
}