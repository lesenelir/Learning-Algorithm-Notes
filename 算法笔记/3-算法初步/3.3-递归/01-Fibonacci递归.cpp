#include <iostream>
#include <cstdio>
using namespace std;

/*

Fibonacci递归求解

备注：
递归讲究的是 递归式+递归边界

*/

int Fibonacci(int n) {
	if (n == 1 || n == 0) return 1;
	else return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", Fibonacci(n));
	}
}