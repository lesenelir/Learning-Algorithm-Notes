#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*

分数矩阵
我们定义如下矩阵：
1/1 1/2 1/3
1/2 1/1 1/2
1/3 1/2 1/1
矩阵对角线上的元素始终是1/1，对角线两边分数的分母逐个递增。
请求出这个矩阵的总和。

输入包含多组测试数据。每行给定整数N（N<50000），表示矩阵为N*N。当N=0时，输入结束。
输出答案，结果保留2位小数。

输入：
1
2
3
4
0
输出：
1.00
3.00
5.67
8.83

备注：
本题实质就是一个找规律的题目

*/


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		double sum = 0;
		sum = sum + n * 1; // 计算对角线
		for (int i = 2; i <= n; i++) {
			sum = sum + (1.0 / i) * (2 * (n-i+1)); // 计算后面除对角线元素和
		}
		printf("%.2f\n", sum);
	}
}