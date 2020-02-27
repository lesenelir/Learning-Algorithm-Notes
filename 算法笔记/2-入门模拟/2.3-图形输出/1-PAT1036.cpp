#include <iostream>
#include <cstdio>
using namespace std;


/*

PAT 1036 跟奥巴马一起编程

*/



int main(int argc, char *argv[]) {
	int col; // 列
	char c;
	while (scanf("%d %c", &col, &c) != EOF) {
		int row; // 行
		if (col % 2 == 0) {
			row = col / 2;
		} else {
			row = col / 2 + 1;
		}
		// 第一行
		for (int i = 0; i < col; i++) {
			printf("%c", c);
		}
		printf("\n"); // 此处把空格也当作和第一行连接起来，当作整体看待
		// 第2到row-1行
		for (int i = 2; i < row; i++) { // 2～row总共有row-2个数
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
	}
}