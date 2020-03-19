#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

n的阶乘（清华大学）P114

*/
const int maxn = 1010;

struct bign{
	int d[1000]; //数字值
	int len; //结构体长度
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

//低位转换为高位，字符转换为数字
bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len-i-1] - '0'; //a中的d数组低位是char数组的高位
	}
	return a;
}

//数组和数字相乘
bign multi(bign a, int b ) {
	bign c;
	int carry = 0;//进位
	for (int i = 0; i < a.len; i ++) {
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

//从高位打印a
void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	char str[maxn];
	while (scanf("%s", str) != EOF) {
		bign a = change(str);
		int n = 0;
		for (int i = a.len - 1; i >= 0; i--) {
			n = n * 10 + a.d[i];
		}
		for (int i = n - 1; i >= 1; i--) { // 阶乘
			a = multi(a, i);
		}
		print(a);
	}

}