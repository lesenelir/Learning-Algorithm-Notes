#include <iostream>
#include <cstdio>
using namespace std;

/*

最大公约数（哈尔滨工业大学）P90

*/

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main(int argc, char *argv[]) {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		int res = GCD(a, b);
		printf("%d\n", res);
	}
}