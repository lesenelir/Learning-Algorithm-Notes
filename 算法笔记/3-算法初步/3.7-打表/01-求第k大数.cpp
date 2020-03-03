#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

求第k大的数
给定一个长度为n（1≤n≤1,000,000）的无序正整数序列，以及另一个数k（1≤k≤1,000,000）
（关于第k大的数：例如序列{1,2,3,4,5,6}中第3大的数是4。）

第一行两个正整数n，k。
第二行为n个正整数。

输入：
6 3
1 2 3 4 5 6
输出：
4

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int count = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (count != k) {
				count++;
			} else {
				printf("%d\n", a[i]);
				break;
			}
		}
	}
}