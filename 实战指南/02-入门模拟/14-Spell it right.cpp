#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

A1005 Spell it right P75

*/
const int maxn = 1010;

// 不要忘记0 不要从一开始就是用1来存储
char change[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		int a[maxn], aNum = 0; 
		for (int i = 0; i < len; i++) { // 把字符数组存储在整型数组
			a[aNum++] = str[i] - '0';
		}
		int sum = 0;
		for (int i = 0; i < aNum; i++) {
			sum = sum + a[i];
		}
		int b[maxn], bNum = 0;
		while (sum != 0) { // 把和拆解装入b数组
			b[bNum++] = sum % 10;
			sum = sum / 10;
		}
		for (int i = bNum - 1; i >= 0; i--) { // 从高位输出
			printf("%s ", change[b[i]]);
		}
		printf("\n");
	}
}