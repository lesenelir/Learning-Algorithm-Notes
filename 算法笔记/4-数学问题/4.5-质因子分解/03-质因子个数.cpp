#include <iostream>
#include <cstdio>
using namespace std;

/*

质因数的个数
求正整数N(N>1)的质因数的个数。
相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。

输入：
120 
200
输出：
5
5

*/


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int num = 0;
		for (int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				n = n / i; // 分解质因子关键步骤
				num++;
			}
		}
		if (n != 1) num++;
		printf("%d\n", num);
	}
}