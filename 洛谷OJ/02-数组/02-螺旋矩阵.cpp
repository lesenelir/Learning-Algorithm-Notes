#include <iostream>
#include <cstdio>
using namespace std;


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[101][101];
		int num = 1;
		for (int i = 0; i < n / 2; i++) { // 层数
			for (int j = i; j < n - i; j++) {
				a[i][j] = num++;
			}
			for (int j = i + 1; j < n - i; j++) {
				a[j][n-i-1] = num++;
			}
			for (int j = n - i - 2; j > i; j--) {
				a[n-i-1][j] = num++;
			}
			for (int j = n - i - 1; j > i; j--) {
				a[j][i] = num++;
			}
		}
		// 输出
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%3d", a[i][j]);
			}
			if (i < n) printf("\n");
		}
	}
	
	return 0;
}