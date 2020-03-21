#include <iostream>
#include <cstdio>
using namespace std;

/*

递归边界（清华大学）P132

*/


int Function(int n) {
	if (n == 0) return 1;
	else return n * Function(n-1);
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = Function(n);
		printf("%d\n", res);
	}
}