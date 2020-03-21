#include <iostream>
#include <cstdio>
using namespace std;

/*

杨辉三角形（西北工业大学）P135

*/
const int maxn = 1010;
int a[maxn][maxn];

int Function(int i, int j) { // 求杨辉三角形i行j列的元素值
	if (j == 1) return 1;
	else if (j == i) return 1;
	else return Function(i-1, j) + Function(i-1, j-1);
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				printf("%d ", Function(i, j));
			}
			printf("\n");
		}
	}
}