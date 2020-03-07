#include <iostream>
#include <cstdio>
using namespace std;

/*

将一个2行3列的矩阵（二维数组）行列互换，存储到另一个3行2列的矩阵中。
输入：
1 2 3
4 5 6
输出：
1 4
2 5
3 6

*/



int main(int argc, char *argv[]) {
	int a[5][5];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[j][i]);
		}
		printf("\n");	
	}
}