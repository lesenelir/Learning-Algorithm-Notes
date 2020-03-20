#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

今年暑假不AC P124

看电视问题

备注：
区间不相交问题：尽可能的选择开区间，使得这些开区间两两没有交集
区间选点问题：n个闭区间，求最少需要多少个点使每个区间至少存在一个点 arr[i].y < lastX


*/
const int maxn = 1010;

struct program {
	int x;
	int y;	
} arr[maxn];

bool cmp(program a, program b) { // 左端点从大到小，右端点从小到大排序
	if (a.x != b.x) return a.x > b.x;
	else return a.y < b.y;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &arr[i].x, &arr[i].y);
		}
		sort(arr, arr + n, cmp);
		// ans记录不相交区间的个数，lastX记录上一个被选中区间的左端点
		int ans = 1, lastX = arr[0].x;
		for (int i = 1; i < n; i++) {
			if (arr[i].y <= lastX) {
				lastX = arr[i].x;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}