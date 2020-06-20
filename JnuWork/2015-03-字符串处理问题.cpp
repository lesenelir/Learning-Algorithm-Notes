#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	char str[1000];
	char ch;
	//scanf()会在读取输入时在缓冲区留下一个'\n'
	while ((ch = getchar()) != '#') {
		if (ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U') {
			continue; //跳过本次循环，不输出任何printf()
		}
		if (ch >= 'a' && ch <= 'z') {
//			ch = ch - 32;
			printf(".%c", ch-32);
		}
		if (ch >= 'A' && ch <= 'Z') {
//			ch = ch + 32;
			printf(".%c", ch+32);
		}
	}
	system("pause");
	return 0;
}