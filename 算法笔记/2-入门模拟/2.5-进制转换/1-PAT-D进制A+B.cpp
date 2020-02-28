#include <iostream>
#include <cstdio>
using namespace std;

/*

PAT1022 A+B的D进制数字
输入：
123 456 8
1103


*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	int A, B, D;
	while (scanf("%d %d %d", &A, &B, &D) != EOF) {
		int sum = A + B;
		int a[maxn];
		int num = 0;
		do { // 十进制数转换
			a[num++] = sum % D;
			sum = sum / D;
		}while(sum != 0);
		// 倒叙输出
		for (int i = num - 1; i >= 0; i--) {
			printf("%d",a[i]);
		}
		printf("\n");
	}
}