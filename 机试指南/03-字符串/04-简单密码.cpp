#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


/*

简单密码（北京大学）P48

备注：
字符数组比较字符串是否相等用strcmp函数来比较

*/

const int maxn = 1010;

char start[] = "START";
char final[] = "ENDOFINPUT";

int main(int argc, char *argv[]) {
	char str1[maxn]; // 起始行
	char str2[maxn]; // 密码行
	char str3[maxn]; // 结束行
	while (gets(str1) != NULL) { // 起始行
		if (strcmp(str1, final) == 0) break;
		if (strcmp(str1, start) == 0) {
			gets(str2);
			int len = strlen(str2);
			for (int i = 0; i < len; i++) {
				if (str2[i] >= 'F' && str2[i] <= 'Z') {
					str2[i] = str2[i] - 'F' + 'A';
				} else if (str2[i] >= 'A' && str2[i] <= 'E') {
					str2[i] = str2[i] + 26 - 5;
				}
			}
			gets(str3);
			puts(str2);
		}
	}
}