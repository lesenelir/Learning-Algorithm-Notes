#include <iostream>
#include <cstdio>
using namespace std;

/*

B1022 D进制的A + B P51

*/
const int maxn = 1010;
int A[maxn], num = 0;

int main(int argc, char *argv[]) {
	int a, b, d;
	while (scanf("%d %d %d", &a, &b, &d) != EOF) {
		int sum = a + b;
		do {
			A[num++] = sum % d;
			sum = sum / d;
		} while (sum != 0);
		for (int i = num - 1; i >= 0; i--) {
			printf("%d", A[i]);
		}
		printf("\n");
	}
}