#include <iostream>
#include <cstdio>
using namespace std;

/*

数组循环右移 P12

*/
const int maxn = 1010;
int A[maxn];

int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
		m = m % n;
		for (int i = n - m; i < n; i++) {
			printf("%d", A[i]);
			count++;
			if (count < n) printf(" ");
		}
		for (int i = 0; i < n - m; i++) {
			printf("%d", A[i]);
			count++;
			if (count < n) printf(" ");
		}
	}
}