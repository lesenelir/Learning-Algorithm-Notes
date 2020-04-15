#include <cstdio>
#include <iostream>
using namespace std;

/*

连续和最小

*/

const int maxn = 10001;
int a[maxn];


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int res_min = 100000000; // 初始设置输出最小值是一个很大的数字
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n - m + 1; i++) { // 符合要求的数字 最后m-1数字不记录
			int temp = 0;
			for (int j = i; j <= i + m - 1; j++) {
				temp = temp + a[j];
			}
			if (temp < res_min) res_min = temp;
		}
		printf("%d\n", res_min);
	}
	return 0;
}