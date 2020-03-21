#include <iostream>
#include <cstdio>
using namespace std;

/*

N的阶乘 非递归

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = 1;
		for (int i = 1; i <= n; i++) {
			res = res * i;
		}
		printf("%d\n", res);
	}
}