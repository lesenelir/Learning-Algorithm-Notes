#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

Senior'sGun P122

用枪最大的减去怪物最小的值，得到的就是价值最大的值

*/
const int maxn = 1010;
int gun[maxn];
int monster[maxn];

bool cmp(int a, int b) {
	return a > b;
}

int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int n, m;
			scanf("%d %d", &n, &m);
			for (int i = 0; i < n; i++) {
				scanf("%d", &gun[i]);
			}
			for (int i = 0; i < m; i++) {
				scanf("%d", &monster[i]);
			}
			sort(gun, gun + n, cmp); // 枪从大到小排序
			sort(monster, monster + m); // 怪物从小到大排序
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (i >= m || gun[i] <= monster[i]) {
					break;
				}
				ans = ans + (gun[i] - monster[i]);
			}
			printf("%d\n", ans);	
		}
	}
}