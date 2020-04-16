#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/*

小写转成大写

*/
const int maxn = 101;

int main() {
	char str[maxn];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				str[i] = str[i] - 'a' + 'A';
			}
		}
		for (int i = 0; i < len; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	
	return 0;
}