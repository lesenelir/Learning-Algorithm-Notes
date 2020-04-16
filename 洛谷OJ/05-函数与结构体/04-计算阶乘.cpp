#include <cstdio>
#include <iostream>
using namespace std;

int functionX(int n) {
	if (n == 1) return 1;
	else return n * functionX(n-1);
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int res = functionX(n);
		printf("%d\n", res);
	}
	return 0;
}