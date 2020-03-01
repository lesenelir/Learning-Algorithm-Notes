#include <iostream>
#include <cstdio>

using namespace std;

/*

判断某一个数字在某一数组中出现的次数。
散列思想：
用数组的下标表示待处理的数字，用数组的元素值代表出现的次数或者是否出现过


*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
		int x;
		int hashtable[maxn] = {0};
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			hashtable[x]++;
		}
		
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			printf("%d\n", hashtable[x]);
		}
	}
}