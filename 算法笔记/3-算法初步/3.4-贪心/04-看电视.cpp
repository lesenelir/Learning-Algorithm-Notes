#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*

暑假到了，小明终于可以开心的看电视了。但是小明喜欢的节目太多了，他希望尽量多的看到完整的节目。

输入包含多组测试数据。每组输入的第一行是一个整数n（n<=100），表示小明喜欢的节目的总数。
接下来n行，每行输入两个整数si和ei（1<=i<=n），表示第i个节目的开始和结束时间，当n=0时，输入结束。

输入：
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
输出：
5

思想：
类似于区间贪心，区间不重叠问题

*/

const int maxn = 1010;

struct Programs{
	int x;
	int y;
}pro[maxn];

bool cmp(Programs a, Programs b) {
	if (a.x != b.x) return a.x > b.x;
	else return a.y < b.y;
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &pro[i].x, &pro[i].y);
		}
		sort(pro, pro + n, cmp);
		int ans = 1, lastX = pro[0].x;
		for (int i = 1; i < n; i++) {
			if (pro[i].y <= lastX) {
				lastX = pro[i].x;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}