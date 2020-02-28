#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开。
所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。

多组数据。每组数据输入包括3行，
第1行是包含多个单词的字符串 s，
第2行是待替换的单词a，(长度<=100)
第3行是a将被替换的单词b。(长度<=100)

输入：
I love Tian Qin
I
You
输出：
You love Tian Qin

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char s[maxn];
	while (gets(s) != NULL) {
		char s1[maxn], s2[maxn];
		gets(s1);
		gets(s2);
		
		int len = strlen(s), r = 0, c = 0;
		char ans[maxn][maxn]; // 二维数组存储字符串
		for (int i = 0; i < len; i++) { 
			if (s[i] != ' ') {
				ans[r][c++] = s[i];
			} else {
				ans[r][c] = '\0';
				r++;
				c = 0;
			}
		}
		
		for (int i = 0; i <= r; i++) {
			if (strcmp(ans[i], s1) == 0) { // s1是字符串
				strcpy(ans[i], s2);
			}
			printf("%s", ans[i]);
			if (i < r) printf(" ");
			else printf("\n");
		}
	
	}
	
}