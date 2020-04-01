#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1001;
int w[maxn];
int c[maxn];
int dp[maxn];

int main() {
	int V, n;
	while (scanf("%d %d", &V, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &w[i], &c[i]);
		}
		for (int v = 0; v <= V; v++) {
			dp[v] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int v = V; v >= w[i]; v--) {
				dp[v] = max(dp[v], dp[v-w[i]] + c[i]);
			}
		}
		printf("%d\n", dp[V]);
	}
	return 0;
}