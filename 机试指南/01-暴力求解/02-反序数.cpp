#include <iostream>
#include <cstdio>
using namespace std;

/*

反序数：它的9倍恰好是他的反序数 1234的反序数是4321

备注：
对于一个数字拆解（可能数组已经拆解好了）
sum = sum * 10 + a[i];
若不是数组则 用% / 进行拆解累加
sum = sum * 10 + x % 10;
x = x / 10;


*/


//编写函数的好处是 可以不用知道x是几位也可以进行拆解
int Reverse(int x) {
	int sum = 0;
	while (x != 0) {
		sum = sum * 10 + (x % 10); 
		x = x / 10;
	}
	return sum;
}

int main(int argc, char *argv[]) {
	for (int i = 1000; i < 10000; i++) {
		int sum = 0;
//		sum = (i % 10 * 1000) + (i % 100 / 10 * 100) + (i / 100 % 10 * 10) + (i / 1000);
//		if (sum == i * 9) printf("%d ", i);
		sum = Reverse(i);
		if (sum == i * 9) printf("%d ", i);
	}
}