#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

首字母大写（北京大学）

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		char ans[maxn][maxn];
		int r = 0, c = 0;
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
			if (ans[i][0] >= 'a' && ans[i][0] <= 'z') { // ans[i][0]表示第i个单词的第一个字母
				ans[i][0] = ans[i][0] - 'a' + 'A';
			}
		}
		
		for (int i = 0; i <= r; i++) {
			printf("%s ", ans[i]);
		}
		
	}
}