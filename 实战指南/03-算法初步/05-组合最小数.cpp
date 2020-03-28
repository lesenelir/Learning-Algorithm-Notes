#include <iostream>
#include <cstdio>
using namespace std;

/*

B1023 组个最小数

*/


int main(int argc, char *argv[]) {
	int count[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &count[i]);
	}
	// 找第一个数字
	for (int i = 1; i < 10; i++) {
		if (count[i] > 0) {
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	// 找剩余的数字
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d", i);
		}
	}
}