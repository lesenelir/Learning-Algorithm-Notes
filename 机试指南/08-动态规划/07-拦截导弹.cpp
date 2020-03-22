#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

拦截导弹（北京大学）P230

*/
const int maxn = 1010;
int A[maxn];
int dp[maxn];


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		int ans = -1;
		for (int i = 0; i < n; i++) {
			dp[i] = 1; // 边界
			for (int j = 0; j < i; j++) {
				if (A[j] >= A[i] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
}