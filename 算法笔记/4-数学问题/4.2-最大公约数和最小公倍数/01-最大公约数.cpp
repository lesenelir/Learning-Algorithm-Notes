#include <iostream>
#include <cstdio>

using namespace std;


/*

公约数：a,b当中能整除的的数字；最大公约数：a,b当中能整除最大的那个数字
递归式：gcd(a, b) = gcd (b, a % b);
递归边界：gcd(a, 0) = a;

int d = gcd(a, b); // d是最大公约数
int res = a * b / d; // res是最小公倍数 或者 a / d * b;

*/


// 最大公约数递归版本
int gcd(int a, int b) { 
	if (b == 0) return a;
	else return gcd(b, a % b);
}


// 最大公约数非递归版本
int gcd_no(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}


int main(int argc, char *argv[]) {
	int m, n;
	while (scanf("%d %d", &n, &m) != EOF) {
		printf("%d\n", gcd(n, m));
	}
}