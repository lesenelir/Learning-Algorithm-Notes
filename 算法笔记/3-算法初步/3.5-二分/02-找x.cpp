#include <iostream>
#include <cstdio>
using namespace std;


/*

输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。

*/


int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		for (int i = 0; i < n; i++) {
			if (a[i] == x) {
				printf("%d\n", i);
				break;
			}
			if (i == n-1) { // 当i遍历到数组最后一位还不满足a[i] == x
				printf("-1\n");
			}
		}
	}
}