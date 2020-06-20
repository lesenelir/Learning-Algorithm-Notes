#include <iostream>

using namespace std;

int Function(int n) {
	if (n == 1) return 1;
	else return n * Function(n-1);
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int result = Function(n);
		printf("%d\n", result);
	}
}