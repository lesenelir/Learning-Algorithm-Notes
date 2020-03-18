#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

拦截导弹
它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度
某天，雷达捕捉到敌国的导弹来袭，并观测到导弹依次飞来的高度，请计算这套系统最多能拦截多少导弹。拦截来袭导弹时，必须按来袭导弹袭击的时间顺序，不允许先拦截后面的导弹，再拦截前面的导弹

每组输入有两行，第一行，输入雷达捕捉到的敌国导弹的数量k（k<=25），第二行，输入k个正整数，表示k枚导弹的高度，按来袭导弹的袭击时间顺序给出，以空格分隔。

每组输出只有一行，包含一个整数，表示最多能拦截多少枚导弹。

输入：
4
9 6 7 8
7
4 5 6 7 13 42 3
5
6 5 4 3 5
0
输出：
2
2
4

备注：
模型：最长不上升子序列

*/
const int maxn = 1010;
int A[maxn];
int dp[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf ("%d", & n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			dp[i] = 1; // 初始化
			for (int j = 0; j < i; j++) {
				if (A[j] >= A[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
}