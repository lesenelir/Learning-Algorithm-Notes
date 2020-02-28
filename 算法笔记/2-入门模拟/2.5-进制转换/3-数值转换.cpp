#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

求任意两个不同进制非负整数的转换（2进制～16进制）
不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。

输入只有一行，包含三个整数a，n，b。a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。
a，b是十进制整数，2 =< a，b <= 16

输出时字母符号全部用大写表示，即（0，1，...，9，A，B，...，F）。

输入：
4 123 10
输出：
27

备注：
ASCII码表：
0 48
A 65
a 97

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int A, B;
	char n[maxn], res[maxn];
	while (scanf("%d %s %d", &A, n, &B) != EOF) {
		int len = strlen(n);
		int temp;
		int sum = 0;
		for (int i = 0; i < len; i++) {
			if (n[i] >= 'a') {
				n[i] = n[i] + 'A' - 'a'; // 小写变成大写
			} else if (n[i] >= 'A') {
				temp = n[i] - 'A' + 10;
			} else {
				temp = n[i] - '0';
			}
			sum = sum * A + temp;
		}
		int num = 0;
		do {
			if (sum % B <= 9) res[num++] = sum % B + '0';
			else res[num++] = sum % B + 'A' - 10;
			sum = sum / B;
		}while (sum != 0);
		for (int i = num - 1; i >= 0; i--) {
			printf("%c", res[i]);
			if (i == 0) printf("\n");
		}
	}
}