#include <iostream>
#include <cstdio>
using namespace std;

/*

考新郎 假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.

错排问题
先用C(n,m)求出从n个新郎中挑m个出来的方案数，再乘以错排数即可。

错排：
所有元素都不在原来的位置上称之为错排。
n个编号元素放在n个编号位置，元素编号与位置编号各不对应的方法用M(n)表示，
则M(n-1)表示n-1个编号元素放在n-1个编号位置，各不对应的方法数。

M(1) = 0 
M(2) = 1
M(n) = (n-1) * (M[n-1] + M[n-2])

*/
const int maxn = 1010;
int dp[maxn];
int a[maxn];

// 排列组合
void make_com(int n) {
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i-1] * (n-i+1) / i;
	}
}



// 错排
void make_mistake(int m) {
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= m; i++) {
		dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
	}
}


int main(int argc, char *argv[]) {
	int C;
	while (scanf("%d", &C) != EOF) {
		while (C--) {
			int n, m;
			scanf("%d %d", &n, &m);
			make_com(n);
			make_mistake(m);
			int res = a[m] * dp[m];
			printf("%d\n", res);
		}
	}
}