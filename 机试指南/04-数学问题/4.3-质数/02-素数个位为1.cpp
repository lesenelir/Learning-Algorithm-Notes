#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

素数（北京航天航空大学） P94

*/
const int maxn = 1010;
int prime[maxn], PNum = 0;
bool P[maxn] = {false};

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void Find_Prime(int n) {
	for (int i = 2; i < n; i++) {
		if (isPrime(i)) {
			prime[PNum++] = i;
			P[i] = true;
		}
	}
}



int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(prime, 0, sizeof(prime)); // 初始化数组，防止每次输入会受到上次输入的影响
		Find_Prime(n);
		bool flag = false;
		for (int i = 0; i < PNum; i++) {
			if (prime[i] % 10 == 1) {
				printf("%d ", prime[i]);
				flag = true;
			}	
		}
		if (flag == false) {
			printf("-1\n");
		} else {
			printf("\n");	
		}
	}
}