#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10001;
char str[maxn];

int main() {
	while (gets(str) != NULL) {
		int len = strlen(str);
		int count = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] != ' ' && str[i] != '\n') {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}