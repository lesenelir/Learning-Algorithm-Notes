#include <iostream>
#include <cstdio>
using namespace std;


/*

输入n个值互不相同的数字，在输入一个x，输出这个值在数组中的下标
输入：
4
1 2 3 4
3
输出：
2

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		int k = 0;
		for (k = 0; k < n; k++) {
			if (a[k] == x) {
				printf("%d\n", k);
				break;
			}
		}
		if (k == n) {
			printf("没有找到\n");
		}
	}
}