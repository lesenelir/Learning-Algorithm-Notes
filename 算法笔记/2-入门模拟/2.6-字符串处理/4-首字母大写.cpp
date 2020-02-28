#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。
输入：
if so, you already have a google account. you can sign in on the right.
输出：
If So, You Already Have A Google Account. You Can Sign In On The Right.

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str), r = 0, c = 0; // r 行 c 列
		char ans[maxn][maxn]; // ans存放单词
		
		for (int i = 0; i < len; i++) {
			if (str[i] != ' ' ) { //&& str[i] != ',' && str[i] != '.'
				ans[r][c++] = str[i];
			} else {
				ans[r][c] = '\0';
				r++;
				c = 0;
			}
		}
		
		for (int i = 0; i <= r; i++) {
			if (ans[i][0] >= 'a' && ans[i][0] <= 'z') {
				ans[i][0] = ans[i][0] - 'a' + 'A'; // 转换为大写
			}
		}
		
		for (int i = 0; i <= r; i++) {
			printf("%s", ans[i]);
			printf(" ");
		}
		
	}
}