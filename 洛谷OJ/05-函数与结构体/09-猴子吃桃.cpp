#include <cstdio>
#include <iostream>
using namespace std;


int main() {
	int n;
	int ans = 1;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i < n; i++) { // 第一天开始吃一直吃到第n-1天
			ans = ans + 1;
			ans = ans * 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}