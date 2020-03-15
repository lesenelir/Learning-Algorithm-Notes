#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

最长公共子序列（二维）
给你一个序列X和另一个序列Z，当Z中的所有元素都在X中存在，并且在X中的下标顺序是严格递增的，那么就把Z叫做X的子序列。
例如：Z=<a,b,f,c>是序列X=<a,b,c,f,b,c>的一个子序列，Z中的元素在X中的下标序列为<1,2,4,6>。

输入：
sadstory
adminsorry
----
abcfbc 
abfcab
----
programming 
contest 
-----
abcd 
mnp
输出：
6
4
2
0

备注：
dp[i][j]代表字符串A的i号位和字符串B的j号位之前的公共子序列长度

*/
const int maxn = 1010;
int dp[maxn][maxn];
char A[maxn], B[maxn];

int main(int argc, char *argv[]) {
	gets(A + 1); // 从下标1开始读入
	gets(B + 1);
	int lenA = strlen(A + 1); //读入下标1开始，读取长度也从1开始
	int lenB = strlen(B + 1);
	// 边界
	for (int i = 0; i <= lenA; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= lenB; j++) {
		dp[0][j] = 0;
	}
	// 状态转移方程
	for (int i = 1; i <= lenA; i++) { // 从1开始
		for (int j = 1; j <= lenB; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	printf("%d\n", dp[lenA][lenB]);
}