#include <iostream>
#include <cstdio>
using namespace std;

/*

打印极值点下标（北京大学）

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		// 单独判断第一个元素
		if (a[0] != a[1]) {
			printf("0 ");
		}
		// 判断中间的元素
		for (int i = 1; i < n - 1; i++) {
			if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) {
				printf("%d ", i);
			}
		}
		//单独判断最后一个元素
		if (a[n-2] != a[n-1]) {
			printf("%d ", n-1);
		}
		printf("\n");
	}
}