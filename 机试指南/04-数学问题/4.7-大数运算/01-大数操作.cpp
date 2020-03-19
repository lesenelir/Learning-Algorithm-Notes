#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}	
};

// 字符串保存位bign类型
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
		c.d[c.len++] = temp % 10; // 个位作为结果
		carry = temp / 10; // 十位进位
	}
	if (carry != 0) {
		c.d[c.len++] = carry; // 进位不为0则直接赋给最高位
	}
	return c;
}

bign sub(bign a, bign b) {
	bign c;
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i]) { // 不够减
			a.d[i+1]--; // 高位减1
			a.d[i] = a.d[i] + 10; // 当前为加10
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) { // 结果至少保存一位，并且最高位为零时
		c.len--;
	}
	return c;
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


int main(int argc, char *argv[]) {
	
}