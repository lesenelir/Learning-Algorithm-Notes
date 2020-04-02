#include <iostream>
#include <cstdio>
using namespace std;

/*
小明的花店新开张，为了吸引顾客，他想在花店的门口摆上一排花，共
m
m盆。通过调查顾客的喜好，小明列出了顾客最喜欢的
n
n种花，从
1
1到
n
n标号。为了在门口展出更多种花，规定第
i
i种花不能超过
a
i
a 
i
​	
 盆，摆花时同一种花放在一起，且不同种类的花需按标号的从小到大的顺序依次摆列。

试编程计算，一共有多少种不同的摆花方案。

*/
const int maxn = 100001;
int n, m;
int a[maxn];
int dp[maxn][maxn];

//从 1 到 n考虑每个xi的值，和当前前i个数的总和k，枚举当前xi所有可能的值
int DFS(int x, int k) {
	if (k > m) return 0;
	if (k == m) return 1;
	if (x == n+1) return 0;
	int ans = 0;
	for (int i = 0; i <= a[x]; i++) ans = (ans + DFS(x+1, k+i));
	return ans;
}

int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		// dp(i,j) 表示前i个数总和为j的方案数
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k <= min(j, a[i]); k++) {
					dp[i][j] = dp[i][j] + dp[i-1][j-k];
				}
			}
		}
		printf("%d\n", dp[n][m]);	
	}
}