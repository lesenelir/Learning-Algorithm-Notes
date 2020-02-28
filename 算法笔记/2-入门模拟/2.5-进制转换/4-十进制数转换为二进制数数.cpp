#include <iostream>
#include <cstdio>
using namespace std;

/*

十进制非负整数转换为二进制数输出。

输入：
985
211
1126
输出：
1111011001
11010011
10001100110

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[maxn];
		int num = 0;
		do {
			a[num++] = n % 2;
			n = n / 2;
		}while (n != 0);
		for (int i = num - 1; i >= 0; i--) {
			printf("%d", a[i]);
		}
		printf("\n");
	}
}