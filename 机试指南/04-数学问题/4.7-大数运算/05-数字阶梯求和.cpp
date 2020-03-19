#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

数字阶梯求和（哈尔滨工业大学）P116
给定a和n，计算a+aa+aaa+a...a(n个a)的和

*/
const int maxn = 1010;


int main(int argc, char *argv[]) {
	int a, n;
	while (scanf("%d %d", &a, &n) != EOF) {
		char str[maxn];
		int carry = 0;
		for (int i = n; i >= 1; i--) {
			str[i] = ((i * a) + carry) % 10;
			carry = ((i * a) + carry) / 10;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d", str[i]);
		}
	}
}