#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char str[1000];
	while (scanf("%s", str) != EOF) {
		int n = strlen(str);
		for (int i = 0; i < n / 2; i++) {
			char temp = str[i];
			str[i] = str[n-i-1];
			str[n-i-1] = temp;
		}
		puts(str);
	}
}