#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1001;
int a[maxn][maxn];
int dp[maxn][maxn];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int j = 1; j <= n; j++) {
			dp[n][j] = a[n][j];
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
			}
		}
		printf("%d\n", dp[1][1]);
	}
	return 0;
}