#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

统计字符（浙江大学）P50

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
		int len_s = strlen(s);
		int count;
		for (int i = 0; i < len_s; i++) { // 遍历要搜的数组
			count = 0;
			for (int j = 0; j < len_str; j++) { // 对于某个要搜索的字符中遍历全部的字符串
				if (s[i] == str[j]) count++;
			}
			printf("%c %d\n", s[i], count);
		}
	}
}