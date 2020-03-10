#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

特殊排序

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		if (n == 1) {
			printf("%d\n-1\n", a[0]);
		} else { 
			printf("%d\n", a[n-1]);
			for (int i = 0; i < n - 1; i++) {
				printf("%d ", a[i]);
			}
		}
	}
}