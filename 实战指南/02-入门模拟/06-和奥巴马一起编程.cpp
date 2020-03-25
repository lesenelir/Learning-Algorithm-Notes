#include <iostream>
#include <cstdio>
using namespace std;

/*

跟奥巴马一起编程 P43

*/

int main(int argc, char *argv[]) {
	int n;
	char c;
	while (scanf("%d %c", &n, &c) != EOF) {
		int col = n;
		int row;
		if (col % 2 == 0) row = col / 2;
		else row = col / 2 + 1;
		// 第一行
		for (int i = 0; i < col; i++) {
			printf("%c", c);
		}
		printf("\n");
		// 第2行到第row - 1 行
		for (int i = 2; i < row; i++) {
			printf("%c", c); // 每行第一个元素是c
			for (int j = 0; j < col - 2; j++) {
				printf(" ");
			}
			printf("%c\n", c);
		}	
		// 最后一行
		for (int i = 0; i < col; i++) {
			printf("%c", c);
		}
		printf("\n");
	}
}