#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

B1009 说反话 P65

*/
const int maxn = 1010;


int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		char ans[maxn][maxn];
		int r = 0, c = 0;
		for (int i = 0; i < len; i++) { // 存储单词
			if (str[i] != ' ') {
				ans[r][c++] = str[i]; // 读入单词
			} else {
				ans[r][c] = '\0';
				r++;
				c = 0;
			}
		}	
		for (int i = r; i >= 0; i--) { // 反向输出
			printf("%s ", ans[i]);
		}
		printf("\n");
		
	}
}