#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

输入一个字符串，长度小于等于200，然后将数组逆置输出。
输入：
tianqin
输出：
niqnait

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		
		for (int i = len - 1; i >= 0; i--) {
			printf("%c", str[i]);
		}
		
	}
}