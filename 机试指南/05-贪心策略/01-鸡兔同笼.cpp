#include <iostream>
#include <cstdio>
using namespace std;

/*

鸡兔同笼问题（北京大学） P118

以脚有102来算
最少的是102 / 4 = 25， 102 % 4 = 2；

*/


int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n % 2 != 0) {
			printf("0 0\n");
		} else {
			int min_num = 0;
			int max_num = 0;
			min_num = n / 4 + (n % 4) / 2;
			max_num = n / 2; // 最多必定是偶数一定能除尽 此时不涉及到兔子
			printf("%d %d\n", min_num, max_num);
		}
	}
}