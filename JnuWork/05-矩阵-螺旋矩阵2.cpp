#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int a[1001][1001];
	memset(a, 0, sizeof(a));
	int x = 0, y = 0;
	a[x][y] = 1;
	int count = 1;
	while (count < n * n) {
		while (y+1<n && !a[x][y+1])		a[x][++y] = ++count;
		while (x+1<n && !a[x+1][y])		a[++x][y] = ++count;
		while (y-1>=0 && !a[x][y-1])	a[x][--y] = ++count;
		while (x-1>=0 && !a[x-1][y])	a[--x][y] = ++count;
	}
	
	for (int i= 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
}