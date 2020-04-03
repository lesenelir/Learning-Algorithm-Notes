#include <iostream>
#include <cstdio>
using namespace std;

/*

输出图案矩阵可以创造一个数组来

*/

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[101][101];
		for (int i = 1; i <= n; i++) {
			a[i][1] = 1;
			a[i][i] = 1;
		}
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= i - 1; j++) {
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}