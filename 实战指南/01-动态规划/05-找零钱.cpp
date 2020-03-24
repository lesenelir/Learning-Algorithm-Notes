#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

A1068 Find More Coins P396

*/
const int maxn = 1010;
const int maxv = 100;
int w[maxn], dp[maxv] = {0};
bool choice[maxn][maxn], flag[maxn];

bool cmp(int a, int b) {
	return a > b;
}


int main(int argc, char *argv[]) {
	int n,V;
	while (scanf("%d %d", &n, &V) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		sort(w, w + n, cmp);
		for (int i = 0; i < n; i++) {
			for (int v = V; v >= w[i]; v--) {
				if (dp[v] <= dp[v-w[i]] + w[i]) {
					dp[v] = dp[v-w[i]] + w[i];
					choice[i][v] = 1; // 放入第i件物品
				} else {
					choice[i][v] = 0; // 不放第i件物品
				}
			}
		}
		if (dp[V] != V) printf("No Solution\n"); // 无解 不能恰好价值为V的方案
		else {
			// 记录最优路径
			int k = n, num = 0, v = V;
			while (k >= 0) {
				if (choice[k][v] == 1) {
					flag[k] = true;
					v = v - w[k];
					num++;
				}
				else flag[k] = false;
				k--
			}		
			// 输出方案
			for (int i = n-1; i >= 0; i--) {
				if (flag[i] == true) {
					printf("%d", w[i]);
					num--;
					if (num > 0) printf(" ");
				}
			}
		}	
	}
}