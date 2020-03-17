#include <iostream>
#include <cstdio>
using namespace std;

/*

递推数列（清华大学）P106

类似于Fibonacci数列

备注：
凡是涉及到数学表达式的递归都可以考虑Fibonacci数列的求解方式 递归来求解

*/

int a0, a1, p, q, k;

int Function(int n) {
	if (n == 0) return a0;
	else if (n == 1) return a1;
	else return (p * Function(n-1) + q * Function(n-2));
}

int main(int argc, char *argv[]) {
	while (scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k) != EOF) {
		int res = Function(k);
		printf("%d\n", res);
	}
}