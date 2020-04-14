#include <cstdio>
#include <iostream>
using namespace std;

/*

输入：
5
输出：
0102030405      
06070809       
101112        
1314         
15

*/

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int num = 1;
		int row = n, col = n;
		// 一行一行来进行赋值
		for (int i = 1; i <= row; i++) {
			// 填数字
			for (int j = 1; j <= n-i+1; j++) {
				printf("%02d", num);
				num++;
			}
			// 填空格
			for (int j = n-i+1; j <= col; j++) {
				printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}