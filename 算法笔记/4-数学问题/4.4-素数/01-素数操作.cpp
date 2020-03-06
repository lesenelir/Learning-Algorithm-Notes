#include <iostream>
#include <cstdio>
using namespace std;

/*

素数：除了1本身的之外 不能被其他数整除的一类数

*/

bool isPrime(int n) { // 判断是不是素数
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

const int maxn = 101;
int primep[maxn], num = 0; // prime[]用于存放所有素数
bool p[maxn] = {false}; // p[i] == true 代表i是素数
void Find_Prime() {
	for (int i = 1; i < maxn; i++) { // 打印素数表 i 不能取到等号
		if (isPrime(i) == true) {
			prime[num++] = i;
			p[i] = true;
		}
	}
}


int main(int argc, char *argv[]) {
	
}