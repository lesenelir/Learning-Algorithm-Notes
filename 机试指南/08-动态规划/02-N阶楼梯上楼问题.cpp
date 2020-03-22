#include <iostream>
#include <cstdio>
using namespace std;

/*

N阶楼梯上楼问题（华中科技大学）P223

递归版本
类似于FIbonacci数列

*/

int Function(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else return Function(n-1) + Function(n-2);
}


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = Function(n);
		printf("%d\n", res);
	}
}