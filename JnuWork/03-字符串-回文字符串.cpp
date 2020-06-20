#include <iostream>
#include <cstring>
using namespace std;

bool isCircle(char str[]) {
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++) {
		if (str[i] != str[n-i-1]) {
			return false;
		}
	}
	return true;
}


int main(int argc, char *argv[]) {
	char str[1000];
	while (gets(str) != NULL) {
		bool flag = isCircle(str);
		if (flag == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}	
}