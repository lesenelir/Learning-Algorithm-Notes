#include <iostream>
#include <cstdio>
using namespace std;

/*

编写一个求斐波那契数列的递归函数，输入n 值，使用该递归函数，输出如下图形（参见样例）
输入第一行为样例数m，接下来有m行每行一个整数n，n不超过10。

输入：
1
6
输出：
		  0
		0 1 1
	  0 1 1 2 3
	0 1 1 2 3 5 8
  0 1 1 2 3 5 8 13 21
0 1 1 2 3 5 8 13 21 34 55

备注：
一定是要在

*/


int Fibonacci(int n) {
	if (n == 1 || n == 2) return 1;
	else return Fibonacci(n-1) + Fibonacci(n-2);
}


int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			int n;
			scanf("%d", &n);
			int row = n, col = 2 * n - 1; // 行数、列数，行数列数的数组下标从1开始计算
			
			for (int i = 1; i <= n; i++) { // 遍历行
				for (int j = 1; j <= n-i; j++) { // 前序空格
					printf("  ");
				}
				
				printf("0 ");
				if (i > 1) { // 不是第一行时
//					for (int j = n-i+2; j < 2*i; j++) { // 中间输出数字组
//						int temp = Fibonacci(j);
//						printf("%d ", temp);
//					}	
					for (int j = 1; j <= 2*i-2; j++) {
						int temp = Fibonacci(j);
						printf("%d ", temp);
					}
				}
				
				for (int j = 1; j <= n-i; j++) { // 后序空格
					printf("  ");
				}
				
				printf("\n"); // 一行结束换行
			}
					
		}
	}
}