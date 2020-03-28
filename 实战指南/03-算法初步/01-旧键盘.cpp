#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

B1029 旧键盘 P128
散列

备注：
对于两个数组找不同或者相同的元素时，可以用一个散列哈希数组表示某一个数组的元素是否输出过

*/

int main(int argc, char *argv[]) {
	char str1[100], str2[100];
	bool hashTable[128] = {false};
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++) { // 枚举第一个字符串的每个字符
		int j;
		char c1, c2;
		for (j = 0; j < len2; j++) {
			c1 = str1[i];
			c2 = str2[j];
			if (c1 >= 'a' && c1 <= 'z') c1 = c1 - 32;
			if (c2 >= 'a' && c2 <= 'z') c2 = c2 - 32;
			if (c1 == c2) break;
		}
		if (j == len2 && hashTable[c1] == false) {
			printf("%c", c1);
			hashTable[c1] = true;
		}
		
	}
		
}