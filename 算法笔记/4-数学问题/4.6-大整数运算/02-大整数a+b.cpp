#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

大整数a+b
输入：
2000000000 30000000000000000000
输出：
30000000002000000000

*/

struct bign {
	int d[1000];
	int len;
	bign () {
		memset(d, 0, sizeof(d));
		len = 0;
	}	
};

// 把字符串类型转换成bign
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
		c.d[c.len++] = temp % 10; // 个位
		carry = temp / 10; // 十位
	}
	if (carry != 0) { // 进位不为0向前进
		c.d[c.len++] = carry;
	}
	return c;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
}



int main(int argc, char *argv[]) {
	char str1[1000], str2[1000];
	while (scanf("%s %s", str1, str2) != EOF) {
		bign a = change(str1);
		bign b = change(str2);
		bign c = add(a, b);
		print(c);
		printf("\n");
	}
}