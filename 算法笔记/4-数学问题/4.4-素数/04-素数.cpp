#include <iostream>
#include <cstdio>
using namespace std;

/*

输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。
最后一个素数后面没有空格

输入：
70
输出：
11 31 41 61

*/

const int maxn = 100001;
int prime[maxn], num = 0;
bool p[maxn] = {false};

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i<= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void Find_Prime(int n) {
	for (int i = 1; i < n; i++) {
		if (isPrime(i) == true) {
			prime[num++] = i;
			p[i] = true;
		}
	}
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		Find_Prime(n);
		for (int i = 0; i < num; i++) {
			if (prime[i] % 10 == 1) {
				printf("%d ", prime[i]);
			}
		}
		printf("\b"); // 退格标志 使得最后一个空格没有
		printf("\n");
	}
}