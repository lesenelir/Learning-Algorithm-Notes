#include <iostream>
#include <cstdio>
using namespace std;

/*

HDU 2046 骨牌铺方格


*/
const int maxn = 1010;
int dp[maxn] = {0};


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		printf("%d\n", dp[n]);
	}
}