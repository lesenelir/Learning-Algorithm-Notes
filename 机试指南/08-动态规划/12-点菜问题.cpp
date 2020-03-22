#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

点菜问题 P238
备注：
经典01背包问题

*/
const int maxn = 1010;
int dp[maxn];
int w[maxn], c[maxn];

int main(int argc, char *argv[]) {
	int n, V;
	while (scanf("%d %d", &V, &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &w[i], &c[i]);
		}
		// 边界
		for (int v = 0; v <= V; v++) {
			dp[v] = 0;
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int v = V; v >= w[i]; v--) {
				dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
			}
		}
		// 找最大值 = dp[V]
		int k = 0;
		for (int v = 1; v <= V; v++) { // 【易出错】
			if (dp[v] > dp[k]) {
				k = v;
			}
		}
		printf("%d\n", dp[k]); // dp[V]
	}	
}