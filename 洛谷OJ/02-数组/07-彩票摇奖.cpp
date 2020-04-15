#include <cstdio>
#include <iostream>
using namespace std;

const int num = 7;
int a[num]; // 中奖号码
int c[num] = {0}; // 输出结果数组

struct tickets{
	int z[num]; // 摇号号码
}ticket[1001];


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < num; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < num; j++) {
				scanf("%d", &ticket[i].z[j]);
			}
		}
		for (int i = 0; i < n; i++) { // 对于每一张彩票的输入来说
			int count = 0;
			for (int j = 0; j < num; j++) { // 比较某一张彩票的所有位数
				for (int k = 0; k < num; k++) { // 某一张彩票的某一位去a中奖数组找值
					if (ticket[i].z[j] == a[k]) {
						count++;
					}
				}
			}
			switch (count) {
				case 7:
					c[0]++;
					break;
				case 6:
					c[1]++;
					break;
				case 5:
					c[2]++;
					break;
				case 4:
					c[3]++;
					break;
				case 3:
					c[4]++;
					break;
				case 2:
					c[5]++;
					break;
				case 1:
					c[6]++;
					break;
			}
		}
		for (int i = 0; i < num; i++) {
			printf("%d ", c[i]);
		}
		printf("\n");
	}
	
	return 0;
}