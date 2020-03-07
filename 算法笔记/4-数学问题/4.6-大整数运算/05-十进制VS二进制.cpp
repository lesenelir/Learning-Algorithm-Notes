#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

10进制 VS 2进制
对于一个十进制数A，将A转换为二进制数，然后按位逆序排列，再转换为十进制数B，我们称B为A的二进制逆序数。
例如对于十进制数173，它的二进制形式为10101101，逆序排列得到10110101，其十进制数为181，181即为173的二进制逆序数。

输入：
985
输出：
623

*/


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		
		// 十进制数转换为二进制数
		int a[1000], num = 0;
		do {
			a[num++] = n % 2;
			n = n / 2;
		} while (n != 0);
		reverse(a, a + num);
		
		// 二进制数转换为十进制数
		int y = 0, product = 1;
		for (int i = 0; i < num; i++) { // 区别于二进制存储于int数据内和数组中
			y = y + a[i] * product;
			product = product * 2;
		}
		printf("%d\n", y);
	}
}