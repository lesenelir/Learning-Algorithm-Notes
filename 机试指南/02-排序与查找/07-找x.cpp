#include <iostream>
#include <cstdio>
using namespace std;

/*

找x

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[100];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		int ans = - 1;
		for (int i = 0; i < n; i++) {
			if (a[i] == x) { // 找到 赋值 退出循环
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
}