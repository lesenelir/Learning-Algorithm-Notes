#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*

三角形
7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(Figure 1)
Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right. 
Input

Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
Output

Your program is to write to standard output. The highest sum is written as an integer.
Sample Input
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
Sample Output
30


备注：
类似于数塔

*/
const int maxn = 1010;
int a[maxn][maxn];
int dp[maxn][maxn];


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		// 边界
		for (int j = 1; j <= n; j++) {
			dp[n][j] = a[n][j];
		}
		// 状态转移方程
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
			}
		}
		printf("%d\n", dp[1][1]);
		
	}
	
	
}