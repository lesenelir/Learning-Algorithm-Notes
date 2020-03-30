#include <iostream>
#include <cstdio>
using namespace std;

/*

折线分平面（hdu2050）

根据直线分平面可知，由交点决定了射线和线段的条数，进而决定了新增的区域数。当n-1条折线时，区域数为f（n-1）。为了使增加的区域最多，则折线的两边的线段要和n-1条折线的边，即2*（n-1）条线段相交。那么新增的线段数为4*（n-1），射线数为2。但要注意的是，折线本身相邻的两线段只能增加一个区域。
f(n)=f(n-1)+4(n-1)+2-1=f(n-1)+4(n-1)+1

*/
const int maxn = 100;
int dp[maxn] = {0};


// 递归求解
int Function(int n) {
	if (n == 1) return 2;
	else return Function(n-1) + 4*(n-1) + 1;
}


int main(int argc, char *argv[]) {
	int C;
	while (scanf("%d", &C) != EOF) {
		while (C--) {
			int n;
			scanf("%d", &n);
			dp[1] = 2;
			for (int i = 2; i <= n; i++) {
				dp[i] = dp[i-1] + 4 * (i-1) + 1; // 递推动规-嵌套循环-n改成i
			}
			printf("%d\n", dp[n]);
		}
	}
}