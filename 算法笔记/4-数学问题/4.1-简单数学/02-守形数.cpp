#include <iostream>
#include <cstdio>
using namespace std;

/*

守形数是这样一种整数，它的平方的低位部分等于它本身。 比如25的平方是625，低位部分是25，因此25是一个守形数。 编一个程序，判断N是否为守形数

输入：
25
4
输出：
Yes!
No!

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int ans = n * n;
		while (n != 0) {
			if (n % 10 != ans % 10) { // 从后位开始往前遍历比较
				printf("No!\n");
				break;
			}
			ans = ans / 10;
			n = n / 10;
		}
		if (n == 0) printf("Yes!\n"); // n == 0 n的各个位数都已经比较完
	}
}