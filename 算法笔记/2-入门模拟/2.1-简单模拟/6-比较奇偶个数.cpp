#include <iostream>
#include <cstdio>
using namespace std;

/*

第一行输入一个数，为n，第二行输入n个数，这n个数中，如果偶数比奇数多，输出NO，否则输出YES。
输入：
1
67 
7
0 69 24 78 58 62 64 
输出
YES
NO

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int odd = 0; // 奇数
		int even = 0; // 偶数
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				even++;
			} else {
				odd++;
			}
		}
		if (odd > even) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}