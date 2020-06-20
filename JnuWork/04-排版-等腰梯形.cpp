#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int maxline = 2*n + 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < maxline/2-(i+1); j++) {
			printf(" ");
		}
		for (int j = maxline/2-(i+1); j < maxline/2+(i+1); j++) {
			printf("*");
		}
		for (int j = maxline/2+(i-1); j < maxline; j++) {
			printf(" ");
		}
		printf("\n");		
	}
}




