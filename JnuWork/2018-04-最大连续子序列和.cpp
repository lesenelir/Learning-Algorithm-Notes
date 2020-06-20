#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[100];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int dp[100];
		dp[0] = a[0];
		for (int i = 0; i < n; i++) {
			dp[i] = max(dp[i-1] + a[i], a[i]);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] > res) {
				res = dp[i];
			}
		}
		printf("%d\n", res);
	}
}