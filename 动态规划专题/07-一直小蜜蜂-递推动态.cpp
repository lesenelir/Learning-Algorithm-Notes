#include <iostream>
#include <cstdio>
using namespace std;

/*

一只小蜜蜂 HDU2044

类似于fibonacci数列
f(n) = f(n-1) + f(n-2)

*/
const int maxn = 1010;
int dp[maxn] = {0};


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			int a, b;
			scanf("%d %d", &a, &b);
			int k = b - a;
			dp[1] = 1;
			dp[2] = 2;
			for (int i = 3; i <= k; i++) {
				dp[i] = dp[i-1] + dp[i-2];
			}
			printf("%d\n", dp[k]);
		}
	}
}