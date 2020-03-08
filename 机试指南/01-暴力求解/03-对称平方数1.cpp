#include <iostream>
#include <cstdio>
using namespace std;

/*

对称平方数1
打印不超过256的所有对称数 。 对称数：2 11 2*2=4, 11*11=121

思想：
查看该数乘积的反序数是否和该数字的乘积相等

备注：
一定要牢记某一个数字 在不知道位数的情况下去求各个位数，即Reverse函数中的操作

*/

// 求一个数字反序数的模版（不通过数组来完成）
int Reverse(int x) {
	int sum = 0;
	while (x != 0) {
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	for (int i = 1; i <= 256; i++) {
		int num = i * i;
		int reverse_num = Reverse(num);
		if (num == reverse_num) printf("%d ", i);
	}
}