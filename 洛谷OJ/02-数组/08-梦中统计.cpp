#include <cstdio>
#include <iostream>
using namespace std;

/*

梦中统计 运用到哈希

*/

const int maxn = 100001;
int a[maxn], num = 0; // a数组保存数字
int c[10]; // 输出数组 下标代表数字，数组值代表出现次数


int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		for (int i = m; i <= n; i++) {
			a[num++] = i;
		}
		for (int i = 0; i < num; i++) { // 对于数组a当中的某一个数字
			while (a[i] != 0) {
				c[a[i] % 10]++;
				a[i] = a[i] / 10;
			}
		}
		for (int i = 0; i < 10; i++) {
			printf("%d ", c[i]);
		}
		printf("\n");
	}
	
	return 0;
}