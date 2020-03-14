#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

密码翻译（北京大学） P47

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y')) {
				str[i] = str[i] + 1;
			} else if (str[i] == 'z' || str[i] == 'Z') {
				str[i] = str[i] - 25;
			}
		}
		for (int i = 0; i < len; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
}