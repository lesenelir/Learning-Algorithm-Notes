#include <iostream>
#include <cstdio>
using namespace std;

/*

Output the k-th prime number.

输入：
10
50
输出：
29 
229

*/

const int maxn = 10001;
int prime[maxn], num = 0;
bool p[maxn] = {false};

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void Find_Prime() {
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i) == true) {
			prime[num++] = i;
			p[i] = true;
		}
	}
} 


int main(int argc, char *argv[]) {
	int k;
	while (scanf("%d", &k) != EOF) {
		Find_Prime(); // 提前打印好素数表
		printf("%d\n", prime[k-1]);
	}
}