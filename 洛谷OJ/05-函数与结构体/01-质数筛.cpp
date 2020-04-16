#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100001;
int a[maxn];

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (isPrime(a[i]) == true) {
				printf("%d ", a[i]);
			}
		}
		printf("\n");
		
	}	
	
	return 0;
}