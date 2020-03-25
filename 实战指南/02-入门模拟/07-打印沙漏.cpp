#include <iostream>
#include <cstdio>
using namespace std;

/*

打印沙漏 P44

* * *
 * * 
  *
 * * 
* * *

*/

int main(int argc, char *argv[]) {
	int n;
	char c;
	while (scanf("%d %c", &n, &c) != EOF) {
		for (int i = 0; i < n; i++) { // 上半部分倒三角形
			for (int j = 0; j < i; j++) {
				printf(" "); // 前面的空格
			}
			for (int k = 0; k < n - i; k++) {
				printf("%c ", c);
			}
			for (int s = 0; s < i; s++) { // 此循环也可以不写 因为默认什么都不输出
				printf(" "); // 后面的空格
			}
			printf("\n");
		}
		for (int i = 1; i < n; i++) { // 下半部分正三角形
			for (int j = 1; j < n - i; j++) { // 前面的空格
				printf(" ");
			}
			for (int k = 0; k < i + 1; k++) {
				printf("%c ", c);
			}
			for (int j = 1; j < n - i; j++) { // 后面的空格 默认可以不写
				printf(" ");
			}
			printf("\n");
		}	
		
	}
}