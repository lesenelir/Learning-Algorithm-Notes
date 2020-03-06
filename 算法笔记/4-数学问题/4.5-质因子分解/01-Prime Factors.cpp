#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*

质因子

*/

const int maxn = 100010;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int prime[maxn], PNum = 0;
void Find_Prime() {
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i) == true) {
			prime[PNum++] = i;
		}
	}
}

struct factor {
	int x, cnt;	
}fac[10];


int main(int argc, char *argv[]) {
	Find_Prime();
	int n, num = 0; // num为n的不同质因子的个数
	scanf("%d", &n);
	if (n == 1) printf("1=1");
	else {
		printf("%d=", n);
		int sqr = (int)sqrt(1.0 * n);
		for (int i = 0; i < PNum && prime[i] <= sqr; i++) {
			if (n % prime[i] == 0) { // 质因子分解
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n % prime[i] == 0) {
					fac[num].cnt++;
					n = n / prime[i];
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1) { // 1做特殊处理
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for (int i = 0; i < num; i++) {
			if (i > 0) printf("*");
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1) {
				printf("^%d", fac[i].cnt);
			}
		}
	}
}