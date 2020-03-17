#include <iostream>
#include <cstdio>
using namespace std;

/*

输出第k个素数（上海交通大学） P96

*/
const int maxn = 1010;
int prime[maxn], pNum = 0;
bool p[maxn];

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
	int k;
	while (scanf("%d", &k) != EOF) {
		Find_Prime();
		printf("%d\n", prime[k-1]);
	}
}