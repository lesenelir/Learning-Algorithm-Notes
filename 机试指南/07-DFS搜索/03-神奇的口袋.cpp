#include <iostream>
#include <cstdio>
using namespace std;

/*

神奇的口袋（北京大学）

*/
const int maxn = 100;
int w[maxn];
int n;

/*

①物品n个，物品体积逐一放入w[100]中
②递归函数count(i,sum)=count(i+1,sum-a[i])+count(i+1,sum);
其中，i为第i个物品，sum代表剩余空缺体积数
count(i+1,sum-a[i]) 代表从第i+1个物品开始，剩余体积数为sum-a[i]的方案数
（隐含：已经将a[i]的体积计算进去，即包含a[i]的体积） 
count(i+1,sum) 代表从第i+1个物品开始，剩余体积数为sum的方案数
（隐含：不将a[i]的体积计算进去，即不包含a[i]的体积）

*/
int count(int i, int sum) { // 第i个物体，剩余空缺体积数sum
	if (sum == 0) return 1;
	if (i == n || sum < 0) return 0;
	return count(i+1, sum) + count(i+1, sum - w[i]);
}


int main(int argc, char *argv[]) {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		int res = count(0, 40);
		printf("%d\n", res);
	}
}