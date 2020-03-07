#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

大整数乘法 n的阶乘

*/

struct bign {
	int d[1000];
	int len;
	bign () {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

// 把整形数字转换为bign类型
bign change(int n) {
	bign a;
	while (n != 0) {
		a.d[a.len++] = n % 10;
		n = n / 10;
	}
	return a;
}

bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) {
		c.d[c.len++] = carry % 10;
		carry = carry / 10;
	}
	return c;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n");
}



int main(int argc, char *argv[]) {
	int n;
	while (scanf ("%d", &n) != EOF) {
		if (n == 0) printf("1\n");
		else {
			bign a = change(n);
			for (int i = n - 1; i >= 1; i--) { //从n-1一直乘到1
				a = multi(a, i);
			}
			print(a);
		}
	}
}