#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

采药
医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间， 在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是辰辰，你能完成这个任务吗？
【输入】第 一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），用一个空格隔开，
T(V)代表总共能够用来采药的时间，M(n)代表山洞里的草药的数目。
接下来的M行每行包括两个在1到100之间（包括1和100）的整 数，分别表示采摘某株草药的时间和这株草药的价值。
【输出】一个整数，表示在规定的时间内，可以采到的草药的最大总价值。

输入：
70 3
71 100
69 1
1 2
输出
3

*/
const int maxn = 100;
const int maxv = 1000;
int w[maxn], c[maxn], dp[maxv];

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
			for (int v = V; v >= w[i]; v--) { // 逆序 01背包
				dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
			}
		}
		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (dp[i] > dp[res]) {
				res = i;
			}
		}
		
		printf("%d\n", dp[res]);
	}
}