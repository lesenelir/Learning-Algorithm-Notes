#include <iostream>
#include <cstdio>
using namespace std;

/*

P进制数字x转换为十进制数y

备注：
十进制转换某一进制 用除法 再倒叙输出
某一进制转换十进制 用乘法 从最后一位开始累乘叠加


*/

int main(int argc, char *argv[]) {
	int P, x;
	while (scanf("%d %d", &P, &x) != EOF) {
		int y = 0;
		int product = 1; // 
		while (x != 0) {
			y = y + (x % 10) * product;
			x = x / 10; // 舍去最后一位
			product = product * P;
		}
		printf("%d\n", y);
	}
}