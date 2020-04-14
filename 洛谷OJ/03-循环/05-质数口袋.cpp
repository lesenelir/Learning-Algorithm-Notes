#include <cstdio>
#include <iostream>
using namespace std;


const int maxn = 100000;
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
		if (isPrime(i) == true) {
			prime[pNum++] = i;
			p[i] = true;
		}
	}
}

int main() {
	int L;
	while (scanf("%d", &L) != EOF) {
		Find_Prime();
		int count = 0;
		int sum = 0;
		for (int i = 0; i < pNum; i++) {
			sum = sum + prime[i];
			if (sum > L) break;
			printf("%d\n", prime[i]);
			count++;
		}
		printf("%d\n", count);		
	}
	return 0;
}