#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*

明明的随机数
去重排序 运用哈希的思想来去重复

*/

const int maxn = 1000;
int a[maxn] = {0};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int x;
		int count = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			if (a[x] == 0) {
				a[x] = x;
				count++;
			}
		}
		printf("%d\n", count);
		for (int i = 0; i < maxn; i++) {
			if (a[i] != 0) {
				printf("%d ", a[i]);
			}
		}
	}
	return 0;
}