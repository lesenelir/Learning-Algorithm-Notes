#include <iostream>
#include <cstdio>
using namespace std;

/*

换个格式输出整数 P59

*/

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a[3], num = 0; // a[0]个位 a[1]十位 a[2]百位
		while (n != 0) {
			a[num++] = n % 10;
			n = n / 10;
		}
		for (int i = num - 1; i >= 0; i--) { // 从高位开始枚举
			if (i == 2) { // 百位
				for (int j = 0; j < a[i]; j++) {
					printf("B");
				}
			} else if (i == 1) { // 十位
				for (int j = 0; j < a[i]; j++) {
					printf("S");
				}
			} else { // 个位
				for (int j = 1; j <= a[i]; j++) {
					printf("%d", j);
				}
			}
		}
		printf("\n");
	}
}