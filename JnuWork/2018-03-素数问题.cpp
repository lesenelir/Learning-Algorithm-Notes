#include <iostream>

using namespace std;

const int maxn = 100;
int prime[maxn], cnt = 0;
bool p[maxn];

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

//素数表
void find_prime(int n) { //找到了小于n的所有素数
	for (int i = 1; i < n; i++) {
		if (isPrime(i) == true) {
			prime[cnt++] = i;
			p[i] = true;
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		find_prime(n);//找到小于n的所有素数
		for(int i = 0; i < cnt; i++) {
			for(int j = i; j < cnt; j++) {
				if(prime[i] + prime[j] == n) {
					printf("%d=%d+%d\n", n, prime[i], prime[j]);
				}
			}
		}
	}
}