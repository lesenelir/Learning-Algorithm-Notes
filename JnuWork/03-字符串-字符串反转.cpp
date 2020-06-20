#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char str[1000];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		reverse(str, str+len);
		puts(str);
	}
}