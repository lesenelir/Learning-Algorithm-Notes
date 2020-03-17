#include <iostream>
#include <cstdio>
using namespace std;

/*

质因数的个数（清华大学）P96

*/
const int maxn = 1010;
int prime[maxn], pNum = 0;
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
		if (isPrime(i)) {
			prime[pNum++] = i;
			p[i] = true;
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		Find_Prime();
		int res = 0;
		for (int i = 0; i < pNum; i++) {
			while (n % prime[i] == 0) {
				n = n / prime[i];
				res++; // 幂指数
			}
		}
		if (n != 1) res++; // 预遍历完n为1则素因数全部分解完，若n > 1 则还有一个素因子，个数必为1  
		printf("%d\n", res);
	}
}