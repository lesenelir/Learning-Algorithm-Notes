#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

北大网络实验室经常有活动需要叫外买，但是每次叫外买的报销经费的总额最大为C元，有N种菜可以点，经过长时间的点菜，网络实验室对于每种菜i都有一个量化的评价分数（表示这个菜可口程度），为Vi，每种菜的价格为Pi, 问如何选择各种菜，使得在报销额度范围内能使点到的菜的总评价分数最大。
	注意：由于需要营养多样化，每种菜只能点一次。

输入的第一行有两个整数C（1 <= C <= 1000）和N（1 <= N <= 100），C代表总共能够报销的额度，N>代表能点菜的数目。接下来的N行每行包括两个在1到100之间（包括1和100）的的整数，分别表示菜的>价格和菜的评价分数。

输出只包括一行，这一行只包含一个整数，表示在报销额度范围内，所点的菜得到的最大评价分数。

输入：
1 3
1 5
3 3
2 5
24 8
2 9
8 6
4 1
1 4
2 2
10 5
2 1
1 4
输出：
5
30

备注：
01背包：在不超过总重量V的情况下尽可能使价值最大
点菜问题：在不超过报销范围内C的情况下尽可能使总评价分数最大

*/
const int maxn = 1010;

int main(int argc, char *argv[]) {
	int C, N; // 可报销的范围C就是01背包中的总体积V
	while (scanf("%d %d", &C, &N) != EOF) {
		int v, p;
		int dp[maxn];
		// 边界
		for (int i = 0; i <= C; i++) {
			dp[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &v, &p);
			for (int j = C; j >= v; j--) {
				dp[j] = max(dp[j], dp[j-v] + p);
			}
		}
		printf("%d\n", dp[C]); // dp[V]
	}
}