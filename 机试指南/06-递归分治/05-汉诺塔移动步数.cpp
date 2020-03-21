#include <iostream>
#include <cstdio>
using namespace std;

/*

汉诺塔问题 至少移动多少次

此时可以不一定经过b杆子，可以直接由a移动到c，或者由c直接移动到b

*/
int move(int n) {
	if (n == 1) return 1;
	// 首先将n-1由a经过c移动到b，再把a的最大盘移动到c + 1，最后把n-1个盘子由b经过a移动到c，n-1移动了两次
	else return 2 * move(n-1) + 1;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = move(n);
		printf("%d\n", res);
	}
}