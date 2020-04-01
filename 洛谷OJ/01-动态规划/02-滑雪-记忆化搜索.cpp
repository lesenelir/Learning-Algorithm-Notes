#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

对于一个二维的数组来说，找最大值，要往迷宫，记忆化搜索，方向去编写

*/

const int maxn = 102;
int a[maxn][maxn];
int dp[maxn][maxn]; // 点(i,j)出发能走的最长的路径距离
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int r, c;

int DFS(int x, int y) {
	if (dp[x][y] == 1) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int NewX = x + X[i];
		int NewY = y + Y[i];
		// 在边界内，并且新搜索的高度小于之前的高度
		if (NewX > 0 && NewX <= r && NewY > 0 && NewY <= c && a[x][y] > a[NewX][NewY]) {
			DFS(NewX, NewY); // 去搜索
			dp[x][y] = max(dp[x][y], dp[NewX][NewY] + 1);
		}
		
	}
	return dp[x][y];
}


int main() {
	while (scanf("%d %d", &r, &c) != EOF) {
		int ans = 0;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				ans = max(ans, DFS(i, j));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}