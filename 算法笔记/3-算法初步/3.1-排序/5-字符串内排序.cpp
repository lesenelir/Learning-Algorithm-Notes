#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*

字符串内排序：
输入一个字符串，长度小于等于200，然后将输出按字符顺序升序排序后的字符串。

输入：
tianqin
输出：
aiinnqt

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char str[maxn];
	while (gets(str) != NULL) {
		int len = strlen(str);
		sort(str, str+len);
		puts(str);
	}
}