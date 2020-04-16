#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/*

字符串循环右移

*/


const int maxn = 51;
char str[maxn];
char str_new[maxn];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		scanf("%s", str);
		int len = strlen(str);
//		n = n % 26; // 如果n > 26就是移动他的余数
		for (int i = 0; i < len ; i++) {
			str[i] = (str[i] - 'a' + n) % 26 + 'a';  // +a代表是数字
		}
		puts(str);
	}
	
	return 0;
}