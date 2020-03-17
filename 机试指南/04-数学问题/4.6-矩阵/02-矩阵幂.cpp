#include <iostream>
#include <cstdio>
using namespace std;

/*

矩阵幂（北京邮件大学）P104

*/



int main(int argc, char *argv[]) {
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		int a[n][n], b[n][n];
		// 输入矩阵
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		// 矩阵相乘k次
		while (k--) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					b[i][j] = 0;
					for (int k = 0; k < n; k++) { // 内标
						b[i][j] = b[i][j] + (a[i][k] * a[k][j]);
					}
				}
			}
		}
		// 输出矩阵
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
	}
}