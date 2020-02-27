#include <iostream>
#include <cstdio>
using namespace std;


/*

输入一个高度h，输出一个高为h，上底边为h的梯形。
输入：
5
输出：
		*****
	  *******
	*********
  ***********
*************

备注：
图形输出把它当作是一个平面中有一个个的小格子，
找规律分别在这些不同的小格子的点中输出空白和图形
for 循环可以从1开始 而不用0开始，是因为方便计算，存在0是要进行加减操作


n = 2, col = 4
n = 3, col = 7
n = 4, col = 10
n = 5, col = 13
col = 3 * n - 2

找规律输出

*/



int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int col = 3 * n - 2; // 最后一行有多少个，即列数有多少个
		int row = n; // 行
		
		// 第一行开始到row-1行
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < col - (2 * i + n); j++) { // 前半部分输入空格
				printf(" ");
			} 
			for (int k = col - (2 * i + n) + 1; k <= col; k++) { // 后半部分输出*
				printf("*");
			}
			
			printf("\n");
		}
	
		// 最后一行，每列都全部布满*
		for (int i = 1; i <= col; i++) {
			printf("*");
		}
		printf("\n");
	}
}