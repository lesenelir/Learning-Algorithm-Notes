#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

装箱问题：
【问题描述】 
有一个箱子的容量为V（V为正整数，且满足0≤V≤20000），同时有n件物品（0的体积值为正整数。 
要求从n件物品中，选取若干装入箱内，使箱子的剩余空间最小。 
输入：1行整数，第1个数表示箱子的容量，第2个数表示有n件物品，后面n个数分别表示这n件 
物品各自的体积。 
输出：1个整数，表示箱子剩余空间。 
【输入输出样例】 
输入： 
24 6 8 3 12 7 9 7 
输出： 
0

备注：（完全背包问题）
尽可能的占据箱子最大值，

*/
const int maxn = 100;
const int maxv = 20000;
int w[maxn], dp[maxv];

int main(int argc, char *argv[]) {
	int V, n;
	while (scanf("%d %d", &V, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		// 边界
		for (int v = 0; v <= V; v++) {
			dp[v] = 0;
		}
		// 状态转移方程
		for (int i = 0; i < n; i++) {
			for (int v = w[i]; v <= V; v++) { // 正序 完全背包
				dp[v] = max(dp[v], dp[v-w[i]] + w[i]);
			}
		}
		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (dp[i] > dp[res]) {
				res = i;
			}
		}
		printf("%d\n", V - dp[res]); // 剩余空间
	}
}