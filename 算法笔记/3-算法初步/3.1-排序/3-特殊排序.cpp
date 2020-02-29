#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。
输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。接下来的一行有N个整数。

输入：
5
5 3 2 4 1
输出：
1 2 3 4 

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		for (int i = 0; i < n-1; i++) { // 最大的存储在最后，不要遍历出来
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}