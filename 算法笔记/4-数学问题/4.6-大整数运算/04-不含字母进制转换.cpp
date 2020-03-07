#include <iostream>
#include <cstdio>
using namespace std;

/*

普通进制转换 不包含字母
输入的第一行包括两个整数：M和N(2<=M,N<=36)。
下面的一行输入一个数X，X是M进制的数，现在要求你将M进制的数X转换成N进制的数输出。

输入：
10 2
11
输出
1011

备注：
十进制数是中介媒介

*/


int main(int argc, char *argv[]) {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		int x;
		scanf("%d", &x);
		// m进制数转换成十进制数字
		int y = 0, product = 1;
		while (x != 0) {
			y = y + (x % 10) * product;
			x = x / 10;
			product = product * m;
		}
		// 将十进制数y转换成n进制数
		int a[100], num = 0;
		do {
			a[num++] = y % n;
			y = y / n;			
		} while (y != 0);
		// 遍历输出
		for (int i = num - 1; i >= 0; i--) {
			printf("%d", a[i]);
		}
		printf("\n");
	}
}