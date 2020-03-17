#include <iostream>
#include <cstdio>
using namespace std;

/*

计算两个矩阵的乘积（哈尔滨工业大学）P102

*/

int main(int argc, char *argv[]) {
	int a[2][3];
	int b[3][2];
	int c[2][2];
	// 输入矩阵a
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	// 输入矩阵b
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	// 矩阵相乘
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c[i][j] = 0; // 赋值0
			for (int k = 0; k < 3; k++) { // 内标
				c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
			}
		}
	}
	
	// 输出矩阵c
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}