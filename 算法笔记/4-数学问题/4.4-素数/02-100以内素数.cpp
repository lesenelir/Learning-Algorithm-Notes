#include <iostream>
#include <cstdio>
using namespace std;

/*

求解100以内的所有素数

*/

const int maxn = 100;
int prime[maxn], num = 0; // 存储素数数组
bool p[maxn] = {false};

bool isPrime(int n) { // 判断某数是否为素数
	if (n <= 1) return false;
	for (int i = 2; i * i <= n ; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void Find_Prime() { // 打印素数表
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i) == true) {
			prime[num++] = i;
			p[i] = true;
		}
	}
}



int main(int argc, char *argv[]) {
	Find_Prime();
	for (int i = 0; i < num; i++) { // 遍历存储数组元素
		printf("%d ", prime[i]);
	}
}