#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/*

货币系统
编写一个程序来计算有多少种方法用给定的货币系统来构造一定数量的面值
输入包含多组测试数据

货币系统中货币的种类数目是 V 。 (1<= V<=25)
要构造的数量钱是 N 。 (1<= N<=10,000)

第 1 行:	 二整数， V 和 N
第 2 ..V+1行：	可用的货币 V 个整数　(每行一个　每行没有其它的数)。

输入：
3 10
1 2 5
输出：
10

设dp[i,j]表示用前i种硬币能表示j数量货币的方法数：

*/


int main(int argc, char *argv[]) {
	int V, n;
	while (scanf("%d %d", &V, &n) != EOF) {
		int money[100];
		int dp[100];
		for (int i = 0; i < V; i++) {
			scanf("%d", &money[i]);
		}
		sort(money, money + V);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < V; i++) {
			for (int j = money[i]; j <= n; j++) {
				dp[j] = dp[j] + dp[j-money[i]];
			}
		}
		printf("%d\n", dp[n]);
	}
}