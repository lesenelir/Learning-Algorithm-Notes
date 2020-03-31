#include <iostream>
#include <cstdio>
using namespace std;

/*

超级楼梯 HDU2041

类似于fibonacci数列

*/
const int maxn = 1010;
int dp[maxn];


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			int m;
			scanf("%d", &m);
			dp[1] = 0;
			dp[2] = 1;
			dp[3] = 2;
			for (int i = 4; i <= m; i++) {
				dp[i] = dp[i-1] + dp[i-2];
			}
			printf("%d\n", dp[m]);
		}
	}
}