#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	char str[1000];
	while (gets(str) != NULL) {
		int len = strlen(str);
		reverse(str, str+len);
		puts(str);
	}
}