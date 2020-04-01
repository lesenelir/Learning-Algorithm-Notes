#include <cstdio>
#include <iostream>
using namespace std;

/*

由滑雪问题 联想到一种蛇形矩阵，也称为螺旋矩阵，数字依次由外而内的递增的矩阵
N=3时： 
1 2 3 
8 9 4 
7 6 5 
N=6时： 
1 2 3 4 5 6 
20 21 22 23 24 7 
19 32 33 34 25 8 
18 31 36 35 26 9 
17 30 29 28 27 10 
16 15 14 13 12 11 

*/
const int maxn = 1010;
int a[maxn][maxn];


int main(){
	int n;
	while (scanf("%d", &n) != EOF) {
		int num = 1;
		for (int i = 0; i < n / 2 + 1; i++) { // 矩阵的层数
			for (int j = i; j < n - i; j++) { // 上
				a[i][j] = num++; 
			}
			for (int j = i + 1; j < n - i; j++) { // 右
				a[j][n-i-1] = num++;
			}
			for (int j = n - i - 2; j > i; j--) { // 下
				a[n-i-1][j] = num++;
			}
			for (int j = n - i - 1; j > i; j--) { // 左
				a[j][i] = num++;
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}