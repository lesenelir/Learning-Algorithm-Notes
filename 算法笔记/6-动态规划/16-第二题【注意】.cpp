#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

第二题

一个数组中有若干正整数，将此数组划分为两个子数组，使得两个子数组各元素之和a,b的差最小，对于非法输入应该输出ERROR。
降序输出两个子数组的元素和

输入：
10 20 30 10 10
10 20 abc 10 10
输出：
40 40
ERROR


思路：
全部为数字的数组求和为sum，分出一个数组使其重量接近sum/2
随后从0~n-1物品中选取若干个，其重量不超过sum/2,且重量达最大
dp[i]表示在在重量不超过i时，所能达到的重量最大值

备注：
类似于01背包问题，要注意输入格式的转换

*/
const int maxn = 1010;


int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		bool flag = true;
		int a[maxn], n = 0;
		for (int i = 0; i < len; i++) { // 【关键转换】
			if (str[i] == ' ') continue;
			else {
				if (str[i] >= '0' && str[i] <= '9') { // str[i]是数字
					int temp = 0;
					temp = temp * 10 + (str[i] - '0');
					int j = i + 1;
					while (str[j] >= '0' && str[j] <= '9') {
						temp = temp * 10 + (str[j] - '0');
						j++;
					}
					a[n++] = temp;
					i = j; // 此时已经遍历到j位置，故下次遍历i从j开始遍历
				} else {
					flag = false;
				}
			}
		}
		if (flag == false) {
			printf("ERROR\n");
		} else {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum = sum + a[i];
			}
			int V = sum / 2;
			int dp[maxn];
			// 边界
			for (int v = 0; v <= V; v++) {
				dp[v] = 0;
			}
			// 状态转移方程
			for (int i = 0; i < n; i++) {
				for (int v = V; v >= a[i]; v--) { // 重量和价值均为a[i]
					dp[v] = max(dp[v], dp[v - a[i]] + a[i]);
				}
			}
			// dp[i]表示不超过i的最能装体积的最大值
			printf("%d %d\n", sum - dp[sum / 2], dp[sum / 2]);
		}
	}
}