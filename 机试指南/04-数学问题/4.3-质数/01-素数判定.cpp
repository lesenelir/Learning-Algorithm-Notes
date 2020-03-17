#include <iostream>
#include <cstdio>
using namespace std;

/*

素数判定（哈尔滨工业大学）P92

*/


bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		bool flag = isPrime(n);
		if (flag == true) printf("YES\n");
		else printf("NO\n");
	}
}