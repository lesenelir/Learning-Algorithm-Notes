#include <iostream>
#include <cstdio>
using namespace std;


/*

输入第一行表示样例数m，接下来m行每行一个整数h，h不超过10
对应于m个case输出要求的等腰梯形。
输入：
1
4
输出：
   ****
  ******
 ********
**********




*/


int main(int argc, char *argv[]) {
	int m;
	while (scanf("%d", &m) != EOF) {
		while (m--) {
			int n;
			scanf("%d", &n);
			int col = 3 * n - 2; // 总列数
			int row = n; // 总行数
			// 一行一行来进行赋值操作
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < (col - n - 2 * i) / 2; j++) { // 前半部分空格
					printf(" ");
				}
				for (int k = 0; k < n + 2 * i; k++) { // 中间部分含有元素
					printf("*");
				}
				for (int m = 0; m < (col - n - 2 * i) / 2; m++) { // 后半部分空格，与前半部分空格对称
					printf(" ");
				}
				printf("\n"); // 每行结束就换行进入下一行
			}
		}
	}
}