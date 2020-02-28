#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输入：
abc def
输出：
abcdef

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str1[maxn], str2[maxn];
	while (scanf("%s %s", str1, str2) != EOF) {
		char str3[maxn];
		int len1 = strlen(str1), len2 = strlen(str2);
		for (int i = 0; i < len1 + len2; i++) {
			if(i < len1) str3[i] = str1[i];
			else str3[i] = str2[i - len1];
		}
		str3[len1 + len2] = '\0'; // 字符数组结束标志
		puts(str3);
	}
}