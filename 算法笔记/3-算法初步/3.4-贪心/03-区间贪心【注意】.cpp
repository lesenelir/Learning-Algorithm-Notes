#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/*

区间贪心：
区间不相交问题：尽可能的选择多的开区间，使得这些开区间两两不相交

类似于 今年暑假不AC

备注：
区间不重叠问题的贪心思路主要体现在寻找最小的包含区间上，
对于每一块有重合情况的区间，我们只需要找出每一块的重合区间中的最小区间，
就可以组合成不重叠的区间，并且这些区间肯定数目最大

*/

const int maxn = 1010;

struct Inteval {
	int x;
	int y;
}I[maxn];

// 包含区间，被包含的区间肯定左端点要大，右端点要小
bool cmp(Inteval a, Inteval b) {
	if (a.x != b.x) return a.x > b.x; // 左端点大 右端点小
	else return a.y < b.y;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &I[i].x, &I[i].y);
		}
		sort(I, I+n, cmp);
		// ans记录不相交区间的个数，lastX记录上一个被选中区间的左端点
		int ans = 1, lastX = I[0].x;
		for (int i = 1; i < n; i++) {
			if (I[i].y <= lastX) { // 区间右端点在lastX左边，若为区间选点问题则该为I[i].y < lastX
				lastX = I[i].x; // 以I[i]作为新选的区间
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}