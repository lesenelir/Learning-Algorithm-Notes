#include <iostream>
#include <cstdio>
using namespace std;
/*
	题目描述 Description
		某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

	输入描述 Input Description
	输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）

	输出描述 Output Description

	输出这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

	样例输入 Sample Input
	8
	389 207 155 300 299 170 158 65 

	样例输出 Sample Output
	6 2
*/

//题目是严格递减最长下降子序列
//对于一个偏序集，最少链划分等于最长反链长度。
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[1001];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		//边界
		int dp1[1001], dp2[1001];
		for (int i = 0; i < n; i++) {
			dp1[i] = 1;
			dp2[i] = 1;
		}
		//状态转移方程
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i] && dp1[j] + 1 > dp1[i]) {
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
	}	
	return 0;
}