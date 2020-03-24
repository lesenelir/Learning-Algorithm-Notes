#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

A1040 longest symmetric String P394 
最长回文子串
dp[i][j]表示S[i]到S[j]子串是否为回文子串 是则1 不是则0
S[i] == S[j] 只要看S[i+1]到S[j-1]是否为回文子串

*/
const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];


int main(int argc, char *argv[]) {
	gets(S);
	int len = strlen(S);
	int ans = 1;
	memset(dp, 0, sizeof(dp));
	// 边界
	for (int i = 0; i < len; i++) {
		dp[i][i] = 1;
		if (i < len - 1) {
			if (S[i] == S[i+1]) {
				dp[i][i+1] = 1;
				ans = 2;
			}
		}
	}
	// 状态转移方程
	for (int L = 3; L <= len; L++) { // 【注意】是小于等于L
		for (int i = 0; i + L - 1 < len; i++) { // 枚举子串起始端点
			int j = i + L - 1; // 子串的右端点
			if (S[i] == S[j] && dp[i+1][j-1] == 1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d\n", ans);
}