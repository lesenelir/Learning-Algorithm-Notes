#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

采药问题 P239

*/
const int maxn = 1010;
int dp[maxn];
int w[maxn], c[maxn];

int main(int argc, char *argv[]) {
	int V, n;
	while (scanf("%d %d", &V, &n) != EOF) {
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
				dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
			}
		}
		printf("%d\n", dp[V]);
	}
}