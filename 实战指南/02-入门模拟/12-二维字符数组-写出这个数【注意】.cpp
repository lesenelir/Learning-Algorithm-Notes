#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

B1002 写出这个数 P63

备注：
字符数组一维的时候可以代表一个字符串
字符数组二维的时候可以代表一组字符串，即若干个字符串


*/
const int maxn = 1010;

// change[10][5]; 
char change[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		int a[maxn], num = 0; // 存储数字
		for (int i = len - 1; i >= 0; i--) { // 字符数组当中的数字存储到整型数组中
			a[num++] = str[i] - '0';
		}
		int sum = 0;
		for (int i = 0; i < num; i++) {
			sum = sum + a[i];
		}
		int b[maxn], bNum = 0; // b数组存储求和的不同位数的结果
		while (sum != 0) {
			b[bNum++] = sum % 10;
			sum = sum / 10;
		}
		for (int i = bNum - 1; i >= 0; i--) { // 从高位开始输出
			printf("%s ", change[b[i]]);
		}
		printf("\n");
	}	
}