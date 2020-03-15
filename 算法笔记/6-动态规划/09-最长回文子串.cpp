#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

最长回文子串（二维）

备注：
dp[i][j]表示S[i]到S[j]所表示的子串是否是回文子串，是则1，不是则0

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
	for (int L = 3; L <= len; L++) {
		for (int i = 0; i + L - 1 < len; i++) {
			int j = i + L - 1;
			if (S[i] == S[j] && dp[i+1][j-1] == 1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d\n", ans);
}