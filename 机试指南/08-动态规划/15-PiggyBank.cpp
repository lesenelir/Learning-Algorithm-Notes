#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

Piggy Bank P240

01背包 要正好达到V就要设置最大的dp[v]，并把dp[0]赋值为0
类似于最小邮票数

*/
const int maxn = 1010;
const int INF = 10000001;
int dp[maxn];
int w[maxn], c[maxn];

int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int e, f;
			scanf("%d %d", &e, &f);
			int V = f - e; // 背包容量
			int n; // 物品种类
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				scanf("%d %d", &c[i], &w[i]);
			}
			// 初始化
			for (int v = 1; v <= V; v++) {
				dp[v] = INF;
			}
			dp[0] = 0;
			// 状态转移方程
			for (int i = 0; i < n; i++) {
				for (int v = w[i]; v <= V; v++) {
					dp[v] = min(dp[v], dp[v-w[i]] + c[i]);
				}
			}
			if (dp[V] == INF) {
				printf("This is impossible.\n");
			} else {
				printf("%d\n", dp[V]);	
			}
		}
	}
}