#include <iostream>
#include <cstdio>
using namespace std;

/*

一个正整数,如果它能被7整除,或者它的十进制表示法中某个位数上的数字为7,
则称其为与7相关的数.现求所有小于等于n(n<100)的与7无关的正整数的平方和。

输入：
6
12
18
输出：
91
601
1575

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			if (i % 7 != 0 && i/10 != 7 && i%10 != 7) {
				sum = sum + i * i;
			}
		}
		printf("%d\n", sum);
	}
}