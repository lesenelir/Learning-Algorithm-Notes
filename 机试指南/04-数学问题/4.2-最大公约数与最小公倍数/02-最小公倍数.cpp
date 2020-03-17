#include <iostream>
#include <cstdio>
using namespace std;

/*

最小公倍数 P91

*/

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main(int argc, char *argv[]) {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		int d = GCD(a, b); // 最大公约数
		int res = a / d * b;
		printf("%d\n", res);
	}
}