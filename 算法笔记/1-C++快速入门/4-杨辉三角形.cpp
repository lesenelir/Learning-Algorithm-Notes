#include <iostream>
#include <cstdio>
using namespace std;

/*

输入只包含一个正整数n，输出杨辉三角。
输入：
6
输出：
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

*/


int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int a[n][n];
	// 第0列和对角线赋值
	for (int i = 0; i < n; i++) { 
		a[i][0] = 1;
		a[i][i] = 1;
	}
	// 中间行赋值
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= i-1; j++) { //列循环次数是i-1次 
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	// 输出矩阵
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}