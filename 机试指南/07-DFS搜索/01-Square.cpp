#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

Square 拼凑正方形 P146

*/
const int maxn = 25;
int side; // 边长
int m; // 树枝数目
int sticks[maxn];
bool visit[maxn];

bool cmp(int a, int b) {
	return a > b;
}



bool DFS(int sum, int number, int position) {//当前拼凑的木棍长度,已拼凑边长数目,当前木棍编号
	if (number == 3) {
		return true;
	}
	int sample = 0;
	for (int i = position; i < m; i++) {
		if (visit[i] == true || sum + sticks[i] > side || sticks[i] == sample) {
			continue;	
		} 
		visit[i] = true; // 凑成一条边
		if (sum + sticks[i] == side) {
			if (DFS(0, number + 1, 0)) {
				return true;
			} else {
				sample = sticks[i];
			}
		} else {
			if (DFS(sum + sticks[i], number, i + 1)) {
				return true;
			} else {
				sample = sticks[i];
			}
		}
		visit[i] = false;
	}
	return false;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			int length = 0; // 总长
			scanf("%d", &m); // 木棍数量
			for (int i = 0; i < n; i++) {
				scanf("%d", &sticks[i]);
				length = length + sticks[i];
			}
			memset(visit, false, sizeof(visit));
			if (length % 4 != 0) {
				printf("NO\n");
				continue;
			}
			side = length / 4;
			sort(sticks, sticks + m, cmp); // 大到小排序
			if (sticks[0] > side) { // 最大的木棍长度已经大于边长
				printf("NO\n");
				continue;
			}
			if (DFS(0, 0, 0)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
}