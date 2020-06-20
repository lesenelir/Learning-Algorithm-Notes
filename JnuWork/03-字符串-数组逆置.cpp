#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	char str[100];
	while (gets(str) != NULL) {
		int len = strlen(str);
		reverse(str, str+len);
		for (int i = 0; i < len; i++) {
			printf("%c", str[i]);
		}
	}
}