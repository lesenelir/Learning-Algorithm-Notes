#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

大整数运算
235813
d[0] = 3
str[0] = 2

*/

struct bign {
	int d[1000];
	int len;
	bign () {
		memset(d, 0, sizeof(d));
		len = 0;
	}	
};

bign change(char str[]) { // 字符数组存储整数转换成bign类型
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

// 高精度 a + b
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) { // 以较长的为界限
		int temp = a.d[i] + b.d[i] + carry; // 对应为与进位相加
		c.d[c.len++] = temp % 10; // 个位数是该位结果
		carry = temp / 10; // 十位数是进位
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

// 高精度 a - b
bign sub(bign a, bign b) {
	bign c;
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i]) { // 不够减
			a.d[i+1]--; // 向高位借位
			a.d[i] = a.d[i] + 10; // 当前位加10
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--; // 去除最高位，同时至少保留一位小数
	}
	return c;
}

// 高精度与低精度乘法
bign multi(bign a, int b) {
	bign c;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) { // 和加法不一样，乘法的进位可能不止一位，用while
		c.d[c.len++] = carry % 10;
		carry = carry / 10;
	}
	return c;
}

// 高精度与低精度除法




int main(int argc, char *argv[]) {
	
}