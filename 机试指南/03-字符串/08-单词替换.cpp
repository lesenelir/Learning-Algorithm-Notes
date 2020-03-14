#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

单词替换（北京大学）

备注：
涉及到要存储单词的要用一个二维数组来存储ans[][] 每一行代表一个单词

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		int r = 0, c = 0;
		char ans[maxn][maxn]; // 存放单词
		char s1[maxn]; 
		char s2[maxn];
		gets(s1);
		gets(s2);
		// 遍历存放单词
		for (int i = 0; i < len; i++) {
			if (str[i] != ' ') {
				ans[r][c++] = str[i];
			} else {
				ans[r][c] = '\0';
				r++;
				c = 0;
			}
		}
		for (int i = 0; i <= r; i++) {
			if (strcmp(ans[i], s1) == 0) {
				strcpy(ans[i], s2);
			}
			printf("%s ", ans[i]);
		}
		printf("\n");
	}
}