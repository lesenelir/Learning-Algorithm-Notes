#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int maxline = 2 * n + 3;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < maxline - (2*i+3); j++) {
			printf(" ");
		}
		for (int k = maxline - (2*i+3); k < maxline; k++) {
			printf("*");
		}
		printf("\n");
	}
}
