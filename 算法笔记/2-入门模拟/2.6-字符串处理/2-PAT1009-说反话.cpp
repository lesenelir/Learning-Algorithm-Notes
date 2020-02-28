#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

PAT 1009 说反话
编写程序要求：将所有单词按照颠倒顺序的方式输出。（此处是单词倒叙而不是字母倒叙）

输入：
Hello World Here I Come
Come I Here World Hello

备注：
此处有空格的输入，所以不能用%s，而需要使用gets
涉及字符数组的问题都要考虑最后一个格子存储'\0'
*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str), r = 0, c = 0; // r为行，c为列，一行存放一个单词
		char ans[maxn][maxn]; // ans[0] ~ ans[r]存放单词
		// 读入单词
		for (int i = 0; i < len; i++) {
			if (str[i] != ' ') {
				ans[r][c++] = str[i]; // 不是空格就是单词
			} else { // 如果是空格说明一个单词输入结束，r加1代表另一个单词，列c恢复为0
				ans[r][c] = '\0';
				r++;
				c = 0;
			}
		}
		// 倒叙输出单词，按照行数来遍历
		for (int i = r; i >= 0; i--) {
			printf("%s", ans[i]);
			if (i > 0) printf(" ");
		}
		printf("\n");
	}
}