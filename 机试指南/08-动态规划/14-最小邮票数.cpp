#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

最小邮票数（清华大学）P239

物体所占体积为本题中邮票的面值，物体价值恒为1，转换为求最小价值即可

备注：
此题目是01背包求最小的问题要注意初始化条件以及边界

多用于 邮票面值 还有 零钱问题

因为该问题要求最后要正好达到V的值，所以要将dp[i]（i:1~V）设置为无穷大， do[0] = 0;

*/
const int maxn = 1010;
const int INF = 1000001;
int w[maxn];
int dp[maxn];

int main(int argc, char *argv[]) {
	int V, n;
	while (scanf("%d %d", &V, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		// 初始化
		for (int i = 1; i <= V; i++) { // 【注意】
			dp[i] = INF;
		}
		dp[0] = 0;
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int v = V; v >= w[i]; v--) {
				dp[v] = min(dp[v], dp[v-w[i]] + 1);
			}
		}
		// 输出
		if (dp[V] != INF) {
			printf("%d\n", dp[V]);
		} else {
			printf("0\n");
		}
		
	}
}