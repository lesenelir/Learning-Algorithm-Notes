#include <iostream>
#include <cstdio>
using namespace std;

/*

剩下的树

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int L, M;
	while (scanf("%d %d", &L, &M) != EOF) {
		int a[maxn];
		for (int i = 0; i <= L; i++) { // 种树
			a[i] = 1;
		}
		int x, y;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &x, &y);
			for (int j = x; j <= y; j++) {
				a[j] = 0; // 移树
			}
		}
		int count = 0;
		for (int i = 0; i <= L; i++) { // 统计
			if (a[i] == 1) count++;
		}
		printf("%d\n", count);
	}
}