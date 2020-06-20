#include <iostream>
#include <cstdio>
using namespace std;

int Fibonacci(int n) {
	if (n == 1 || n == 2) return 1;
	else return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(int argc, char *argv[]) {
	int n;
	printf("请输入要输入的数据:\n");
	scanf("%d", &n);
	int result = Fibonacci(n);
	printf("%d的斐波那契数列是:\n%d", n, result);	
}