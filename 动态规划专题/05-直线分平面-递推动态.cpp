#include <iostream>
#include <cstdio>
using namespace std;

/*

直线分平面

题目大致如:n条直线，最多可以把平面分为多少个区域。

f(n) = f(n-1) + n


*/
const int maxn = 100;
int dp[maxn] = {0};


// 递归求解
int Function(int n) {
	if (n == 1) return 2;
	else return Function(n-1) + n;
}



int main(int argc, char *argv[]) {
	int C;
	while (scanf("%d", &C) != EOF) {
		while (C--) {
			int n;
			scanf("%d", &n);
			dp[1] = 2;
			// 嵌套循环就是把递归的function(n)改成循环嵌套下的dp[i]
			for (int i = 2; i <= n; i++) { 
				dp[i] = dp[i-1] + i;
			}
			printf("%d\n", dp[n]);
		}
	}
}