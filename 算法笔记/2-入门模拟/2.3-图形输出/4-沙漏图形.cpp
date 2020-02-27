#include <iostream>
#include <cstdio>
using namespace std;


/*

输入n，输出正倒n层星号三角形。首行顶格，星号间有一空格
输入：
3
输出：
* * *
 * * 
  *
 * * 
* * *

*/


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) { // 上半部分倒三角形
			for (int j = 0; j < i; j++) {
				printf(" "); // 前面的空格
			}
			for (int k = 0; k < n - i; k++) {
				printf("* ");
			}
			printf("\n");
		}
		for (int i = 1; i < n; i++) { // 下半部分正三角形
			for (int j = 0; j < n - 1 - i; j++) {
				printf(" ");
			}
			for (int k = 0; k < i + 1; k++) {
				printf("* ");
			}
			printf("\n");
		}
	}
}