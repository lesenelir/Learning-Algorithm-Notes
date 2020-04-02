#include <iostream>
#include <cstdio>
using namespace std;


/*

题目是严格递减最长下降子序列
对于一个偏序集，最少链划分等于最长反链长度。

*/
const int maxn = 100000;
int a[maxn];
int dp1[maxn]; // 一个装置最多拦截多少导弹
int dp2[maxn]; // 最少链划分

int main() {
	int x;
	int n = 0;
	while (scanf("%d", &x) != EOF) {
		a[n] = x;
		n++;
	}
	n--; // 最后一次n会加1
	// 边界
	for (int i = 0; i < n; i++) {
		dp1[i] = 0;
		dp2[i] = 0;
	}
	//状态转移方程
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i] && dp1[j] + 1 > dp1[i]) { // a[j]之前的要高于它
				dp1[i] = dp1[j] + 1;
			}
			if (a[j] < a[i] && dp2[j] + 1 > dp2[i]) { //a[j] < a[i]反链长度
				dp2[i] = dp2[j] + 1;
			}
		}
	}
	//都找最长的长度
	int res1 = 0, res2 = 0;
	for (int i = 1; i < n; i++) {
		if (dp1[i] > dp1[res1]) {
			res1 = i;
		}
		if (dp2[i] > dp2[res2]) {
			res2 = i;
		}
	}
	printf("%d %d\n", dp1[res1], dp2[res2]);
	return 0;
}