#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

完全背包：每种的物品可以选无穷多次

*/
const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxv];

int main(int argc, char *argv[]) {
	int n, V;
	while (scanf("%d %d", &n, &V) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &c[i]);
		}
		// 边界
		for (int v = 0; v <= V; v++) {
			dp[v] = 0;
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int v = w[i]; v <= V; v++) { // 正序
				dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
			}
		}
		// 找最大
		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (dp[i] > dp[res]) {
				res = i;
			}
		}
		printf("%d\n", dp[res]);
	}
}