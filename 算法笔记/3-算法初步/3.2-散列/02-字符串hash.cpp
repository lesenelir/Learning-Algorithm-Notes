#include <iostream>
#include <cstdio>
using namespace std;

/*

字符串hash是指，将一个字符串S映射为一个整数，使该整数尽可能的唯一表示字符串S
问题：
给出n个字符串（恰好由三位大写字母组成），再给出m个查询字符串，问每个查询字符串在n个字符串中出现次数


*/

const int maxn = 1010;
char S[maxn], temp[maxn];
int hashTable[26*26*26 + 10];

int hashFunc(char S[], int len) {
	int id = 0, product = 1;
	for (int i = 0; i < len; i++) { // 二十六进制转换为十进制
		id = id + (S[i] - 'A') * product;
		product = product * 26;
	}
	return id;
}

int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s", S);
			int id = hashFunc(S[i], 3); // 字符串S[i]转换为整数
			hashTable[id]++; // 该字符串出现的次数加1
		}
		for (int i = 0; i < m; i++) {
			scanf("%s", temp);
			int id = hashFunc(temp, 3);
			printf("%d\n", hashTable[id]);
		}		
	}
}