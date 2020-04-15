#include <cstdio>
#include <iostream>
using namespace std;


const int maxn = 10001;
int a[maxn];
int num = 1;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		a[0] = n; // 数组第一位存放本事数
		while (true) {
			if (n == 1) break;
			if (n % 2 == 1) {
				n = 3 * n + 1;
				a[num++] = n;
			} else {
				n = n / 2;
				a[num++] = n;
			}
		}	
		for (int i = num - 1; i >= 0; i--) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}