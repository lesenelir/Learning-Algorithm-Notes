#include <iostream>
#include <cstdio>
using namespace std;

/*

叠筐 P12

备注：
输出图形用一个缓存数组来存储

*/


int main(int argc, char *argv[]) {
	int n;
	char a, b;
	while (scanf("%d %c %c", &n, &a, &b) != EOF) {
		char matrix[80][80];
		char c;
		int r = 0; // 用来判断用哪个字符
		for (int i = (n + 1) / 2; i >= 1; i--) { // 从最内层开始遍历
			c = (r % 2 == 0) ? a : b;
			for (int j = i; j <= n - i + 1; j++) {
				matrix[i][j] = matrix[n-i+1][j] = c; // 打印横的
				matrix[j][i] = matrix[j][n-i+1] = c; // 打印竖的 有重合
			}
			r++;
		}
		
		// 去除四个角
		if (n != 1) {
			matrix[1][1] = ' ';
			matrix[1][n] = ' ';
			matrix[n][1] = ' ';
			matrix[n][n] = ' ';
		}
		
		// 输出
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%c", matrix[i][j]);
			}
			printf("\n");
		}
	}
}