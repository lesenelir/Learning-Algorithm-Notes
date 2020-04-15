#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/*

剩下的树

*/
const int maxn = 10001;
int a[maxn];

int main() {
	int l, m;
	while (scanf("%d %d", &l, &m) != EOF) {
		memset(a, 0, sizeof(a));
		// 种树
		for (int i = 0; i <= l; i++) {
			a[i] = 1;
		}
		// 移树
		int x, y;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			for (int j = x; j <= y; j++) {
				a[j] = 0;
			}
		}
		// 遍历找存在的树
		int count = 0;
		for (int i = 0; i <= l; i++) {
			if (a[i] == 1) {
				count++;
			}
		}
		printf("%d\n", count);
		
	}
	return 0;
}