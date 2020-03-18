#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，
则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。
第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
输出最少需要几位同学出列。

输入：
3
174 208 219 
6
145 206 193 171 187 167 
0
输出：
0
1

备注：
枚举每个位置，从左边找最长上升子序列，从右边开始找最长下降子序列，两个数相加就是题目所说的唱歌的人数。
以某个学生为中心 两边最长不上升子序列长度最大

*/
const int maxn = 1010;
int A[maxn];
int dp1[maxn];
int dp2[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		// 从前往后枚举每位的最长上升子序列长度
		int ans1 = -1;
		for (int i = 0; i < n; i++) {
			dp1[i] = 1;
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i] && dp1[j] + 1 > dp1[i]) {
					dp1[i] = dp1[j] + 1;
				}
			}
			ans1 = max(ans1, dp1[i]);
		}
		// 从后往前枚举每位的最长上升子序列长度
		int ans2 = -1;
		for (int i = n-1; i >= 0; i--) { // 从后往前上升序列
			dp2[i] = 1;
			for (int j = n-1; j > i; j--) {
				if (A[j] < A[i] && dp2[j] + 1 > dp2[i]) {
					dp2[i] = dp2[j] + 1;
				}
			}
			ans2 = max(ans2, dp2[i]);
		}
		
		int total = -1;// 此时dp1 dp2均保存了每位的最大值
		for (int i = 0; i < n; i++) {
			total = max(dp1[i] + dp2[i] - 1, total);//当前在i位置，dp1[i]里面包含i位，而dp2[i]也包含i为，所以要减去1
		}
		printf("%d\n", n-total);
	}
}