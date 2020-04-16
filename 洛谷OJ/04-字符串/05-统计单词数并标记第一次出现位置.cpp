#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/*

大写变成小写、存储单词、字符串匹配、标记字符串位置

*/
const int maxn = 1000001;
char str[maxn];
char str_word[10];
char ans[maxn][maxn]; // 存储文章的单词
int r = 0, c = 0;


int main() {
	gets(str_word);
	gets(str);
	int len_word = strlen(str_word);
	int len = strlen(str);
	for (int i = 0; i < len_word; i++) { // 单词大写变小写
		if (str_word[i] >= 'A' && str_word[i] <= 'Z') {
			str_word[i] = str_word[i] - 'A' + 'a';
		}
	}
	for (int i = 0; i < len; i++) { // 文章大写变小写
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
	// 存储单词
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ') {
			ans[r][c++] = str[i];
		} else {
			ans[r][c] = '\0';
			r++;
			c = 0;
		}
	}
	int count = 0;
	bool flag = false; // 标记是否出现过，第一次找到设置为true
	int temp = 0; // 标记第一次出现的位置
	for (int i = 0; i <= r; i++) {
		if (strcmp(ans[i], str_word) == 0) {
			count++;
			if (flag == false) { // 第一次匹配的时候标记还是位false
				flag = true;
				temp = i;
			}
		}
	}
	if (count != 0) {
		printf("%d %d\n", count, temp);
	} else {
		printf("-1\n");
	}
	return 0;
}