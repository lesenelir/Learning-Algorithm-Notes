#include <iostream>
#include <cstdio>
using namespace std;

/*

特殊乘法（清华大学）

*/


int main(int argc, char *argv[]) {
	char s1[20], s2[20];
	while (scanf("%s %s", s1, s2) != EOF) {
		int len1 = strlen(s1), len2 = strlen(s2);		
		int res = 0;
			for (int i = 0; i < len1; i++) {
				for (int j = 0; j < len2; j++) {
					res += (s1[i] - '0') * (s2[j] - '0');
				}
			}
			printf("%d\n", res);
		}
}