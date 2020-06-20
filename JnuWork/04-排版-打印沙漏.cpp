#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i-1; j++) {
			printf(" ");
		}
		for (int j = 0; j < n-i+1; j++) {
			if (j == n-i+1) {
				printf("*");
			} else {
				printf("* ");
			}
		}
		for (int j = 0; j < i-1; j++) {
			printf(" ");
		}
		printf("\n");
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n-i; j++) {
			printf(" ");
		}
		
		for (int j = 0; j < i; j++) {
			if (j == i-1) {
				printf("*");
			} else {
				printf("* ");
			}
		}
		
		for (int j = 0; j < n-i; j++) {
			printf(" ");
		}
		printf("\n");
	}
}