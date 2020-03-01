#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*

输入字符串S1和字符串S2，计算S1 - S2最终得到的结果

输入：
They are students.
aeiou
输出：
Thy r stdnts.

*/

const int maxn = 1010;

int main(int argc, char *argv[]) {
	char S1[maxn], S2[maxn];
	while (gets(S1) != NULL ) {
		gets(S2);
		int len1 = strlen(S1), len2 = strlen(S2);
		int hashTable[maxn] = {0};
		for (int i = 0; i < len1; i++) { // 出现过的字符标记为1
			hashTable[S1[i]] = 1;
		}
		for (int i = 0; i < len2; i++) { // 需要去掉的字符标记为0
			hashTable[S2[i]] = 0;
		}
		
		for (int i = 0; i < len1; i++) {
			if (hashTable[S1[i]] == 1) {
				printf("%c", S1[i]);			
			}
		}
		printf("\n");
	}
	
}