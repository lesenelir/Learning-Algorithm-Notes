#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

n的阶乘（清华大学）P114

*/
const int maxn = 1010;

struct bign{
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}	
};

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
	while (scanf("%d", &n) != EOF) {
		bign a = change(n);
		for (int i = n - 1; i >= 1; i--) {
			a = multi(a, i);
		}
		print(a);
	}
}