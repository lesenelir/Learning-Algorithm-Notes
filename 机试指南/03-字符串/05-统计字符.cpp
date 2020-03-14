#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

统计字符（浙江大学）P50

备注：
HASH打表方法

*/

const int maxn = 1010;

char final[] = "#";

int main(int argc, char *argv[]) {
	char s[maxn];
	char str[maxn];
	while (gets(s) != NULL) {
		if (strcmp(s, final) == 0) break;
		gets(str);
		int len_str = strlen(str);
		int number[maxn] = {0};
		for (int i = 0; i < len_str; i++) {
			number[str[i]]++; // 每一个字符都有特定的ASCII码
		}
		int len_s = strlen(s);
		for (int i = 0; i < len_s; i++) {
			printf("%c %d\n", s[i], number[s[i]]);
		}
	}
}