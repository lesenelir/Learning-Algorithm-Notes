#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[100][100], num = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = num++;
			}
		}	
		int b[100][100];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 2 != 0) {
					b[i][j] = a[i][j];
				} else {
					b[i][j] = a[i][n-j-1];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}	
	}
}