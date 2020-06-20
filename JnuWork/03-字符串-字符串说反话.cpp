#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char str[90];
	gets(str);
	int len = strlen(str);
	int r = 0, h = 0; //r是行，h是列
	char ans[100][100]; //每一行存放一个单词
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ') {
			ans[r][h++] = str[i];
		} else {
			ans[r][h] = '\0'; //此时是空格，则一行的末尾为结束符号
			r++;
			h = 0;
		}
	}
	//以上是用二维数组存储一行字符固定格式，其中有空格，并且存储了一行字符的所有单词，不仅仅是字符
	for (int i = r; i >= 0; i--) {
		printf("%s", ans[i]);
		if (i > 0) printf(" ");
	}
}