#include <iostream>
#include <cstdio>
using namespace std;

/*

Least Common Multiple
有T组数据 每组首先给一个n 然后有n个数 问这个n个数的最小公倍数

输入：
2
2 3 5
3 4 6 12
输出：
15
12

*/

const int maxn = 1010;

int gcd(int a, int b) { // 最大公约数
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main(int argc, char *argv[]) {
	int T;
	while (scanf("%d", &T) != EOF) {
		while (T--) {
			int n;
			scanf("%d", &n);
			int a[maxn];
			for (int i = 0; i < n; i++) {
				scanf("%d", &a[i]);
			}
			int d;
			int i;
			for (i = 1; i < n; i++) { // 找出a[i-1]与a[i]之间的最小公倍数
				d = gcd(a[i-1], a[i]);
				a[i] = a[i-1] / d * a[i]; // a / d * b;
			}
			printf("%d\n", a[i-1]);
		}
	}
}