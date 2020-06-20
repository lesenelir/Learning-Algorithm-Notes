#include <iostream>
#include <algorithm>
using namespace std;

const int n = 5;
const int maxn = 100;
int dp[maxn][maxn];
int f[maxn][maxn];

int main(int argc, char *argv[]) {
	//读入
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &f[i][j]);
		}
	}
	//边界
	for (int j = 1; j <= n; j++) {
		dp[n][j] = f[n][j];
	}
	//转移方程
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
		}
	}
	printf("%d\n", dp[1][1]);
}