#include <iostream>
#include <cstdio>
using namespace std;


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[101][101] = {0};
		int num = 1;
		int x = 1, y = 0;
		while (num <= n * n) {
			while (y < n && !a[x][y+1]) a[x][++y] = num++;
			while (x < n && !a[x+1][y]) a[++x][y] = num++;
			while (y > 1 && !a[x][y-1]) a[x][--y] = num++;
			while (x > 1 && !a[x-1][y]) a[--x][y] = num++;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%3d", a[i][j]);
			}
			printf("\n");
		}		
	}
	return 0;
}