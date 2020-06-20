#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	char s[1000];
	char c;
	while (scanf("%s %c", s, &c) != EOF) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] != c) {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
}