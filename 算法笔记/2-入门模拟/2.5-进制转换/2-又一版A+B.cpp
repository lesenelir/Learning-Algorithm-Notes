#include <iostream>
#include <cstdio>
using namespace std;

/*

输入两个不超过整型定义的非负10进制整数A和B(<=231-1)，输出A+B的m (1 < m <10)进制数。
输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
当m为0时输入结束。

输入：
2 4 5
8 123 456
0
输出：
1001
1103

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int m, A, B;
	while (scanf("%d", &m) != EOF) {
		if (m == 0) break;
		scanf("%d %d", &A, &B);
		int sum = A + B;
		int a[maxn];
		int num = 0;
		// do while 循环可以考虑0的情况
		do { 
			a[num++] = sum % m;
			sum = sum / m;
		}while (sum != 0);
		for (int i = num - 1; i >= 0; i--) {
			printf("%d", a[i]);
		}
		printf("\n");
	}
}