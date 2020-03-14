#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

字母统计（上海交通大学）P51

备注：
hash思想
字符的充当下标，数组值充当个数

*/

const int maxn = 1010;

char numbers[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int number[26];  // 数组下标存储字母，数组值存储个数

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		memset(number, 0, sizeof(number));
		for (int i = 0; i < len; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				number[str[i] - 'A']++; // 关键步骤
			}
		}
		for (int i = 0; i < 26; i++) {
			printf("%c %d\n", numbers[i], number[i]);
		}
	}
}