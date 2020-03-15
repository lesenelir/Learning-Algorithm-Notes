#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

给定K个整数的序列{ N1, N2, ..., NK }，其任意连续子序列可表示为{ Ni, Ni+1, ..., Nj }，其中 1 <= i <= j <= K。最大连续子序列是所有连续子序列中元素和最大的一个，例如给定序列{ -2, 11, -4, 13, -5, -2 }，其最大连续子序列为{ 11, -4, 13 }，最大和为20。现在增加一个要求，即还需要输出该子序列的第一个和最后一个元素。当K为0时，输入结束，该用例不被处理。

在1行里输出最大和、最大连续子序列的第一个和最后一个元素，中间用空格分隔。如果最大连续子序列不唯一，则输出序号i和j最小的那个（如输入样例的第2、3组）。若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。

输入：
5
-3 9 -2 5 -4
3
-2 -3 -1
0
输出：
12 9 5
0 -2 -1

*/
const int maxn = 1010;
int dp[maxn];
int A[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		bool flag = false;
		// 输入序列
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			if (A[i] > 0) flag = true;
		}
		
		if (flag == false) { // 序列全部都是负数
			printf("%d %d %d\n", 0, A[0], A[n-1]);
		} else {
			// 边界
			dp[0] = A[0];
			// 状态转移方程
			for (int i = 1; i < n; i++) {
				dp[i] = max(A[i], dp[i-1] + A[i]);
			}
			int k = 0; // dp[k]代表序列和最大，k就是结束下标
			for (int i = 1; i < n; i++) {
				if (dp[i] > dp[k]) {
					k = i;
				}
			}
			// 找开始的上标
			int num = 0;
			int s = 0;
			for (int i = k; i >= 0; i--) {
				num = num + A[i];
				if (num == dp[k]) {
					s = i; // 赋值
					break;
				}
			}
			printf("%d %d %d\n", dp[k], A[s], A[k]);
			
		}	
	}
}