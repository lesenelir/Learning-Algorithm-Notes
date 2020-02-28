#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

输入字符串s和字符c，要求去掉s中所有的c字符，并输出结果。
输入：
goaod
a
输出：
good

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char s[maxn];
	while (gets(s) != NULL) {
		char c;
		scanf("%c", &c);
		int len = strlen(s);
		char res[maxn];
		int num = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] != c) {
				res[num++] = s[i];
			}
		}
		for (int i = 0; i < num; i++) {
			printf("%c", res[i]);
		}
		printf("\n");
	}
}