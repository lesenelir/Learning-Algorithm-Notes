#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

A1045 Favorite Color Stripe P390

最长不下降子序列

*/
const int maxc = 210; // 最大颜色数
const int maxn = 1010; // 最大长度L
int LikeTable[maxc]; // 喜欢颜色的数目
int BeltTable[maxn]; // 带子长度
int dp[maxn];
int A[maxn], num = 0;

int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf("%d", &LikeTable[i]);
		}
		int L;
		scanf("%d", &L); // 带子总长度
		for (int i = 0; i < L; i++) {
			scanf("%d", &BeltTable[i]);
		}	
		// 遍历带子长度 按顺序把喜欢的颜色放入新的数组A中
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < m; j++) {
				if (BeltTable[i] == LikeTable[j]) {
					A[num++] = LikeTable[i];
					break;
				}
			}
		}
//		for (int i = 0; i < num; i++) {
//			printf("%d ", A[i]);
//		}
		// 最长不下降子序列模版
		for (int i = 0; i < num; i++) { // 边界
			dp[i] = 1;
		}
		for (int i = 0; i < num; i++) { // 状态转移方程
			for (int j = 0; j < i; j++) {
				if (A[j] <= A[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		int k = 0;
		for (int i = 1; i < num; i++) {
			if (dp[i] > dp[k]) {
				k = i;
			}
		}
		printf("%d\n", dp[k]);	
	}
}