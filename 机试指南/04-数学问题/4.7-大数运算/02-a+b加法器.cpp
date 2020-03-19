#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


/*

a+b（华中科技大学）P111

*/

const int maxn = 1010;

struct bign {
	int d[1000];
	int len;
	bign () {
		memset(d, 0, sizeof(d));
		len = 0;
	}	
};

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) { // 高位开始输出
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	char A[maxn], B[maxn];
	while (scanf("%s %s", A, B) != EOF) {
		bign a = change(A);
		bign b = change(B);
		bign c = add(a, b);
		print(c);
	}
}