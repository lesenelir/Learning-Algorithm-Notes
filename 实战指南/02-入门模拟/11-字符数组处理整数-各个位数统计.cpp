#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

B1021 各个位数统计

备注：
统计数组count 记录数字0~9出现的次数

字符转数字 str[i] - '0'
大写字母R转小写字母r 'R' - 'A' + 'a'
小写字母r转大写字母R 'r' - 'a' + 'A'

*/
const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		int count[10] = {0};// 记录0 ~ 9出现的次数
		for (int i = 0; i < len; i++) {
			count[str[i] - '0']++;
		}
		for (int i = 0; i < 10; i++) { // 枚举 0 ~ 9
			if (count[i] != 0) {
				printf("%d:%d\n", i, count[i]);
			}
		}
		
	}
}