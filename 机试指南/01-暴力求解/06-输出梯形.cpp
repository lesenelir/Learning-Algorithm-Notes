#include <iostream>
#include <cstdio>
using namespace std;

/*

输出一个直角梯形 P10

*/

int main(int argc, char *argv[]) {
	int h;
	while (scanf("%d", &h) != EOF) {
		int row = h;
		int col = 2 * h + 2;
		for (int i = 1; i <= row; i++) { // 对每一行来说
		
			for (int j = 1; j <= col - (2 * i + 2 ); j++) { // 先输出空格
				printf(" ");
			}
			
			for (int j = col - (2 * i + 2)+ 1; j <= col; j++) { // 后输出*
				printf("*");
			}
			printf("\n");
		}
	}
}