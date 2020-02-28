#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

判断字符串是否为回文串，如果是回文串输出YES，不是回文串输出NO
输入：
12321
输出：
YES

备注：
数组位置的对称位置：
a[i] <======> a[n-i-1]


*/

const int maxn = 1010;

bool judge(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) { // 此处只需要遍历一半即可
		if (str[i] != str[len - i - 1]) { // 对称位置不相等
			return false;
		}
	}
	return true;
}


int main(int argc, char *argv[]) {
	char str[maxn];
	while (scanf("%s", str) != EOF) {
		bool flag = judge(str);
		if (flag) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}
	}
}