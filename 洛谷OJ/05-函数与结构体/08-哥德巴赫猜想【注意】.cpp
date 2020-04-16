#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void print_function(int n) {
	printf("%d=", n);
	for (int i = 2; i < n; i++) {
		if (isPrime(i) == true && isPrime(n-i)) { // 这两个数字都是素数
			printf("%d+%d\n", i, n-i);
			break; // 找到一个第一个数字最小的数字就退出
		}
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 4; i <= n; i = i + 2) {
			print_function(i);
		}
	}
	return 0;
}