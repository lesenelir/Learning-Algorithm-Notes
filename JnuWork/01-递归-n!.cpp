#include <iostream>
#include <cstdio>
using namespace std;

int Function(int n) {
	if (n == 1) return 1;
	else return n * Function(n-1);
}

int main(int argc, char *argv[]) {
	int n;
	printf("请输入要输入的数据:\n");
	scanf("%d", &n);
	int result;
	result = Function(n);
	printf("%d的阶乘是:\n%d", n, result);
}