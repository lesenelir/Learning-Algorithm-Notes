#include <iostream>
#include <cstdio>
using namespace std;

/*

PAT 1013 数素数
输入m,n输出从第M个素数到第n个素数的当中的所有素数
输出每十个素数占一行 行末没有空格

输入：
5 27
输出：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/

const int maxn = 100001;
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
	for (int i = 2; i < maxn; i++) {
		if (isPrime(i) == true) {
			prime[num++] = i;
			p[i] = true;
		}
	}
}


int main(int argc, char *argv[]) {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		Find_Prime();
		int count = 0;
		for (int i = m; i <= n; i++) {
			printf("%d", prime[i-1]); // 第m个 数组下标是m-1
			count++;
			if (count % 10 != 0 && i < n) printf(" ");
			else printf("\n");
		}
	}
}