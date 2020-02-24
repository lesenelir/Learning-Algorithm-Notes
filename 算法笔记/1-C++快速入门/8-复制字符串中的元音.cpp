#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

写一个函数，将一个字符串中的元音字母复制到另一个字符串中。通过调用该函数，得到一个有该字符串中的元音字母组成的一个字符串。
输入：
CLanguage
输出：
auae

*/

void vowels(char s1[]) {
	char s2[255];
	int len1 = strlen(s1);
	int index = 0;
	// 逐个判断s1数组中的元素是否为元音，若是则放入s2数组
	for (int i = 0; i < len1; i++) {
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' ||
			s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U') {
			s2[index] = s1[i];
			index++;
		}
	}
	// 遍历输出s2数组
	for (int i = 0; i < index; i++) {
		printf("%c", s2[i]);
	}
	
}


int main(int argc, char *argv[]) {
	char str[255];
	gets(str);
	vowels(str);
}