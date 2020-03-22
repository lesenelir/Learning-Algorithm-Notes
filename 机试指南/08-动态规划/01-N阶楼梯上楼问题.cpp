#include <iostream>
#include <cstdio>
using namespace std;

/*

N阶楼梯上楼问题（华中科技大学）P223

备注：
类似于Fibonacci数列 (递推方式的动态规划)

dp[n]表示n阶楼梯的上楼方式总数

易错：n是从1开始取的， 边界是不包含0的

*/
const int maxn = 100;
int dp[maxn];


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		printf("%d\n", dp[n]);
	}
}