#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

编写函数将字符串按反序存放。在主函数中输入一个字符串，通过调用该函数，得到该字符串按反序存放后的字符串，并输出。
输入：
abcd
输出：
dcba

思路：
函数编写直接按照字符数组的逆序依次打印字符

*/



void Reverse_String(char str[]) {
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}



int main(int argc, char *argv[]) {
	char str[255];
	//scanf("%s", str); // %s不能出现空格若要用空格用gets()
	gets(str);
	Reverse_String(str);
}