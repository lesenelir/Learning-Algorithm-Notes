#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

01背包问题：每种物品只有一件

dp[v]表示 重量不超过v的时候，最大价值

*/
const int maxn = 100;  // 物品最大限度
const int maxv = 1000; // 容量的上限

int w[maxn], c[maxn], dp[maxv];

int main(int argc, char *argv[]) {
	int n, V;
	while (scanf("%d %d", &n, &V) != EOF) {
		for (int i = 0; i < n; i++) { // 重量
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < n; i++) { // 价值
			scanf("%d", &c[i]);
		}
		// 边界
		for (int v = 0; v <= V; v++) {
			dp[v] = 0;
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int v = V; v >= w[i]; v--) { // 逆序
				dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
			}
		}
		// 找最大的dp[v]
		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (dp[i] > dp[res]) {
				res = i;
			}
		}
		printf("%d\n", dp[res]); // dp[V]
	}
}