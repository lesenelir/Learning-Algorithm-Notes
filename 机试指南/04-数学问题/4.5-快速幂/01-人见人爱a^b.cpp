#include <iostream>
#include <cstdio>
using namespace std;

/*

人见人爱的a^b P100

备注：
没有使用快速幂

*/

int main(int argc, char *argv[]) {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		if (a == 0 && b == 0) break;
		int sum = 1;
		for (int i = 1; i <= b; i++) {
			sum = (sum * a);
			sum = sum % 1000;
		}
		printf("%d\n", sum);
	}
}