#include <cstdio>
#include <iostream>
using namespace std;


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		// 	正方形
		int num1 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				num1++;
				printf("%02d", num1);
			}
			printf("\n");
		}
		printf("\n");
		// 三角形(由于后面空格不做处理默认输出空白)
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n-i; j++) {
				printf(" ");
			}
			while (cnt <= i * (i + 1) / 2) {
				if (cnt < 10) printf("0%d", cnt);
				else printf("%d", cnt);
				cnt++;
			}
			printf("\n");
		}	
	}
	return 0;
}