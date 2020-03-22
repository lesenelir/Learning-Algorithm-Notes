#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

神奇的口袋（北京大学）

*/
const int maxn = 1010;
const int V = 40;
int w[maxn];
int dp[maxn]; // dp[i]代表口袋体积为i时，有几种方法

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		// 边界
		for (int v = 0; v <= V; v++) {
			dp[v] = 0;
		}
		dp[0] = 1;
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int v = V; v >= w[i]; v--) {
				dp[v] = dp[v] + dp[v-w[i]];
			}
			//dp[w[i]]++; // 口袋体积等于物体体积时，必有一种方法
		}
		printf("%d\n", dp[V]);
	}
}