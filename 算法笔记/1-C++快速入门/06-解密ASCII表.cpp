#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

A-->Z        a-->z

B-->Y        b-->y

C-->X        c-->x
第一个字母变成第26个字母，第i个字母变成第（26-i+1)个字母，非字母字符不变
输入：
ZYX123zyx
输出：
ABC123abc

备注：

ASCII码表：
A:65 Z:90
a:97 z:122
空格:32

字符数组最后一格是\0，即字符数组的长度应该要比实际字符串长度+1
当用字符数组的时候，应该尽量使用gets()和puts()
因为用scanf时候，%s不能读入空格，遇到空格就结束


*/



int main(int argc, char *argv[]) {
	char str[25];
	gets(str);
	for (int i = 0; i < 25; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] = 'A' + 'Z' - str[i];
		}
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = 'a' + 'z' - str[i];
		}
		if('0' < str[i] < '9') {
			str[i] = str[i];
		}
	}
	puts(str);	
	
}