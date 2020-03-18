#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
比如，如下4 * 4的矩阵

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

的最大子矩阵是

9 2
-4 1
-1 8

这个子矩阵的大小是15。

输入是一个N * N的矩阵。输入的第一行给出N (0 < N <= 100)。
再后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）给出矩阵中的N2个整数，整数之间由空白字符分隔（空格或者空行）。


备注：
数组b表示数组a的i ~ j行，对应列元素的和

*/
const int maxn = 1010;
int a[maxn][maxn];
int b[maxn];

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int res = -1;
		for (int i = 0; i < n; i++) {
			//数组b表示i~j行，对应列元素的和
			//将二维动态规划问题转化为一维动态规划问题
			memset(b, 0, sizeof(b));
			for (int j = i; j < n; j++) { // 往下求数组b，j也表示行
				int sum = 0;
				for (int k = 0; k < n; k++) { // 列
					b[k] = b[k] + a[j][k];
					sum = sum + b[k];
					if (sum < 0) sum = b[k];
					if (sum > res) res = sum;	
				}
			}
		}
		printf("%d\n", res);
	}
}