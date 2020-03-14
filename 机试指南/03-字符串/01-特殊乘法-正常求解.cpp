#include <iostream>
#include <cstdio>
using namespace std;

/*

特殊乘法（清华大学）

*/

int main(int argc, char *argv[]) {
	int n1, n2;
	while (scanf("%d %d", &n1, &n2) != EOF) {
		// 把n1进行拆解进数组
		int a[1000], num1 = 0;
		while (n1 != 0) {
			a[num1++] = n1 % 10; // 从个位开始存储
			n1  = n1 / 10;
		}
		// 把n2进行拆解进数组
		int b[1000], num2 = 0;
		while (n2 != 0) {
			b[num2++] = n2 % 10;
			n2 = n2 / 10;
		}
		// 遍历两个数组 求解
		int sum = 0;
		for (int i = 0; i < num1; i++) {
			for (int j = 0; j < num2; j++) {
				sum = sum + a[i] * b[j];
			}
		}
		printf("%d\n", sum);
	}
}