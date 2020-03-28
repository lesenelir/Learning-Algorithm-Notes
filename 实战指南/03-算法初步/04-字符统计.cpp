#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

B1042 字符统计 P135

*/
const int maxn = 1010;
char str[maxn];
int hashTable[30] = {0}; // 记录小写字母出现的次数


int main(int argc, char *argv[]) {
	while (gets(str) != NULL) {
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				hashTable[str[i] - 'a']++;
			} else if (str[i] >= 'A' && str[i] <= 'Z') {
				hashTable[str[i] - 'A']++;
			} 
		}
		int k = 0;
		for (int i = 1; i < 30; i++) {
			if (hashTable[i] > hashTable[k]) {
				k = i;
			}
		}
		printf("%c %d\n", 'a' + k, hashTable[k]);
	}
}