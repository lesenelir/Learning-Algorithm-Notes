#include <iostream>
#include <cstdio>
using namespace std;

/*

汉诺塔问题

*/

void move(int n, char a, char b, char c) {
	if (n == 1) printf("%c -----> %c\n", a, c); // 当只有一块的时候直接由a移动到c
	else {
		move(n-1, a, c, b); // n-1块由a介c移动到中间块b
		printf("%c -----> %c\n", a, c); // 打印 a c 最大的一块
		move(n-1, b, a, c); // 把b上的n-1块盘子由b介a移动到c
	}
}



int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		move(n, 'a', 'b', 'c');
	}
}