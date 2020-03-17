#include <iostream>
#include <cstdio>
using namespace std;

/*

约数的个数(清华大学) P99

备注：
约数只需要满足能除尽即可，不是要质因数

*/
const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) { // 遍历数组元素的每一个数字进行判断
			int res = 0;
			for (int j = 1; j <= a[i]; j++) {
				if (a[i] % j == 0) res++;
			}
			printf("%d\n", res);
		}	
	}
}